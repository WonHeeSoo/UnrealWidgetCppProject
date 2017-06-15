// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "ButtonUserWidget.h"


void UButtonUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	
	//OnClicked.AddDynamic(this, &UButtonUserWidget::ClickEventFunction);
	// Bind delegates here.
}

TSharedRef<SWidget> UButtonUserWidget::RebuildWidget()
{
	TSharedRef<SWidget> FinalWidget = Super::RebuildWidget();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	ButtonBox = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), FName(TEXT("Button1TEXT")));
	RootWidget->AddChild(ButtonBox);

	UCanvasPanelSlot* ButtonSlot = Cast<UCanvasPanelSlot>(ButtonBox->Slot);
	if (ButtonSlot)
	{
		ButtonSlot->SetSize(FVector2D(ButtonSizeX, ButtonSizeY));
		ButtonSlot->SetAnchors(FAnchors(ButtonAnchorX, ButtonAnchorY));
		//ButtonSlot->SetAlignment
		//ButtonSlot->SetZOrder()
		//ButtonSlot->SetAutoSize
		//ButtonSlot->
	}
	return FinalWidget;
}

void UButtonUserWidget::handleMyButtonClick()
{
	UE_LOG(LogClass, Log, TEXT("HandleClicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "HandleClicked");
	//UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit);
	// implementation of functionality
}

void UButtonUserWidget::Construct_Implementation()
{
	//Super::Construct_Implementation();
	//UButton* InteractionButtton = (UButton*)GetWidgetFromName(TEXT("ButtonWidget"));
	//InteractionButtton->OnClicked.AddDynamic(this, &UButtonUserWidget::ClickEventFunction);
	ButtonBox->OnClicked.AddDynamic(this, &UButtonUserWidget::ClickEventFunction);
	
}

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