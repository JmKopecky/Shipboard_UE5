#include "BaseShip.h"

#include "Engine/Engine.h"

ABaseShip::ABaseShip() {
	PrimaryActorTick.bCanEverTick = true;
	
	//handle the main mesh (body)
	bodyComponent = CreateDefaultSubobject<UStaticMeshComponent>("Ship Body");
	SetRootComponent(bodyComponent);
	
	bodyComponent->SetMobility(EComponentMobility::Movable);
	bodyComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	bodyComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	if (staticMeshComponent) {
		bodyComponent->SetStaticMesh(staticMeshComponent);
	}
	if (materialInterfaceComponent) {
		bodyComponent->SetMaterial(0, materialInterfaceComponent);
	}
}

/**
 * Move this ship forward according to the summed speed of the engines.
 * @param deltaTime The time passed since the last frame.
 */
void ABaseShip::moveBySpeed(float deltaTime) {
	if (engines.Num() == 0) {
		return;
	}
	
	int sum {0};
	for (UShipEngineComponent* engine : engines) {
		if (IsValid(engine)) {
			sum += engine->GetSpeed();
		}
	}
	
	double offset {sum * deltaTime * currentSpeedPercent};
	FVector change = GetActorForwardVector() * offset;
	SetActorLocation(GetActorLocation() + change, true);
}

/**
 * Increase or decrease the current speed percentage by acceleration.
 * Side Effect: currentSpeedPercentage remains between 0 and 1
 * @param acceleration A float that should be between -1 and 1 
 * representing what to add to our speed percentage.
 */
void ABaseShip::accelerateSpeed(float acceleration) {
	currentSpeedPercent = std::min(currentSpeedPercent + acceleration, MAX_SPEED_PERCENT);
	currentSpeedPercent = std::max(currentSpeedPercent, MIN_SPEED_PERCENT);
}

// Called when the game starts or when spawned
void ABaseShip::BeginPlay() {
	Super::BeginPlay();
	//populate all engine components
	GetComponents(UShipEngineComponent::StaticClass(), engines);
}

// Called every frame
void ABaseShip::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	//accelerate forward
	moveBySpeed(DeltaTime);
}

// Called to bind functionality to input
void ABaseShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

