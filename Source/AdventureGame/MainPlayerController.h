// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */

class UUserWidget;

UCLASS()
class ADVENTUREGAME_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	//Referente to the UMG asset in the editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "States | HUD")
	TSubclassOf<UUserWidget> HUDOverlayAsset;

	//Variable to hold the wiget after create it
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "States | HUD")
	UUserWidget* HUDOverlay;

protected:

	virtual void BeginPlay()override;


};
