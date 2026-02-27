// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeaponComponent.h"

// Sets default values for this component's properties
UBaseWeaponComponent::UBaseWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	weaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Weapon Mesh");
	weaponMeshComponent->SetupAttachment(this);
	
	if (weaponMesh) {
		weaponMeshComponent->SetStaticMesh(weaponMesh);
	}
	if (weaponMaterial) {
		weaponMeshComponent->SetMaterial(0, weaponMaterial);
	}
}

void UBaseWeaponComponent::fireWeapon(FVector target) {
	if (!canFire()) {
		return;
	}
	
	currentCooldown = COOLDOWN;
}

bool UBaseWeaponComponent::canFire() {
	return currentCooldown <= 0.0f;
}

// Called when the game starts
void UBaseWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBaseWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!canFire()) {
		currentCooldown = std::max(0.0f, currentCooldown - DeltaTime);
	}
}

