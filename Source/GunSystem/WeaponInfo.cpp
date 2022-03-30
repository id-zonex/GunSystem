// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponInfo.h"
#include "Weapon.h"

AWeapon* UWeaponInfo::InstantiateWeapon(AActor* Outer)
{
    AWeapon* WeaponInstance = Outer->GetWorld()->SpawnActor<AWeapon>(ViewWeapon);

    WeaponInstance->UpdateWeaponInfo(this);

    return WeaponInstance;
}
