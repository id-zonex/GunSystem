#include "Weapon.h"
#include "WeaponInfo.h"
#include "AttackType.h"

AWeapon::AWeapon()
{
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponRoot"));
    
    AttackPivot = CreateDefaultSubobject<USceneComponent>(TEXT("AttackPivot"));

    AttackPivot->SetupAttachment(RootComponent);
    
	PrimaryActorTick.bCanEverTick = true;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

    ImplementWeaponInfo(WeaponInfo);
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Attack events
void AWeapon::StartAttack_Implementation()
{
    if(WeaponInfo->AttackType == EAttackType::Auto)
        GetWorld()->GetTimerManager().SetTimer(AttackingTimer, this, &AWeapon::AttackTick, WeaponInfo->ShootingSpeed, true);

    if (WeaponInfo->AttackType == EAttackType::Single)
        AttackTick();
}

void AWeapon::AttackTick_Implementation()
{
}

void AWeapon::StopAttack_Implementation()
{
    GetWorld()->GetTimerManager().ClearTimer(AttackingTimer);
}

// Second module actions
void AWeapon::ActivateSecondModule_Implementation()
{
}

void AWeapon::DeactivateSecondModule_Implementation()
{
}

// Weapon visibility
void AWeapon::Select_Implementation()
{
    SetActive(true);
}

void AWeapon::Unselect_Implementation()
{
    SetActive(false);
}

// DA WeaponInfo Actions
void AWeapon::UpdateWeaponInfo(UWeaponInfo* NewWeaponInfo)
{
    WeaponInfo = NewWeaponInfo;

    ImplementWeaponInfo(WeaponInfo);
}

void AWeapon::ImplementWeaponInfo_Implementation(UWeaponInfo* NewWeaponInfo)
{
    if(NewWeaponInfo == nullptr)
        return;
    
    if (NewWeaponInfo->ShootingModule != nullptr)
    {
        ShootingComponent = DuplicateObject(NewWeaponInfo->ShootingModule, this);
        ShootingComponent->Initialize(AttackPivot);
    }
}

void AWeapon::SetActive(bool Active)
{
    SetActorEnableCollision(Active);
    SetActorHiddenInGame(!Active);
}