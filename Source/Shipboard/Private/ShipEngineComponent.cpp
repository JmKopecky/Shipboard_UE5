// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipEngineComponent.h"

// Sets default values for this component's properties
UShipEngineComponent::UShipEngineComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
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
void UShipEngineComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UShipEngineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UShipEngineComponent::GetSpeed() {
	return speed;
}
