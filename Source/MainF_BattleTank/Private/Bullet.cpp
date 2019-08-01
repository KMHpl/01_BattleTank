// Fill out your copyright notice in the Description page of Project Settings.
#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values

ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("BulletMovement"));
	BulletMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABullet::LunchBullet(float Speed)
{
	UE_LOG(LogTemp, Warning, TEXT("Fire!"));
	//BulletMovement->SetComponentTickEnabled(true);
	//BulletMovement->SetVelocityInLocalSpace(FVector::ForwardVector*Speed);
	//Velocity = 
		
		//UpdatedComponent->GetComponentToWorld().TransformVectorNoScale(NewVelocity);
	//BulletMovement->Activate();
}

