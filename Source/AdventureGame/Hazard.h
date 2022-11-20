// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Hazard.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREGAME_API AHazard : public AItem
{
	GENERATED_BODY()

public:

	AHazard();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Damage")
	float Damage;

public:

	/** OVERLAP */

	virtual void OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)override;

	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)override;
	
};
