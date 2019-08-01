// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetForwardThrottle(float Throttle)
{
	//UE_LOG(LogTemp, Warning, TEXT("Moves"));

	auto ForceApplied = GetForwardVector()* Throttle * TrackMaxSpeed;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::SetBacwardsThrottle(float Throttle)
{
	//UE_LOG(LogTemp, Warning, TEXT("Moves"));

	auto ForceApplied = -(GetForwardVector()* Throttle * TrackMaxSpeed);
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
	