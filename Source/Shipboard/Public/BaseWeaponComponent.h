#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BaseWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHIPBOARD_API UBaseWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UBaseWeaponComponent();
	
	UFUNCTION(BlueprintCallable)
	bool canFire();
	
	UFUNCTION(BlueprintCallable)
	void fireWeapon(FVector target);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	//defines weapon appearance
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Visual")
	UStaticMeshComponent* weaponMeshComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	UStaticMesh* weaponMesh = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual")
	UMaterialInterface* weaponMaterial = nullptr;
	
	//variables related to firing cooldowns
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ship|Weapons")
	float COOLDOWN;
	
	float currentCooldown = 0.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
