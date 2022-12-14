// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"


class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class ADVENTUREGAME_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

	//COLISSION
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Switch")
	USphereComponent* TriggerSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Switch")
	UStaticMeshComponent* FloorSwitch;//the overllaped obj to trigger the action

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Switch")
	UStaticMeshComponent* DoorSwitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Switch")
	FVector InitialDoorLocation;//Initial location for the door

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | Switch")
	FVector InitialSwitchLocation;//Initial Location for the floor switch

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | Switch")
	float DelayDoor;

	FTimerHandle TimerHandle;

	void CloseDoor();

	bool bCharStillOnSwitch;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Collision

	UFUNCTION()
	void OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereEndOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Called in Blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = "States | Door")
	void RaiseDoor();
	UFUNCTION(BlueprintImplementableEvent, Category = "States | Door")
	void LowerDoor();

	// Called in Blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = "States | Door")
	void RaiseFloor();
	UFUNCTION(BlueprintImplementableEvent, Category = "States | Door")
	void LowerFloor();

	UFUNCTION(BlueprintCallable, Category = "States | Switch" )
	void SteppedInFloorSwitch(float value);

	UFUNCTION(BlueprintCallable, Category = "States | Switch")
	void UpdateDoorSwitch(float value);

};
