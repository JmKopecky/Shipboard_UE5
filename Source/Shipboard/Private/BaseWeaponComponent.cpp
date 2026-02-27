#include "BaseWeaponComponent.h"

UBaseWeaponComponent::UBaseWeaponComponent() {
	PrimaryComponentTick.bCanEverTick = true;

	//handle weapon appearance
	weaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Weapon Mesh");
	weaponMeshComponent->SetupAttachment(this);
	
	if (weaponMesh) {
		weaponMeshComponent->SetStaticMesh(weaponMesh);
	}
	if (weaponMaterial) {
		weaponMeshComponent->SetMaterial(0, weaponMaterial);
	}
}

/**
 * Fires this weapon at the target location, triggering the cooldown.
 * @param target The location we are firing our weapon towards.
 */
void UBaseWeaponComponent::fireWeapon(FVector target) {
	if (!canFire()) {
		return;
	}
	
	currentCooldown = COOLDOWN;
}

/**
 * Determines if this weapon is permitted to fire again yet.
 * @return True if the cooldown has expired.
 */
bool UBaseWeaponComponent::canFire() {
	return currentCooldown <= 0.0f;
}

// Called when the game starts
void UBaseWeaponComponent::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void UBaseWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//decrease current cooldown until it reaches 0.
	if (!canFire()) {
		currentCooldown = std::max(0.0f, currentCooldown - DeltaTime);
	}
}

