#include "ShipEngineComponent.h"

UShipEngineComponent::UShipEngineComponent() {
	PrimaryComponentTick.bCanEverTick = true;

	engineMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Engine Mesh");
	engineMeshComponent->SetupAttachment(this);
	
	if (engineMesh) {
		engineMeshComponent->SetStaticMesh(engineMesh);
	}
	if (engineMaterial) {
		engineMeshComponent->SetMaterial(0, engineMaterial);
	}
}

// Called when the game starts
void UShipEngineComponent::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void UShipEngineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

/**
 * Determines how much speed this engine contributes to the ship's movement.
 * @return The speed contributed by this engine.
 */
int UShipEngineComponent::GetSpeed() {
	return speed;
}
