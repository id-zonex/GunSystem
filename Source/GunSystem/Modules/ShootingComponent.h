// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponModule.h"
#include "ShootingComponent.generated.h"


UCLASS(Abstract, Blueprintable)
class GUNSYSTEM_API UShootingComponent : public UWeaponModule
{
	GENERATED_BODY()

public:	
	UShootingComponent();

	USceneComponent* Pivot;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<AActor*> Attack();

	TArray<AActor*> virtual Attack_Implementation();
};
