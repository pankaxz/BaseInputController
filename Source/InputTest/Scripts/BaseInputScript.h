// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseInputScript.generated.h"

/**
 * 
 */
UCLASS()
class INPUTTEST_API UBaseInputScript : public UObject
{
	GENERATED_BODY()


	public:
	UPROPERTY(VisibleAnywhere, Category= "Base Input")
	float Vertical = 0.0f;
	UPROPERTY(VisibleAnywhere, Category= "Base Input")
	float Horizontal = 0.0f;
	
	protected:
	virtual void HandleInput();

	
	public:
	UFUNCTION(BlueprintCallable, Category = Test)
    void CallTimer();

	void TestTimer();

	virtual void Tick(float DeltaTime);
	bool IsTickable() const;
	bool IsTickableInEditor() const;
	bool IsTickableWhenPaused() const;
	TStatId GetStatId() const;

	UWorld* GetWorld() const override;

	float TestCounter;
};
