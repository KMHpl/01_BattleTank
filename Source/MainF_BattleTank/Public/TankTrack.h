// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class MAINF_BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category = "Input")
	void SetForwardThrottle(float Throttle);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetBacwardsThrottle(float Throttle);
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxSpeed = 40000000;
	
};
