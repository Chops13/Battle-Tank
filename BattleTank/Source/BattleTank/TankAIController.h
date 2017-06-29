// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATankAIController();

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
protected:

	FVector GetPlayerTankLocation();

	//How close can the AI Tank approach until stop
	float AcceptanceRadius = 3000;

	UTankAimingComponent* AimingComponent = nullptr;
};
