// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(Damage); //Just to not compare between floats
	int32 ActualDamage = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth = CurrentHealth - ActualDamage;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	return ActualDamage;
}

float ATank::GetHealthPercentage() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}