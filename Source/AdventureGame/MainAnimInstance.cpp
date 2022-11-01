// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"


UMainAnimInstance::UMainAnimInstance():PawnREF(nullptr), MovementSpeed(0.f), bIsInAir(false)
{


}

void UMainAnimInstance::NativeInitializeAnimation()
{
	//Get the reference to the pawn who is the owner of the animation class
	if (PawnREF == nullptr)
	{
		PawnREF = TryGetPawnOwner();
	}

}

void UMainAnimInstance::UpdateAnimationProperties()
{
	//Get the reference to the pawn who is the owner of the animation class
	if (PawnREF == nullptr)
	{
		PawnREF = TryGetPawnOwner();
	}

	if (PawnREF)
	{
		FVector Speed = PawnREF->GetVelocity();
		FVector LateralSpeed(Speed.X, Speed.Y, 0.f);

		MovementSpeed = LateralSpeed.Size();

		bIsInAir = PawnREF->GetMovementComponent()->IsFalling();
	}

}
