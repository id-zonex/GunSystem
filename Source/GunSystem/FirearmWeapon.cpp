// Fill out your copyright notice in the Description page of Project Settings.


#include "GunSystem/FirearmWeapon.h"
#include "WeaponInfo.h"


void AFirearmWeapon::ImplementWeaponInfo_Implementation(UWeaponInfo* NewWeaponInfo)
{
	Super::ImplementWeaponInfo_Implementation(NewWeaponInfo);
	
	Ammo = DuplicateObject(NewWeaponInfo->Ammo, this);

	AimingModule = DuplicateObject(NewWeaponInfo->AimingModule, this);
}

void AFirearmWeapon::AttackTick_Implementation()
{
	Super::AttackTick_Implementation();
	
	if(Ammo->CommitAttack() == false)
	{
		OnClipEmpty();
		return;
	}
	
	Shoot(ShootingComponent->Attack());
}

void AFirearmWeapon::Recharge_Implementation()
{
	IRechargable::Recharge_Implementation();

	Ammo->Reload();
}

void AFirearmWeapon::Zoom_Implementation()
{
	if(AimingModule)
		IAimingable::Execute_Zoom(AimingModule);
}

void AFirearmWeapon::UnZoom_Implementation()
{
	if(AimingModule)
		IAimingable::Execute_UnZoom(AimingModule);
}

void AFirearmWeapon::Shoot_Implementation(const TArray<AActor*>& HitResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Paw!!!"));
}

void AFirearmWeapon::OnClipEmpty_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("AmmoEmpty!!!"));
}
