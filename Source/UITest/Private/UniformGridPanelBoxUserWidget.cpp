// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "UniformGridPanelBoxUserWidget.h"

void UUniformGridPanelBoxUserWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	RebuildWidget();
}

void UUniformGridPanelBoxUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	// Bind delegates here.
}

TSharedRef<SWidget> UUniformGridPanelBoxUserWidget::RebuildWidget()
{
	TSharedRef<SWidget> FinalWidget = Super::RebuildWidget();

	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	UniformGridPanelBox = WidgetTree->ConstructWidget<UUniformGridPanel>(UUniformGridPanel::StaticClass(), FName(TEXT("ButtonBox")));
	/*NamedSlotBox = WidgetTree->ConstructWidget<UNamedSlot>(UNamedSlot::StaticClass(), FName(TEXT("NamedSlotBox")));
	CanvasPanelBox = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), FName(TEXT("CanvasPanelBox")));

	RootWidget->AddChild(CanvasPanelBox);
	CanvasPanelBox->AddChild(UniformGridPanelBox);
	CanvasPanelBox->AddChild(NamedSlotBox);*/
	RootWidget->AddChild(UniformGridPanelBox);

	UCanvasPanelSlot* UniformGridPanelSlot = Cast<UCanvasPanelSlot>(UniformGridPanelBox->Slot);
	if (UniformGridPanelSlot)
	{
		UniformGridPanelSlot->SetSize(FVector2D(10.0f, 10.0f));
		
	}
	return FinalWidget;
}
