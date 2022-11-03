// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingPlatform.h"
#include "TimerManager.h"

// Sets default values
AFloatingPlatform::AFloatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = Platform;


	//Vectors

	StartPoint = FVector();
	//EndPoint Is relative to the actor root position
	EndPoint = FVector(0.f, 0.f, 25.f);


	InterpSpeed = 1.f;
	InterpDelayTime = 2.f;//how much it should waite till toggle the platform direction
	bInterping = false;
	DistanceToTravel = (StartPoint - EndPoint).Size();

}

// Called when the game starts or when spawned
void AFloatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	//Calculating the distance to be travelled
	DistanceToTravel = (StartPoint - EndPoint).Size();

	//Set the origin point
	StartPoint = GetActorLocation();

	//calculation the end point for world position
	EndPoint += StartPoint;

	//tell the platform when to move from side to side
	GetWorldTimerManager().SetTimer(InterpTimerHandle, this, &ThisClass::ToggleInperting, InterpDelayTime);
}

// Called every frame
void AFloatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInterping)
	{
		//Gets the actor current location each frame
		FVector CurrentLocation = GetActorLocation();

		//Future point to go to each frame/delta second
		FVector Interp = FMath::VInterpTo(CurrentLocation, EndPoint, DeltaTime, InterpSpeed);

		SetActorLocation(Interp);

		const float DistanceTravelled = (GetActorLocation() - StartPoint).Size();

		if (DistanceToTravel - DistanceTravelled <= 0.1f)
		{
			ToggleInperting();
			GetWorldTimerManager().SetTimer(InterpTimerHandle, this, &ThisClass::ToggleInperting, InterpDelayTime);
			SwapVectors(StartPoint, EndPoint);
		}
	}
}

void AFloatingPlatform::ToggleInperting()
{
	bInterping = !bInterping;
}

void AFloatingPlatform::SwapVectors(FVector& v1, FVector& v2)
{
	FVector TempV = v1;
	v1 = v2;
	v2 = TempV;
}

