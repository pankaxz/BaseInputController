// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInputScript.h"



#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Engine/EngineTypes.h"

void UBaseInputScript::HandleInput()
{
    UE_LOG(LogTemp, Warning, TEXT("Handle Input called"));
}

void UBaseInputScript::CallTimer()
{
    FTimerHandle tHandle;
    const float Delay = 1.0f;
    GetWorld()->GetTimerManager().SetTimer(tHandle, this, &UBaseInputScript::TestTimer, Delay, false);
}

void UBaseInputScript::TestTimer()
{
    GEngine->AddOnScreenDebugMessage(1, 2, FColor::Red, "Hello World");
}

void UBaseInputScript::Tick(float DeltaTime)
{
    TestCounter += DeltaTime;

    GEngine->AddOnScreenDebugMessage(0, 0, FColor::Green, FString::SanitizeFloat(TestCounter));
    HandleInput();

}

bool UBaseInputScript::IsTickable() const
{
    return true;
}

bool UBaseInputScript::IsTickableInEditor() const
{
    return false;
}

bool UBaseInputScript::IsTickableWhenPaused() const
{
    return false;
}

TStatId UBaseInputScript::GetStatId() const
{
    return TStatId();
}

UWorld* UBaseInputScript::GetWorld() const
{
    return GetOuter()->GetWorld();
}