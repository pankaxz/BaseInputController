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
	virtual void HandleInput();
	
};
