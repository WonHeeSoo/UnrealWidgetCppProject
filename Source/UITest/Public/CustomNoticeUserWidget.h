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
	/* 공지사항 버튼 */
	UPROPERTY()
		class UButton* NoticeImage1;

	UPROPERTY()
		class UButton* NoticeImage2;

	UPROPERTY()
		class UButton* NoticeImage3;

	/* 공지사항 세로 라인 */
	UPROPERTY()
		class UVerticalBox* NoticeBoard;

	/* 공지사항 배치 그리드 */
	UPROPERTY()
		class UGridPanel* NoticeGrid;

	/* 공지사항 제목 */
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

	/* 공지사항 버튼 이미지 크기 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonSetting")
		float ButtonSizeY;

	/* 스크롤 바 크기 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalTopSlotImageSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalTopSlotImageSizeY;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalBackgroundImageSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float VerticalBackgroundImageSizeY;*/
	
	/* 공지사항 창 크기*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float NoticeScrollBoxSizeX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ScrollSetting")
		float NoticeScrollBoxSizeY;

	/* 스크롤 바 뒷배경, 바 이미지 */
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

	/* 공지사항 제목 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FString MyString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FString MyString2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FString MyString3;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ButtonStyleSetting")
		//FSlateBrush * VerticalBackgroundImage;
	
	/* 공지사항 폰트 관련*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		FSlateFontInfo NoticeFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TextSetting")
		int32 NoticeFontSize;
	
	virtual TSharedRef<SWidget> RebuildWidget() override;

	//virtual void NativeConstruct() override;

	/* 컴파일 하지 않고도 번경된 상태 값 확인*/
	virtual void SynchronizeProperties() override;

	/* 팔레트 분류 생성*/
	virtual const FText GetPaletteCategory() override;
	
	/* 공지사항 이벤트 */
	UFUNCTION(BlueprintCallable, Category = NoticeWidgetClass)
	void NoticeFunction1();
	
	UFUNCTION(BlueprintCallable, Category = NoticeWidgetClass)
	void NoticeFunction2();
	
	UFUNCTION(BlueprintCallable, Category = NoticeWidgetClass)
	void NoticeFunction3();

};
