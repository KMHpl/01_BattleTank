// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**

 * 
 */
UCLASS()
class MAINF_BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;
private:
	
	
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float) override;
	
	void AimTowardsCrosshair();
private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0;
private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D, FVector&) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
