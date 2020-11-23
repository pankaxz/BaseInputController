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
	
	UE_LOG(LogTemp, Warning, TEXT("Cyclic X Value : %f"), CyclicInput.X);
	UE_LOG(LogTemp, Warning, TEXT("Cyclic Y Value : %f"), CyclicInput.Y);
	UE_LOG(LogTemp, Warning, TEXT("Throttle Value : %f"), GetThrottleInput());
	UE_LOG(LogTemp, Warning, TEXT("Collective Value : %f"), GetCollectiveInput());
	UE_LOG(LogTemp, Warning, TEXT("______________________________________________________"));
	
	//UE_LOG(LogTemp, Warning, TEXT("cyclic Value : %f"), GetCyclicInput());
}

//////////////////////////////////////////////////////////////////////
// INPUT
void AInputTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//KEYBOARD
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AInputTestPawn::SetHorizontalInput);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &AInputTestPawn::SetVerticalInput);
	PlayerInputComponent->BindAxis(TEXT("Throttle"), this, &AInputTestPawn::SetThrottleInput);
	PlayerInputComponent->BindAxis(TEXT("Collective"), this, &AInputTestPawn::SetCollectiveInput);
	PlayerInputComponent->BindAxis(TEXT("Pedal"), this, &AInputTestPawn::SetPedalInput);
	//XBOX CONTROLLER
	PlayerInputComponent->BindAxis(TEXT("XBOXCyclicVertical"), this, &AInputTestPawn::SetVerticalInput);
	PlayerInputComponent->BindAxis(TEXT("XBOXCyclicHorizontal"), this, &AInputTestPawn::SetHorizontalInput);
	PlayerInputComponent->BindAxis(TEXT("XBOXCollective"), this, &AInputTestPawn::SetCollectiveInput);
	PlayerInputComponent->BindAxis(TEXT("XBOXPedal"), this, &AInputTestPawn::SetPedalInput);
	PlayerInputComponent->BindAxis(TEXT("XBOXThrottle"), this, &AInputTestPawn::SetThrottleInput);
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

void AInputTestPawn::SetThrottleInput(float AxisValue)
{
	ThrottleInput = AxisValue;
}

void AInputTestPawn::SetPedalInput(float AxisValue)
{
	PedalInput = AxisValue;
}

void AInputTestPawn::SetCollectiveInput(float AxisValue)
{
	CollectiveInput = AxisValue;
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

float AInputTestPawn::GetCollectiveInput()
{
	return CollectiveInput;
}

FVector2D AInputTestPawn::GetCyclicInput()
{
	return CyclicInput;
}
