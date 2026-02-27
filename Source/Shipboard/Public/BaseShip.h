// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShipEngineComponent.h"
#include "GameFramework/Pawn.h"
#include "BaseShip.generated.h"

UCLASS()
class SHIPBOARD_API ABaseShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseShip();
	
	UFUNCTION(BlueprintCallable)
	//Add or subtract to the current speed percentage of this ship.
	//The final value of currentSpeedPercent is still bounded between 0 and 1.
	void accelerateSpeed(float acceleration);

protected:
	//main body of the ship
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Visual")
	UStaticMeshComponent* bodyComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	UStaticMesh* staticMeshComponent = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	UMaterialInterface* materialInterfaceComponent = nullptr;
	
	//components for various ship components
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ship|Engines")
	TArray<UShipEngineComponent*> engines;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ship|Weapons")
	TArray<UBaseWeaponComponent*> weapons;
	
	//speed control
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ship|Engines")
	//should be a number between 0 and 1.
	float currentSpeedPercent = MIN_SPEED_PERCENT;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void moveBySpeed(float deltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	const float MAX_SPEED_PERCENT = 1.0f;
	const float MIN_SPEED_PERCENT = 0.0f;
};
