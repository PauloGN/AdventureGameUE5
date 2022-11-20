// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ADVENTUREGAME_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	//Basic Character 

	//*** Positioning the camera behind the player
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerStats | Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	//*** Keeps attached to the camera boom, following the player throughout the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerStats | Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	//MOVEMENT

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats | Movement")
	float BaseKeyBoardTurnRate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats | Movement")
	float BaseKeyBoardLookUpRate;

	/*** Player Stats*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	float Health;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	float Stamina;

	//Max points to up level
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats")
	float MaxSoulPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	float SoulPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	int32 Level;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//MOVEMENT

	void MoveFoward(const float value);// Keyboard up and down
	void MoveRight(const float value);//keyboard side to side

	void TurnAtRate(const float rate);
	void LookUpRate(const float rate);

	UFUNCTION(BlueprintCallable, Category = "States | EXP")
	void AddExp(const float value);

	UFUNCTION(BlueprintCallable, Category = "States | Dmg")
	void DecrementHealth(const float amount);

	UFUNCTION(BlueprintCallable, Category = "States | Dmg")
	void Die();

};
