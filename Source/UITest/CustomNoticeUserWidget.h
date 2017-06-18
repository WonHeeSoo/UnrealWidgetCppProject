// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
//#include "ScrollBox.h"
//#include "VerticalBox.h"
//#include "Text.h"
#include "TextBlock.h"
//#include "SlateBrush.h"
#include "CustomNoticeUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UCustomNoticeUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		class UButton* NoticeImageBox;

	UPROPERTY()
		class UVerticalBox* NoticeBoard;

	UPROPERTY()
		class UGridPanel* NoticeGrid;

	UPROPERTY()
		class UTextBlock* NoticeText;

	UPROPERTY()
		class UTextBlock* NoticeText2;

	UPROPERTY()
		class UTextBlock* NoticeText3;

	UPROPERTY()
		class UScrollBox* NoticeScrollBoard;

	/*UPROPERTY()
		class UTextBox* NoticeTitleText;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ScrollThicknessX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ScrollThicknessY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float VerticalBackgroundImageSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float VerticalBackgroundImageSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float NoticeScrollSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float NoticeScrollSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *CustomVerticalBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *CustomNormalThumbImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *PressedButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *DisabledButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		FString MyString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		FString MyString2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		FString MyString3;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		//FSlateBrush * VerticalBackgroundImage;
	//virtual void NativeConstruct() override;

	virtual TSharedRef<SWidget> RebuildWidget() override;

	//virtual void SynchronizeProperties() override;
	//void CreateNotice();
};
