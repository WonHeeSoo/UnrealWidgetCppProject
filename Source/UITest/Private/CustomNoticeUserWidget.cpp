// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "CustomNoticeUserWidget.h"

#define LOCTEXT_NAMESPACE "UMG"

void UCustomNoticeUserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	//RebuildWidget();
}

const FText UCustomNoticeUserWidget::GetPaletteCategory()
{
	return LOCTEXT("", "CustomNotice");
}

/*void UCustomNoticeUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	// Bind delegates here.
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
		/* ���� ���� */
		NoticeScrollBoard = WidgetTree->ConstructWidget<UScrollBox>(UScrollBox::StaticClass(), TEXT("VerticalBoxThatUsesUNIT64"));
		NoticeGrid = WidgetTree->ConstructWidget<UGridPanel>(UGridPanel::StaticClass(), TEXT("Grid"));
		NoticeText1 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TextBox1"));
		NoticeText2 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TextBox2"));
		NoticeText3 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TextBox3"));
		NoticeImage1 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button1"));
		NoticeImage2 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button2"));
		NoticeImage3 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("Button3"));
		
		NoticeImage1->OnClicked.AddDynamic(this, &UCustomNoticeUserWidget::NoticeFunction1);
		NoticeImage2->OnClicked.AddDynamic(this, &UCustomNoticeUserWidget::NoticeFunction2);
		NoticeImage3->OnClicked.AddDynamic(this, &UCustomNoticeUserWidget::NoticeFunction3);

		/* �������� */
		RootWidget->AddChild(NoticeScrollBoard);
		NoticeScrollBoard->AddChild(NoticeGrid);
		NoticeGrid->AddChild(NoticeText1);
		NoticeGrid->AddChild(NoticeImage1);
		NoticeGrid->AddChild(NoticeText2);
		NoticeGrid->AddChild(NoticeImage2);
		NoticeGrid->AddChild(NoticeText3);
		NoticeGrid->AddChild(NoticeImage3);

		/* ���� ���� ���� */
		UCanvasPanelSlot* NoticeScrollBoardSlot = Cast<UCanvasPanelSlot>(NoticeScrollBoard->Slot);
		UScrollBoxSlot* NoticeGridSlot = Cast<UScrollBoxSlot>(NoticeGrid->Slot);
		UGridSlot* NoticeTextSlot1 = Cast<UGridSlot>(NoticeText1->Slot);
		UGridSlot* NoticeImageSlot1 = Cast<UGridSlot>(NoticeImage1->Slot);
		UGridSlot* NoticeTextSlot2 = Cast<UGridSlot>(NoticeText2->Slot);
		UGridSlot* NoticeImageSlot2 = Cast<UGridSlot>(NoticeImage2->Slot);
		UGridSlot* NoticeTextSlot3 = Cast<UGridSlot>(NoticeText3->Slot);
		UGridSlot* NoticeImageSlot3 = Cast<UGridSlot>(NoticeImage3->Slot);

		/* ��ũ�� �ڽ� ���� */
		//NoticeScrollBoard->WidgetBarStyle.SetVerticalBackgroundImage(VerticalBackgroundImage);
		NoticeScrollBoard->WidgetBarStyle.VerticalBackgroundImage.SetResourceObject(CustomVerticalBackgroundImage);
		//NoticeScrollBoard->WidgetBarStyle.VerticalBackgroundImage.ImageSize = FVector2D(VerticalBackgroundImageSizeX, VerticalBackgroundImageSizeY);
		NoticeScrollBoard->WidgetBarStyle.VerticalBackgroundImage.DrawAs = ESlateBrushDrawType::Image;
		NoticeScrollBoard->WidgetBarStyle.VerticalTopSlotImage.ImageSize = FVector2D(VerticalTopSlotImageSizeX, VerticalTopSlotImageSizeY);
		
		NoticeScrollBoard->WidgetBarStyle.NormalThumbImage.SetResourceObject(CustomNormalThumbImage);
		NoticeScrollBoard->WidgetBarStyle.NormalThumbImage.DrawAs = ESlateBrushDrawType::Image;
		NoticeScrollBoard->WidgetBarStyle.HoveredThumbImage.SetResourceObject(CustomHoveredThumbImage);
		NoticeScrollBoard->WidgetBarStyle.HoveredThumbImage.DrawAs = ESlateBrushDrawType::Image;
		NoticeScrollBoard->WidgetBarStyle.DraggedThumbImage.SetResourceObject(CustomDraggedThumbImage);
		NoticeScrollBoard->WidgetBarStyle.DraggedThumbImage.DrawAs = ESlateBrushDrawType::Image;

		NoticeScrollBoardSlot->SetSize(FVector2D(NoticeScrollBoxSizeX, NoticeScrollBoxSizeY));
		NoticeScrollBoard->AlwaysShowScrollbar = true;
		
		NoticeScrollBoard->ScrollBarVisibility = ESlateVisibility::Visible;

		NoticeGridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
		
		/* �׸��� Row ũ�� */
		NoticeTextSlot1->SetRow(0);
		NoticeImageSlot1->SetRow(1);
		NoticeTextSlot2->SetRow(2);
		NoticeImageSlot2->SetRow(3);
		NoticeTextSlot3->SetRow(4);
		NoticeImageSlot3->SetRow(5);

		/* ��Ʈ ���� �� ��Ʈ ũ�� */
		NoticeText1->SetFont(NoticeFont);
		NoticeText2->SetFont(NoticeFont);
		NoticeText3->SetFont(NoticeFont);
		NoticeText1->Font.Size = NoticeFontSize;
		NoticeText2->Font.Size = NoticeFontSize;
		NoticeText3->Font.Size = NoticeFontSize;

		/* �������� 1 ���� ���� */
		//NoticeTextSlot1->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
		NoticeText1->SetText(FText::FromString(MyString));
		
		/* �������� 1 ��ư ���� */
		NoticeImage1->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage1->WidgetStyle.Normal.SetResourceObject(NormalButtonImage1);
		NoticeImage1->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage1->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage1->WidgetStyle.Hovered.SetResourceObject(HoveredButtonImage1);
		NoticeImage1->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage1->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage1->WidgetStyle.Pressed.SetResourceObject(PressedButtonImage1);
		NoticeImage1->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage1->WidgetStyle.Disabled.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage1->WidgetStyle.Disabled.SetResourceObject(DisabledButtonImage1);
		NoticeImage1->WidgetStyle.Disabled.DrawAs = ESlateBrushDrawType::Image;
		
		/* �������� 2 ���� ���� */
		//NoticeTextSlot2->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
		NoticeText2->SetText(FText::FromString(MyString2));
		
		/* �������� 2 ��ư ���� */
		NoticeImage2->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage2->WidgetStyle.Normal.SetResourceObject(NormalButtonImage2);
		NoticeImage2->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage2->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage2->WidgetStyle.Hovered.SetResourceObject(HoveredButtonImage2);
		NoticeImage2->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage2->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage2->WidgetStyle.Pressed.SetResourceObject(PressedButtonImage2);
		NoticeImage2->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage2->WidgetStyle.Disabled.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage2->WidgetStyle.Disabled.SetResourceObject(DisabledButtonImage2);
		NoticeImage2->WidgetStyle.Disabled.DrawAs = ESlateBrushDrawType::Image;
		
		/* �������� 2 ���� ���� */
		//NoticeTextSlot3->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
		NoticeText3->SetText(FText::FromString(MyString3));
		
		/* �������� 3 ��ư ���� */
		NoticeImage3->WidgetStyle.Normal.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage3->WidgetStyle.Normal.SetResourceObject(NormalButtonImage3);
		NoticeImage3->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage3->WidgetStyle.Hovered.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage3->WidgetStyle.Hovered.SetResourceObject(HoveredButtonImage3);
		NoticeImage3->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage3->WidgetStyle.Pressed.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage3->WidgetStyle.Pressed.SetResourceObject(PressedButtonImage3);
		NoticeImage3->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;
		NoticeImage3->WidgetStyle.Disabled.ImageSize = FVector2D(ButtonSizeX, ButtonSizeY);
		NoticeImage3->WidgetStyle.Disabled.SetResourceObject(DisabledButtonImage3);
		NoticeImage3->WidgetStyle.Disabled.DrawAs = ESlateBrushDrawType::Image;
	}

	return Widget;
}

void UCustomNoticeUserWidget::NoticeFunction1()
{
	UE_LOG(LogClass, Log, TEXT("NoticeFunction1 Clicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "NoticeFunction1 Clicked");
}

void UCustomNoticeUserWidget::NoticeFunction2()
{
	AUIGameMode * UIGM = Cast<AUIGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UIGM->ScreenNotice1Widget();
	UE_LOG(LogClass, Log, TEXT("NoticeFunction2 Clicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "NoticeFunction2 Clicked");
}

void UCustomNoticeUserWidget::NoticeFunction3()
{
	UE_LOG(LogClass, Log, TEXT("NoticeFunction3 Clicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "NoticeFunction3 Clicked");
}

#undef LOCTEXT_NAMESPACE