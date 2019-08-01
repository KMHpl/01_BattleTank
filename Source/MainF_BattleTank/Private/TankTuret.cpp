// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTuret.h"
#include "Engine/World.h"
#include "math.h"


void UTankTuret::Rotate(float RelativeSpeed) 
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegPerSec * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}


