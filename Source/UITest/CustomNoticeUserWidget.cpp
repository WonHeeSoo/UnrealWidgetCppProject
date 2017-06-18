// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "CustomNoticeUserWidget.h"

/*void UCustomNoticeUserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	RebuildWidget();
}*/

TSharedRef<SWidget> UCustomNoticeUserWidget::RebuildWidget()
{
	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	if (!RootWidget)
	{
		RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootWidget"));
		UCanvasPanelSlot* RootWidgetSlot = Cast<UCanvasPanelSlot>(RootWidget->Slot);
		if (RootWidgetSlot)
		{
			RootWidgetSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
			RootWidgetSlot->SetOffsets(FMargin(0.0f, 0.0f));
		}

		WidgetTree->RootWidget = RootWidget;

	}
	//super :: RebuildWidget () /�� ȣ���ϱ� ���� ��Ʈ ������ �����ؾ��մϴ�.
	//�� ������ UWidget::RebuildWidget()�� TakeWidget()�� ȣ���ϰ� ������ ��Ʈ ���� �ʱ�ȭ�� �ʿ��� �����ڸ� ȣ���ϱ� �����Դϴ�.
	//���⼭ �ܼ��� takewidget()�� ȣ�� �� ���� �����ϴ�.
	
	

	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	if (RootWidget && WidgetTree)
	{
		NoticeScrollBoard = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("VerticalBoxThatUsesUNIT64"));
		NoticeGrid = WidgetTree->ConstructWidget<UGridPanel>(UGridPanel::StaticClass(), TEXT("Grid"));
		NoticeText = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TextBox"));
		NoticeText2 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TextBox2"));
		NoticeText3 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TextBox3"));
		
		RootWidget->AddChild(NoticeScrollBoard);
		NoticeScrollBoard->AddChild(NoticeGrid);
		NoticeGrid->AddChild(NoticeText);
		NoticeGrid->AddChild(NoticeText2);
		NoticeGrid->AddChild(NoticeText3);

		UCanvasPanelSlot* NoticeScrollBoardSlot = Cast<UCanvasPanelSlot>(NoticeScrollBoard->Slot);
		UScrollBoxSlot* NoticeGridSlot = Cast<UScrollBoxSlot>(NoticeGrid->Slot);
		UGridSlot* NoticeTextSlot = Cast<UGridSlot>(NoticeText->Slot);
		UGridSlot* NoticeTextSlot2 = Cast<UGridSlot>(NoticeText2->Slot);
		UGridSlot* NoticeTextSlot3 = Cast<UGridSlot>(NoticeText3->Slot);

		//NoticeScrollBoard->WidgetBarStyle.SetVerticalBackgroundImage(VerticalBackgroundImage);
		NoticeScrollBoard->WidgetBarStyle.VerticalBackgroundImage.SetResourceObject(CustomVerticalBackgroundImage);
		NoticeScrollBoard->WidgetBarStyle.VerticalBackgroundImage.ImageSize = FVector2D(VerticalBackgroundImageSizeX, VerticalBackgroundImageSizeY);
		NoticeScrollBoard->WidgetBarStyle.NormalThumbImage.SetResourceObject(CustomNormalThumbImage);
		NoticeScrollBoardSlot->SetSize(FVector2D(NoticeScrollSizeX, NoticeScrollSizeY));
		//NoticeScrollBoardSlot->set
		NoticeScrollBoard->AlwaysShowScrollbar = true;
		NoticeScrollBoard->ScrollbarThickness = FVector2D(ScrollThicknessX, ScrollThicknessY);
		NoticeScrollBoard->ScrollBarVisibility = ESlateVisibility::Visible;
				
		//NoticeGridSlot->SetSize(FVector2D(200.0f, 40.0f));
		NoticeGridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
		

		MyString = "NoticePlease65";
		MyString2 = "Second65";
		MyString3 = "Test Please";

		NoticeText->SetText(FText::FromString(MyString));
		NoticeTextSlot->SetRow(0);
		NoticeText2->SetText(FText::FromString(MyString2));
		NoticeTextSlot2->SetRow(1);
		NoticeText3->SetText(FText::FromString(MyString3));
		NoticeTextSlot3->SetRow(2);

			//NoticeTextSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
			
	}


	return Widget;
}
