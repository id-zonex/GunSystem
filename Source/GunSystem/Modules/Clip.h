#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GunSystem/ProjectileBase.h"
#include "Clip.generated.h"

UCLASS(DefaultToInstanced, EditInlineNew)
class GUNSYSTEM_API UClip : public UObject
{
	GENERATED_BODY()

public:
	UClip();
	
	UFUNCTION(BlueprintCallable)
	bool CommitAttack();

	UFUNCTION(BlueprintCallable)
	void Reload();

	UFUNCTION(BlueprintCallable)
	TSubclassOf<AProjectileBase> GetBulletClass() const { return BulletClass; };
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AProjectileBase> BulletClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 MaxAmmo;

	UPROPERTY(BlueprintReadOnly)
	int32 CurrentAmmo;
};
