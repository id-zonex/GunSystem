#pragma once

#include "CoreMinimal.h"
#include "IRechargable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class URechargable : public UInterface
{
	GENERATED_BODY()
};

class IRechargable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Recharge();
};
