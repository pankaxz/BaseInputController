// Fill out your copyright notice in the Description page of Project Settings.


#include "InputTestPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputTest/Scripts/BaseInputScript.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInputTestPawn::AInputTestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//Components
	SM_TestPawnBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TestPawnBody"));
	RootComponent = SM_TestPawnBody;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AInputTestPawn::BeginPlay()
{
	Super::BeginPlay();
	BaseInputScript = NewObject<UBaseInputScript>(this);
}

void AInputTestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(BaseInputScript)
	{
		BaseInputScript->HandleInput();
	}
}

// Called to bind functionality to input
void AInputTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

