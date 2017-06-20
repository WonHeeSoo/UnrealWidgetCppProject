// Fill out your copyright notice in the Description page of Project Settings.

#include "UITest.h"
#include "UIPlayerController.h"

AUIPlayerController::AUIPlayerController()
{
}

void AUIPlayerController::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	MyController->bShowMouseCursor = true;
	MyController->bEnableClickEvents = true;
	MyController->bEnableMouseOverEvents = true;
}


