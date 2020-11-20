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
	UE_LOG(LogTemp, Warning, TEXT("Horizontal Value : %f"), HorizontalAxisVal);
	UE_LOG(LogTemp, Warning, TEXT("Vertical Value : %f"), VerticalAxisVal);
}

// Called to bind functionality to input
void AInputTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &AInputTestPawn::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &AInputTestPawn::Vertical);

}

void AInputTestPawn::Horizontal(float AxisValue)
{
	HorizontalAxisVal = AxisValue;
	PedalInput = HorizontalAxisVal;
}

void AInputTestPawn::Vertical(float AxisValue)
{
	VerticalAxisVal = AxisValue;
	ThrottleInput = VerticalAxisVal;
}
