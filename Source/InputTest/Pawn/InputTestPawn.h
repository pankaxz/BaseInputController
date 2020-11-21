// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputTestPawn.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;


UCLASS()
class INPUTTEST_API AInputTestPawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputTest", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_TestPawnBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputTest", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputTest", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	public:
	
	AInputTestPawn();

	virtual void Tick(float DeltaTime) override;

	//Input Functions
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Getters
	float GetHorizontalInput();
	float GetVerticalInput() ;
	float GetThrottleInput();
	float GetPedalInput();
	float GetCollectiveValue();
	FVector2D GetCyclicInput();
	


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//Setters
	void SetHorizontalInput(float AxisValue);
	void SetVerticalInput(float AxisValue);
	void SetThrottleInput();
	void SetPedalInput();
	void SetCollectiveInput();
	void SetCyclicInput();

	
	//Input Variables
	UPROPERTY(VisibleAnywhere, Category = "InputTest")
	float HorizontalInput = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "InputTest")
	float VerticalInput = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "InputTest")
	float ThrottleInput = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "InputTest")
	float CollectiveInput = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "InputTest")
	FVector2D CyclicInput = FVector2D().ZeroVector;
	
	UPROPERTY(VisibleAnywhere, Category = "InputTest")
	float PedalInput = 0.0f;
	
};

