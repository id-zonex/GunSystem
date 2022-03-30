// Fill out your copyright notice in the Description page of Project Settings.


#include "Clip.h"

UClip::UClip()
{
	Reload();
}

bool UClip::CommitAttack()
{
	if(CurrentAmmo < 0)
		return false;

	CurrentAmmo--;

	return true;
}

void UClip::Reload()
{
	CurrentAmmo = MaxAmmo;
}
