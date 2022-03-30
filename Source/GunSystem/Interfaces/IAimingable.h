// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IAimingable.generated.h"


UINTERFACE(Blueprintable, BlueprintType)
class GUNSYSTEM_API UAimingable : public UInterface
{
	GENERATED_BODY()
};

class IAimingable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Zoom();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UnZoom();
};
