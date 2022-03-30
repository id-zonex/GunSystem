// Copyright Epic Games, Inc. All Rights Reserved.

#include "GunSystemGameMode.h"
#include "GunSystemHUD.h"
#include "GunSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGunSystemGameMode::AGunSystemGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGunSystemHUD::StaticClass();
}
