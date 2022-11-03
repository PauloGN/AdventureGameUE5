// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class UStaticMeshComponent;

UCLASS()
class ADVENTUREGAME_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "States | Mesh")
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Movement")
	FVector PlatformSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "States | Movement")
	float DistanceTravelled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Movement")
	float DistanceToMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Movement")
	FRotator RotationVelocity;

	FVector StartLocation;

	FTimerHandle PlatformTimerHandle;
	
	bool bMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Movement")
	bool bRotatePlatform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Movement")
	float MovePauseDelayTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	void ToggleDirection();

};
