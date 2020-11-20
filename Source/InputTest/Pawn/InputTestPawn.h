// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputTest/Scripts/BaseInputScript.h"
#include "InputTestPawn.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class INPUTTEST_API AInputTestPawn : public APawn
{
	GENERATED_BODY()

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputTest", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* SM_TestPawnBody;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputTest", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "InputTest", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	
	
public:
	// Sets default values for this pawn's properties
	AInputTestPawn();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly)
	UBaseInputScript* BaseInputScript;
};
