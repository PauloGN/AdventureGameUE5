// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/Boxcomponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Enemy.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawning Box"));


}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetSpawnPoint()
{
	const FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
	const FVector BoxOrigin = SpawningBox->GetComponentLocation();

	const FVector Point = UKismetMathLibrary::RandomPointInBoundingBox(BoxOrigin, BoxExtent);

	return Point;
}

//Hybrids called blueprint native events / have some native C++ code functionality and they also have some blueprint functionality.
void ASpawnVolume::SpawnEnemy_Implementation(UClass* OBJToSpawn, const FVector& SpawnLocation)
{
	if (OBJToSpawn)
	{
		UWorld* World = GetWorld();
		FActorSpawnParameters SpawnParams;

		if (World)
		{
			AEnemy* EnemySpawned =	World->SpawnActor<AEnemy>(OBJToSpawn, SpawnLocation, FRotator().ZeroRotator, SpawnParams);
		}
	}
}

