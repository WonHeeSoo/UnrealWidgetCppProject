// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
//#include "ScrollBox.h"
//#include "VerticalBox.h"
//#include "Text.h"
#include "TextBlock.h"
#include "UIGameMode.h"
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
	/* �������� ��ư */
	UPROPERTY()
		class UButton* NoticeImage1;

	UPROPERTY()
		class UButton* NoticeImage2;

	UPROPERTY()
		class UButton* NoticeImage3;

	/* �������� ���� ���� */
	UPROPERTY()
		class UVerticalBox* NoticeBoard;

	/* �������� ��ġ �׸��� */
	UPROPERTY()
		class UGridPanel* NoticeGrid;

	/* �������� ���� */
	UPROPERTY()
		class UTextBlock* NoticeText1;

	UPROPERTY()
		class UTextBlock* NoticeText2;

	UPROPERTY()
		class UTextBlock* NoticeText3;

	UPROPERTY()
		class UTextBlock* NoticeText4;

	UPROPERTY()
		class UScrollBox* NoticeScrollBoard;

	/* �������� ��ư �̹��� ũ�� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonSizeY;

	/* ��ũ�� �� ũ�� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalTopSlotImageSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalTopSlotImageSizeY;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalBackgroundImageSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalBackgroundImageSizeY;*/
	
	/* �������� â ũ��*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float NoticeScrollBoxSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float NoticeScrollBoxSizeY;

	/* ��ũ�� �� �޹��, �� �̹��� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		UTexture *CustomVerticalBackgroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		UTexture *CustomNormalThumbImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		UTexture *CustomHoveredThumbImage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		UTexture *CustomDraggedThumbImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *NormalButtonImage1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *HoveredButtonImage1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *PressedButtonImage1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *DisabledButtonImage1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *NormalButtonImage2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *HoveredButtonImage2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *PressedButtonImage2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *DisabledButtonImage2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *NormalButtonImage3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *HoveredButtonImage3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *PressedButtonImage3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		UTexture *DisabledButtonImage3;

	/* �������� ���� */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FString MyString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FString MyString2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FString MyString3;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		//FSlateBrush * VerticalBackgroundImage;
	
	/* �������� ��Ʈ ����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FSlateFontInfo NoticeFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		int32 NoticeFontSize;
	
	virtual TSharedRef<SWidget> RebuildWidget() override;

	//virtual void NativeConstruct() override;

	/* ������ ���� �ʰ� ����� ���� �� Ȯ��*/
	virtual void SynchronizeProperties() override;

	/* �ȷ�Ʈ �з� ����*/
	virtual const FText GetPaletteCategory() override;
	
	/* �������� �̺�Ʈ */
	UFUNCTION(BlueprintCallable, Category = NoticeWidgetClass)
	void NoticeFunction1();
	
	UFUNCTION(BlueprintCallable, Category = NoticeWidgetClass)
	void NoticeFunction2();
	
	UFUNCTION(BlueprintCallable, Category = NoticeWidgetClass)
	void NoticeFunction3();

};
