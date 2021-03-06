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
	UPROPERTY(EditAnywhere, Category= Setup)
	float AcceptanceRadius = 8000;

	UTankAimingComponent* AimingComponent = nullptr;

	UFUNCTION()
	void OnPossessedTankDeath();

private:
	void SetPawn(APawn* InPawn) override;
};
