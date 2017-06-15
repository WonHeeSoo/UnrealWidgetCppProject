// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GameFramework/GameMode.h"
#include "UIGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API AUIGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UMG System")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG System")
		TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY()
		UUserWidget * CurrentWidget;

	AUIGameMode();

protected:
	virtual void BeginPlay() override;
};
