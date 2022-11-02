// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;
class AEnemy;

UCLASS()
class ADVENTUREGAME_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "States | Spawning")
	TSubclassOf<AEnemy> EnemyToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "States | Spawning")
	FVector GetSpawnPoint();

	//Hybrids called blueprint native events / have some native C++ code functionality and they also have some blueprint functionality.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "States | Spawning")
	void SpawnEnemy(UClass* OBJToSpawn,const FVector& SpawnLocation);

};
