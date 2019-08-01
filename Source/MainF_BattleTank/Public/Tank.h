// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class UTankTuret;
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class ABullet;
UCLASS()
class MAINF_BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	

	virtual void BeginPlay() override;
	// Sets default values for this pawn's properties
	void AimAt(FVector);
	ATank();

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

protected:
	// Called when the game starts or when spawned
	
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
public:	
	// Called to bind functionality to input
	
	
	UPROPERTY(EditAnywhere, Category = "Firing")
		float LunchSpeed = 4000;
	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<ABullet> BulletBP;
	UTankBarrel* Barrel = nullptr;
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
};
