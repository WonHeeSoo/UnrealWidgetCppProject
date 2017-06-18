// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "ButtonUserWidget.generated.h"

/**
 * 
 */
/*UENUM(BlueprintType)
enum class EDrawAsList : uint8
{
	NoDrawType,
	Box,
	Border,
	Image
};*/

UCLASS()
class UITEST_API UButtonUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		class UButton* ButtonBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonSizeY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonAnchorX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float ButtonAnchorY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		int32 ButtonZOrder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float AlignmentX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		float AlignmentY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSlotSetting")
		bool bAutoSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *NormalButtonImage;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		enum ESlateBrushDrawType *DrawAsNormal;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *HoveredButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *PressedButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *DisabledButtonImage;


	virtual void NativeConstruct() override;

	virtual TSharedRef<SWidget> RebuildWidget() override;

	virtual void SynchronizeProperties() override;
	
	virtual const FText GetPaletteCategory() override;
	/*UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void handleMyButtonClick();*/

	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void ClickEventFunction();

	//virtual void Construct_Implementation();

	//virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);


};
