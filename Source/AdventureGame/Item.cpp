// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Volume"));
	RootComponent = CollisionVolume;
	//Default radius size
	CollisionVolume->SetSphereRadius(100.f);

	//Base mesh 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Basemesh"));
	Mesh->SetupAttachment(GetRootComponent());

	/** Particles*/

	IdleParticlesComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Idle Particle"));
	IdleParticlesComponent->SetupAttachment(GetRootComponent());


	/** Functionalities*/

	bRotate = false;
	RotationSpeed = FRotator().ZeroRotator;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	//Binding function to the event begin and end overlap
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereBeginOvelap);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Set rotation if you want
	RotateItem(DeltaTime);
}

void AItem::OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Item Overlapped"));

	if (OverlapParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticles, GetActorLocation(), FRotator().ZeroRotator, true);
	}

	if (OverlapSound)
	{
		UGameplayStatics::PlaySound2D(this, OverlapSound);
	}

	Destroy();
}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Item EndOverlaped"));
}

void AItem::RotateItem(float DeltaTime)
{
	if (bRotate)
	{
		FRotator DeltaRotation = GetActorRotation();
		DeltaRotation.Yaw += RotationSpeed.Yaw * DeltaTime;
		DeltaRotation.Roll += RotationSpeed.Roll * DeltaTime;
		DeltaRotation.Pitch += RotationSpeed.Pitch * DeltaTime;
		SetActorRotation(DeltaRotation);
	}
}

