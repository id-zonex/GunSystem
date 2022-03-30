// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Modules/ShootingComponent.h"
#include "Weapon.generated.h"

class UWeaponInfo;

UCLASS()
class GUNSYSTEM_API AWeapon : public AActor
{
	GENERATED_BODY()

	FTimerHandle AttackingTimer;
	
public:	
	AWeapon();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Attributes)
	UWeaponInfo* WeaponInfo;

	UPROPERTY(BlueprintReadWrite, Category = Modules)
	UShootingComponent* ShootingComponent;

public:	
	virtual void Tick(float DeltaTime) override;

	//// Blueprint events ////

	// Weapon visibility
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Select();
	void Select_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Unselect();
	void Unselect_Implementation();

	// Attack
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StartAttack();
	void virtual StartAttack_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AttackTick();
	void virtual AttackTick_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void StopAttack();
	void virtual StopAttack_Implementation();

	UFUNCTION(BlueprintCallable)
	void UpdateWeaponInfo(UWeaponInfo* NewWeaponInfo);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ImplementWeaponInfo(UWeaponInfo* NewWeaponInfo);
	
	virtual void ImplementWeaponInfo_Implementation(UWeaponInfo* NewWeaponInfo);
	
private:
	void SetActive(bool Active);
};
