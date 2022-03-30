// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IRechargable.h"
#include "GunSystem/Weapon.h"
#include "Interfaces/IAimingable.h"
#include "Modules/Clip.h"
#include "FirearmWeapon.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GUNSYSTEM_API AFirearmWeapon : public AWeapon, public IRechargable, public  IAimingable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Modules")
	UWeaponModule* AimingModule;
	
	UPROPERTY(BlueprintReadOnly, Category = "Modules")
	UClip* Ammo;
	
	virtual void AttackTick_Implementation() override;

	virtual void Recharge_Implementation() override;

	virtual void Zoom_Implementation() override;
	virtual void UnZoom_Implementation() override;
	
protected:
	virtual void ImplementWeaponInfo_Implementation(UWeaponInfo* NewWeaponInfo) override;
	
public:
	UFUNCTION(BlueprintNativeEvent)
	void Shoot(const TArray<AActor*>& HitResult);

	virtual void Shoot_Implementation(const TArray<AActor*>& HitResult);

	UFUNCTION(BlueprintNativeEvent)
	void OnClipEmpty();

	virtual void OnClipEmpty_Implementation();
};
