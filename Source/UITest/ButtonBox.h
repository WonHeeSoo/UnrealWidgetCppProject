// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/Button.h"
#include "ButtonBox.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UButtonBox : public UButton
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonAnchorX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonAnchorY;
	
	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void ClickFunction();

	UButtonBox();
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
protected:
	/** Cached pointer to the underlying slate button owned by this UWidget */
	TSharedPtr<SButton> MyButtonBox;
protected:
	/** Handle the actual click event from slate and forward it on */
	FReply SlateHandleClicked();
};
