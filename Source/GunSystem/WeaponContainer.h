// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.h"
#include "WeaponContainer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSelectWeaponDelegate, AWeapon*, SelectedWeapon, AWeapon*, PreviousWeapon);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddWeaponDelegate, AWeapon*, Weapon);

UCLASS(Blueprintable)
class GUNSYSTEM_API UWeaponContainer : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponContainer();

	UPROPERTY(BlueprintAssignable)
	FSelectWeaponDelegate OnSelectWeapon;

	UPROPERTY(BlueprintAssignable)
	FAddWeaponDelegate OnAddWeapon;

	UPROPERTY(BlueprintReadOnly)
	AWeapon* CurrentWeapon;

	UPROPERTY(BlueprintReadOnly)
	int CurrentWeaponIndex;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int MaxWeaponCount = 4;

protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<AWeapon*> Weapons;

protected:
	virtual void BeginPlay() override;

	AWeapon* SelectWeapon(int WeaponIndex);

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddWeapon(AWeapon* Weapon);

	UFUNCTION(BlueprintCallable)
	AWeapon* SwitchWeapon(int SwitchDelta);
};
