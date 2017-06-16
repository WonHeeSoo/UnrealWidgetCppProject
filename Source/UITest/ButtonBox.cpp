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

