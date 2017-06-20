// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "UIGameMode.h"

AUIGameMode::AUIGameMode() : Super()
{
	static ConstructorHelpers::FClassFinder<APlayerController> 
		PlayerPawnClassFinder(TEXT("/Script/UITest.UIPlayerController"));
	PlayerControllerClass = PlayerPawnClassFinder.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget>
		MainMenuWidgetClassFinder(TEXT("/Game/StarterContent/TestWidget"));
	MainMenuWidgetClass = MainMenuWidgetClassFinder.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget>
		Notice1WidgetClassFinder(TEXT("/Game/StarterContent/ButtonWidget"));
	Notice1WidgetClass = Notice1WidgetClassFinder.Class;
}

void AUIGameMode::BeginPlay()
{
	Super::BeginPlay();

	ChangeMenuWidget(MainMenuWidgetClass);
}

void AUIGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AUIGameMode::ScreenNotice1Widget()
{
	if (Notice1Widget == nullptr)
	{
		Notice1Widget = CreateWidget<UUserWidget>(GetWorld(), Notice1WidgetClass);
		if (Notice1Widget != nullptr)
		{
			Notice1Widget->AddToViewport();
		}
	}
	else
	{
		Notice1Widget->RemoveFromViewport();
		Notice1Widget = nullptr;
	}
}