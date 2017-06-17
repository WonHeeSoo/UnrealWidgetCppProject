// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "ButtonUserWidget.h"

void UButtonUserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	RebuildWidget();
}

void UButtonUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonBox->OnClicked.AddDynamic(this, &UButtonUserWidget::ClickEventFunction);
	// Bind delegates here.
}

TSharedRef<SWidget> UButtonUserWidget::RebuildWidget()
{
	TSharedRef<SWidget> FinalWidget = Super::RebuildWidget();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	ButtonBox = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), FName(TEXT("ButtonBox")));
//	GridBox = WidgetTree->ConstructWidget<UGridPanel>(UGridPanel::StaticClass(), FName(TEXT("GridBox")));
//	RootWidget->AddChild(GridBox);
	//GridBox->AddChild(ButtonBox);
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
		ButtonBox->WidgetStyle.Normal.ImageSize = FVector2D(40.0f,40.0f);
		ButtonBox->WidgetStyle.Normal.DrawAs = ESlateBrushDrawType::Image;

		ButtonBox->WidgetStyle.Hovered.SetResourceObject(HoveredButtonImage);
		ButtonBox->WidgetStyle.Hovered.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Image;

		ButtonBox->WidgetStyle.Pressed.SetResourceObject(PressedButtonImage);
		ButtonBox->WidgetStyle.Pressed.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Image;

		ButtonBox->WidgetStyle.Disabled.SetResourceObject(DisabledButtonImage);
		ButtonBox->WidgetStyle.Disabled.ImageSize = FVector2D(40.0f, 40.0f);
		ButtonBox->WidgetStyle.Disabled.DrawAs = ESlateBrushDrawType::Image;

		//ButtonBox->WidgetStyle.Normal.TintColor. // FVector4(1.0f, 1.0f, 1.0f, 0.5f);
		//DrawAsNormal::Image;//Cast<ESlateBrushDrawType>(DrawAsNormal);//ESlateBrushDrawType::Image;
		//ESlateBrushDrawType::Image;
		//ButtonSlot->SetAutoSize
		//ButtonSlot->
	}
	return FinalWidget;
}

/*void UButtonUserWidget::handleMyButtonClick()
{
	UE_LOG(LogClass, Log, TEXT("HandleClicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "HandleClicked");
	//UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit);
	// implementation of functionality
}*/

/*void UButtonUserWidget::Construct_Implementation()
{
	//Super::Construct_Implementation();
	//UButton* InteractionButtton = (UButton*)GetWidgetFromName(TEXT("ButtonWidget"));
	//InteractionButtton->OnClicked.AddDynamic(this, &UButtonUserWidget::ClickEventFunction);
	ButtonBox->OnClicked.AddDynamic(this, &UButtonUserWidget::ClickEventFunction);
	
}*/

void UButtonUserWidget::ClickEventFunction()
{
	UE_LOG(LogClass, Log, TEXT("Clicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "Clicked");
}

/*FReply UButtonUserWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	UE_LOG(LogClass, Log, TEXT("Clicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "Clicked");
	//return FReply(true);
	return FReply(true);
}*/