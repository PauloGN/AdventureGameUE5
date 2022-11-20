// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "MainCharacter.h"

APickup::APickup()
{
}

void APickup::OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOvelap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, FromSweep, SweepResult);

	if (OtherActor)
	{
		AMainCharacter* MainCharREF = Cast<AMainCharacter>(OtherActor);

		if (MainCharREF)
		{
			OnPickupBP(MainCharREF);
		}
		Destroy();
	}
}

void APickup::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Pickup EndOverlapped"));
}

