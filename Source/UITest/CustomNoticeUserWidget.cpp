// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "CustomNoticeUserWidget.h"

TSharedRef<SWidget> UCustomNoticeUserWidget::RebuildWidget()
{
	TSharedRef<SWidget> FinalWidget = Super::RebuildWidget();

	/*UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	ButtonBox = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), FName(TEXT("ButtonBox")));
	RootWidget->AddChild(ButtonBox);

	UCanvasPanelSlot* ButtonSlot = Cast<UCanvasPanelSlot>(ButtonBox->Slot);
	if (ButtonSlot)
	{
		ButtonSlot->SetSize(FVector2D(ButtonSizeX, ButtonSizeY));
		ButtonSlot->SetAnchors(FAnchors(ButtonAnchorX, ButtonAnchorY));
		ButtonSlot->SetAlignment(FVector2D(AlignmentX, AlignmentY));
		ButtonSlot->SetZOrder(ButtonZOrder);
		ButtonSlot->SetAutoSize(bAutoSize);

		ButtonBox->WidgetStyle.Normal.SetResourceObject(NormalButtonImage);
		ButtonBox->WidgetStyle.Normal.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Image;

		ButtonBox->WidgetStyle.Hovered.SetResourceObject(HoveredButtonImage);
		ButtonBox->WidgetStyle.Hovered.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;

		ButtonBox->WidgetStyle.Pressed.SetResourceObject(PressedButtonImage);
		ButtonBox->WidgetStyle.Pressed.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;

		ButtonBox->WidgetStyle.Disabled.SetResourceObject(DisabledButtonImage);
		ButtonBox->WidgetStyle.Disabled.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Disabled.DrawAs = ESlateBrushDrawType::Image;*/
	}
	return FinalWidget;
}


