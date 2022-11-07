// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	PlatformMesh->SetupAttachment(GetRootComponent());
	PlatformSpeed = FVector(0.f, 0.f, 100.f);
	StartLocation = GetActorLocation();
	DistanceTravelled = 0.f;
	DistanceToMove = 200.f;
	RotationVelocity = FRotator(0.f, 1.f, 0.f);

	bMoving = false;
	MovePauseDelayTime = 2.f;

	bRotatePlatform = false;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(PlatformTimerHandle, this, &ThisClass::ToggleDirection, MovePauseDelayTime);

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMoving)
	{
		Move(DeltaTime);
	}

	if (bRotatePlatform)
	{
		Rotate(DeltaTime);
	}
}

void AMovingPlatform::Move(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += PlatformSpeed * DeltaTime;
	DistanceTravelled = StaticCast<float>(FVector::Dist(StartLocation, CurrentLocation));

	if (DistanceTravelled > DistanceToMove)
	{
		ToggleDirection();
		FVector NormalMoveDirection = PlatformSpeed.GetSafeNormal();
		DistanceTravelled = 0;
		StartLocation = StartLocation + NormalMoveDirection * DistanceToMove;
		SetActorLocation(StartLocation);
		PlatformSpeed *= -1;
		GetWorldTimerManager().SetTimer(PlatformTimerHandle, this, &ThisClass::ToggleDirection, MovePauseDelayTime);
	}
	SetActorLocation(CurrentLocation);
}

void AMovingPlatform::Rotate(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

void AMovingPlatform::ToggleDirection()
{
	bMoving = !bMoving;
}

