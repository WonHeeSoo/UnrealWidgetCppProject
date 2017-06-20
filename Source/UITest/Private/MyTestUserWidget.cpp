// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "MyTestUserWidget.h"


void UMyTestUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonSize = 100.0F;
	// Bind delegates here.
}

TSharedRef<SWidget> UMyTestUserWidget::RebuildWidget()
{
	TSharedRef<SWidget> FinalWidget = Super::RebuildWidget();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	Button1 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), FName(TEXT("Button1TEXT")));
	RootWidget->AddChild(Button1);

	UCanvasPanelSlot* ButtonSlot = Cast<UCanvasPanelSlot>(Button1->Slot);
	if (ButtonSlot)
	{
		ButtonSlot->SetSize(FVector2D(ButtonSize, ButtonSize));

	}
	return FinalWidget;
}
