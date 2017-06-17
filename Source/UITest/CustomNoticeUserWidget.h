// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
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
		class UTEXT* NoticeTitleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture2D *NormalButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture2D *HoveredButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture2D *PressedButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture2D *DisabledButtonImage;
	
	virtual void NativeConstruct() override;

	virtual TSharedRef<SWidget> RebuildWidget() override;

	virtual void SynchronizeProperties() override;
	
};
