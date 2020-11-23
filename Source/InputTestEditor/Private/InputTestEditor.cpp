
#include "InputTestEditor.h"

void FInputTestEditorModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Input Test Editor loaded"));
}

void FInputTestEditorModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Input Test Editor Shut Down"));
}

IMPLEMENT_MODULE(FInputTestEditorModule, InputTestEditor);