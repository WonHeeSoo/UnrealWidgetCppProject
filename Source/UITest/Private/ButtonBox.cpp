// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "ButtonBox.h"

UButtonBox::UButtonBox()
{
	OnClicked.AddDynamic(this, &UButtonBox::ClickFunction);
}
void UButtonBox::ClickFunction()
{
	UE_LOG(LogClass, Log, TEXT("Clicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "Clicked");
}
TSharedRef<SWidget> UButtonBox::RebuildWidget()
{
	MyButton = SNew(SButton)
		.OnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked))
		.OnPressed(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandlePressed))
		.OnReleased(BIND_UOBJECT_DELEGATE(FSimpleDelegate, SlateHandleReleased))
		.OnHovered_UObject(this, &ThisClass::SlateHandleHovered)
		.OnUnhovered_UObject(this, &ThisClass::SlateHandleUnhovered)
		.ButtonStyle(&WidgetStyle)
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.IsFocusable(IsFocusable)
		;

	if (GetChildrenCount() > 0)
	{
		Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyButton.ToSharedRef());
	}

	return MyButton.ToSharedRef();
}
FReply UButtonBox::SlateHandleClicked()
{
	UE_LOG(LogClass, Log, TEXT("SlateHandleClicked"));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, "SlateHandleClicked");
	OnClicked.Broadcast();

	return FReply::Handled();
}