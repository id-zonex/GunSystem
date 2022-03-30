// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/Clip.h"
#include "Engine/DataAsset.h"
#include "Modules/ShootingComponent.h"		
#include "WeaponType.h"
#include "AttackType.h"
#include "WeaponInfo.generated.h"

class AWeapon;

UCLASS(meta=(ShowWorldContextPin))
class GUNSYSTEM_API UWeaponInfo : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// �������� ������
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Description", meta = (DisplayPriority = 1))
	FText Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Description", meta = (DisplayPriority = 1))
	FText Description;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Description", meta = (DisplayPriority = 1))
	EWeaponType Type;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Description", meta = (DisplayPriority = 1))
	UTexture2D* Icon;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes", meta = (DisplayPriority = 1))
	float Damage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes", meta = (DisplayPriority = 1))
	float ShootingSpeed;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Gameplay", meta = (DisplayPriority = 1))
	EAttackType AttackType;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Gameplay", meta = (DisplayPriority = 1))
	TSubclassOf<AWeapon> ViewWeapon;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Gameplay|Modules|Attack", meta = (DisplayPriority = 1))
	UShootingComponent* ShootingModule;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Gameplay|Modules", meta = (DisplayPriority = 1))
	UWeaponModule* MiddleButtonModule;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Gameplay|Modules", meta = (DisplayPriority = 1))
	UWeaponModule* SecondModule;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced, Category = "Gameplay|Attack", meta = (DisplayPriority = 1))
	UClip* Ammo;

public:
	UFUNCTION(BlueprintCallable)
	AWeapon* InstantiateWeapon(AActor* Outer);

	void virtual ImplementWeaponInfo(AWeapon* Weapon);
};
