// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FuncTestRenderingComponent.h"
#include "WeaponModule.h"
#include "ShootingComponent.generated.h"


UCLASS(Abstract, Blueprintable)
class GUNSYSTEM_API UShootingComponent : public UWeaponModule
{
	GENERATED_BODY()

public:	
	UShootingComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	virtual void BeginPlay() override;
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Initialize(USceneComponent* Pivot);

	virtual void Initialize_Implementation(USceneComponent* Pivot);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<AActor*> Attack();

	TArray<AActor*> virtual Attack_Implementation();
	
protected:
	UPROPERTY(BlueprintReadWrite, Category="Attack")
	USceneComponent* AttackPivot;
};
