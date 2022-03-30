#include "WeaponContainer.h"

UWeaponContainer::UWeaponContainer()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponContainer::BeginPlay()
{
	Super::BeginPlay();	
}

void UWeaponContainer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeaponContainer::AddWeapon(AWeapon* Weapon)
{
	if (Weapons.Num() > MaxWeaponCount)
		return;

	Weapons.Add(Weapon);

	OnAddWeapon.Broadcast(Weapon);

	Weapon->Unselect();
}

AWeapon* UWeaponContainer::SwitchWeapon(int SwitchDelta)
{
	if (SwitchDelta == 0)
		return CurrentWeapon;

	int NewIndex = CurrentWeaponIndex + SwitchDelta;

	if (NewIndex >= Weapons.Num())
		return SelectWeapon(0);
	else if (NewIndex < 0)
		return SelectWeapon(Weapons.Num());

	return SelectWeapon(NewIndex);
}

AWeapon* UWeaponContainer::SelectWeapon(int WeaponIndex)
{
	AWeapon* PreviousWeapon = CurrentWeapon;

	if (Weapons.Num() == 0)
		return nullptr;

	if (CurrentWeapon != nullptr)
		CurrentWeapon->Unselect();

	CurrentWeaponIndex = FMath::Clamp(WeaponIndex, 0, Weapons.Num() - 1);
	CurrentWeapon = Weapons[CurrentWeaponIndex];

	CurrentWeapon->Select();

	OnSelectWeapon.Broadcast(CurrentWeapon, PreviousWeapon);

	return CurrentWeapon;
}

