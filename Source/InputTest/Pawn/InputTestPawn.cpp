// Fill out your copyright notice in the Description page of Project Settings.


#include "InputTestPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputTest/Scripts/BaseInputScript.h"
#include "Engine/GameEngine.h"
#include "Kismet/GameplayStatics.h"

#define D(x) if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x));}

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
	
}



void AInputTestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Calling set functions
	SetCyclicInput();
	SetThrottleInput();
	SetPedalInput();
	SetCollectiveInput();

	
	UE_LOG(LogTemp, Warning, TEXT("Horizontal Value : %f"), GetHorizontalInput());
	UE_LOG(LogTemp, Warning, TEXT("Vertical Value : %f"), GetVerticalInput());
	

}

//////////////////////////////////////////////////////////////////////
// INPUT
void AInputTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//Setter Functions

void AInputTestPawn::SetHorizontalInput(float AxisValue)
{
	HorizontalInput = AxisValue;
}

void AInputTestPawn::SetVerticalInput(float AxisValue)
{
	VerticalInput = AxisValue;
}

void AInputTestPawn::SetThrottleInput()
{

}

void AInputTestPawn::SetPedalInput()
{

}

void AInputTestPawn::SetCollectiveInput()
{
}


void AInputTestPawn::SetCyclicInput()
{
	CyclicInput.Y = VerticalInput;
	CyclicInput.X = HorizontalInput;
}

//Getter Functions

float AInputTestPawn::GetHorizontalInput()
{
	return HorizontalInput;
}

float AInputTestPawn::GetVerticalInput()
{
	return  VerticalInput;
}

float AInputTestPawn::GetThrottleInput()
{
	return ThrottleInput;
}

float AInputTestPawn::GetPedalInput()
{
	return PedalInput;
}

float AInputTestPawn::GetCollectiveValue()
{
	return CollectiveInput;
}

FVector2D AInputTestPawn::GetCyclicInput()
{
	return CyclicInput;
}
