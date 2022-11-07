// Fill out your copyright notice in the Description page of Project Settings.


#include "Hazard.h"

AHazard::AHazard()
{
}

void AHazard::OnSphereBeginOvelap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	Super::OnSphereBeginOvelap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, FromSweep, SweepResult);

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Hazard Overlapped"));

}

void AHazard::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Hazard EndOverlapped"));

}
