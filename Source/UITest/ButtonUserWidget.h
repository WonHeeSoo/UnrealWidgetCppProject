// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "ButtonUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UButtonUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		class UButton* ButtonBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonAnchorX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonAnchorY;

	virtual void NativeConstruct() override;

	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void handleMyButtonClick();

	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void ClickEventFunction();

	virtual void Construct_Implementation();

	//virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
};
