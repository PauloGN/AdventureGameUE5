// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */

class APawn;


UCLASS()
class ADVENTUREGAME_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UMainAnimInstance();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimStats | Movement")
	float MovementSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimStats | Movement")
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AnimStats | Movement")
	APawn* PawnREF;


public:

	//**
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = "AnimStats")
	void UpdateAnimationProperties();

};
