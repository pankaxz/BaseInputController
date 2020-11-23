// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomDetails.h"
#include "PropertyEditor/Public/DetailLayoutBuilder.h"
#include "PropertyEditor/Public/DetailCategoryBuilder.h"
#include "PropertyEditor/Public/DetailWidgetRow.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "InputTest/InputTest.h"
#include "Input/Reply.h"
#include "InputTest/Pawn/InputTestPawn.h"
#define LOCTEXT_NAMESPACE"CustomDetails"
TSharedRef<IDetailCustomization> FCustomDetails::MakeInstance()
{
    return MakeShareable(new FCustomDetails);
}



void FCustomDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{

    DetailBuilder.GetObjectsBeingCustomized(ObjectsToEdit);
    
    IDetailCategoryBuilder& Category = DetailBuilder.EditCategory
        ("Input Test", LOCTEXT("CatName", "Input Settings"),
        ECategoryPriority::Important );

    Category.AddCustomRow(LOCTEXT("Keyword", "Shuffle"))
    .NameContent()
    [
        SNew(STextBlock)
        .Text(LOCTEXT("NameText", "Reassign materials"))
        .Font(IDetailLayoutBuilder::GetDetailFont())
    ]
    .ValueContent()
    [
        SNew(SButton)
        .Text(LOCTEXT("ButtonText", "Shuffle"))
        .OnClicked_Raw(this, &FCustomDetails::EditObjects)
    ];
}

FReply FCustomDetails::EditObjects()
{
    for(TWeakObjectPtr<UObject> Object : ObjectsToEdit)
    {
        if(!Object.IsValid()) continue;

        AInputTestPawn* TestPawn = Cast<AInputTestPawn>(Object.Get());

        if(!TestPawn) continue;

    }
    
    return FReply::Handled;
}

#undef LOCTEXT_NAMESPACE