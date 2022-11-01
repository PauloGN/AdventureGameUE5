 // Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	//	Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f;//camera attached follows at this distance
	CameraBoom->bUsePawnControlRotation = true;// rotate arm based on controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Fallow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);//attache the camera at the end of the boom
	FollowCamera->bUsePawnControlRotation = false;//let the boom control the rotation

	//	MOVEMENT

	BaseKeyBoardTurnRate = 60.f;
	BaseKeyBoardLookUpRate = 60.f;

	bUseControllerRotationYaw = false;//do not rotate the character based on controller
	
	GetCharacterMovement()->bOrientRotationToMovement = true;//character is going to automatically turn towards the direction that he's physically moving.
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);//Yaw rotation speed rate whent orienting rotation to movement
	GetCharacterMovement()->JumpZVelocity = 700.f;//Jump Height
	GetCharacterMovement()->AirControl = 0.4f;//control direction while in the air
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	//Axis
	PlayerInputComponent->BindAxis("MoveForward", this, &ThisClass::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ThisClass::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ThisClass::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ThisClass::LookUpRate);
	//Action
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this,&ACharacter::StopJumping);




}

void AMainCharacter::MoveFoward(const float value)
{
	if ((Controller != nullptr) && (value != 0.0f))
	{
		//find out witch way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, value);
	}
}

void AMainCharacter::MoveRight(const float value)
{
	if ((Controller != nullptr) && (value != 0.0f))
	{
		//find out witch way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, value);
	}
}

void AMainCharacter::TurnAtRate(const float rate)
{
	UWorld* World = GetWorld();

	if (World && rate != 0.f)
	{
		const float InputRate = rate * World->GetDeltaSeconds() * BaseKeyBoardTurnRate;
		AddControllerYawInput(InputRate);
	}
}

void AMainCharacter::LookUpRate(const float rate)
{
	UWorld* World = GetWorld();

	if (World && rate != 0.f)
	{
		const float InputRate = rate * World->GetDeltaSeconds() * BaseKeyBoardLookUpRate;
		AddControllerPitchInput(InputRate);
	}
}

