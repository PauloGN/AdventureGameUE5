// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"

APickup::APickup()
{
}

void APickup::OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOvelap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, FromSweep, SweepResult);

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Pickup Overlapped"));

}

void APickup::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Pickup EndOverlapped"));

}

