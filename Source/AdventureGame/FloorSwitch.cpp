// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSwitch.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MainCharacter.h"	


// Sets default values
AFloorSwitch::AFloorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Collision

	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	RootComponent = TriggerSphere;

	TriggerSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//onlyoverlap events no physics
	TriggerSphere->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);//the type of object that this is considered
	TriggerSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);//set collision to ignore all channels no response
	TriggerSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);//how would this collision responde to a specific channel
	TriggerSphere->SetSphereRadius(55.f);//Set default size of the sphere in radius

	TriggerSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereBeginOvelap);
	TriggerSphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnSphereEndOvelap);

	FloorSwitch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor Switch"));
	FloorSwitch->SetupAttachment(GetRootComponent());

	DoorSwitch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Switch"));
	DoorSwitch->SetupAttachment(GetRootComponent());

	//Components

	InitialDoorLocation = FVector();
	InitialSwitchLocation = FVector();


	//Control

	bCharStillOnSwitch = false;
	DelayDoor = 2.f;


}

// Called when the game starts or when spawned
void AFloorSwitch::BeginPlay()
{
	Super::BeginPlay();
	
	InitialDoorLocation = DoorSwitch->GetComponentLocation();
	InitialSwitchLocation = FloorSwitch->GetComponentLocation();
}

void AFloorSwitch::CloseDoor()
{
	//Only close the door when character isn't over the switch platform
	if (!bCharStillOnSwitch)
	{
		//Blueprint Implementable Events
		LowerDoor();
		RaiseFloor();
	}
}

// Called every frame
void AFloorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AFloorSwitch::OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, "Overlap");

	bCharStillOnSwitch = true;

	//Blueprint Implementable Events
	RaiseDoor();
	LowerFloor();
}

void AFloorSwitch::OnSphereEndOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, "End Overlap");

	bCharStillOnSwitch = false;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFloorSwitch::CloseDoor, DelayDoor);
}

void AFloorSwitch::SteppedInFloorSwitch(float value)
{
	FVector NewLocation = InitialSwitchLocation;
	NewLocation.Z += value;

	FloorSwitch->SetWorldLocation(NewLocation);
}

void AFloorSwitch::UpdateDoorSwitch(float value)
{
	FVector NewLocation = InitialDoorLocation;
	NewLocation.Z += value;

	DoorSwitch->SetWorldLocation(NewLocation);
}


