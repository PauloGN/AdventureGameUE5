// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

class UStaticMeshComponent;

UCLASS()
class ADVENTUREGAME_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "States | Platform")
	UStaticMeshComponent* Platform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "States | Platform")
	FVector StartPoint;

	//EndPoint Is relative to the actor root position
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"), Category = "States | Platform")
	FVector EndPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Platform")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Platform")
	float InterpDelayTime;

	FTimerHandle InterpTimerHandle;
	bool bInterping;

	float DistanceToTravel;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInperting();

	void SwapVectors(FVector& v1, FVector& v2);

};
