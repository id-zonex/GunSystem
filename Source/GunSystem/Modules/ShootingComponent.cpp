#include "ShootingComponent.h"


UShootingComponent::UShootingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UShootingComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

TArray<AActor*> UShootingComponent::Attack_Implementation()
{
	return TArray<AActor*>();
}

