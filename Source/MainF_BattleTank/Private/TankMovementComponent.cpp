// Fill out your copyright notice in the Description page of Project Settings.
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrack, UTankTrack* RightTrack)
{
	if (!LeftTrack || !RightTrack) { return; }
	this->LeftTrack = LeftTrack;
	this->RightTrack = RightTrack;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetForwardThrottle(Throw);
	RightTrack->SetForwardThrottle(Throw);
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetForwardThrottle(Throw);
	RightTrack->SetBacwardsThrottle(Throw);
}

void UTankMovementComponent::IntendLeftTurn(float Throw)
{
	RightTrack->SetForwardThrottle(Throw);
	LeftTrack->SetBacwardsThrottle(Throw);
}

void UTankMovementComponent::IntendMoveBackwards(float Throw)
{
	LeftTrack->SetBacwardsThrottle(Throw);
	RightTrack->SetBacwardsThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(RightThrow);
	//UE_LOG(LogTemp,Warning,TEXT("%s is vectoring to %s"), *TankName, *MoveVelocityString)
}




