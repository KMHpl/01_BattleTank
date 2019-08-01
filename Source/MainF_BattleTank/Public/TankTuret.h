// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTuret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class MAINF_BATTLETANK_API UTankTuret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegPerSec = 15;
		
};
