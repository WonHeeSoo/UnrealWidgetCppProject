// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
//#include "WidgetTree.h"
//#include "TextWidgetTypes.h"
//#include "TextBlock.h"
#include "MyTestUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UMyTestUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	class UButton* Button1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	float ButtonSize;

	virtual void NativeConstruct() override;
	
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
