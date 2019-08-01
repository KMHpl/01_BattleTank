// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankBarrel.h"
#include "Bullet.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
/*
void ATank::SetTuretReference(UTankTuret* Turet)
{
	TankAimingComponent->SetTuretReference(Turet);
}
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}*/

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	/*TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));*/
}

void ATank::Fire()
{
	bool IsReady = FPlatformTime::Seconds() - LastFireTime > ReloadTimeInSeconds;
	
	//spawn a bullet at the socket location
	if (Barrel && IsReady)
	{
		auto SocketLocation = Barrel->GetSocketLocation(FName("EndOfBarrel"));
		auto SocketRotation = Barrel->GetSocketRotation(FName("EndOfBarrel"));

		auto Bullet = GetWorld()->SpawnActor<ABullet>(BulletBP, SocketLocation, SocketRotation);
		LastFireTime = FPlatformTime::Seconds();
		//Bullet->LunchBullet(LunchSpeed);

	
	}

}


void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input


void ATank::AimAt(FVector HitPosition)
{
	if (!TankAimingComponent) { return; };
	TankAimingComponent->AimAt(HitPosition, LunchSpeed);
}

