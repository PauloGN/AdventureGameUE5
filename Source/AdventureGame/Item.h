// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class UParticleSystem;
class USoundCue;

UCLASS()
class ADVENTUREGAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	//Volume to detect contact
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Collision")
	USphereComponent* CollisionVolume;

	//Base Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Mesh")
	UStaticMeshComponent* Mesh;


	/** Particle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Particles")
	UParticleSystemComponent* IdleParticlesComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Particles")
	UParticleSystem* OverlapParticles;

	/** Sounds */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Sounds")
	USoundCue* OverlapSound;

	/** Functionalities */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Functionalities")
	bool bRotate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Functionalities")
	FRotator RotationSpeed;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** OVERLAP */
	UFUNCTION()
	virtual void OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	void RotateItem(float DeltaTime);

};
