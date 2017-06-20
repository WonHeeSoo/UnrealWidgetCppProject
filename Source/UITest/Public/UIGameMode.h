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

	UFUNCTION(BlueprintCallable, Category = "UMG System")
		void ScreenNotice1Widget();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG System")
		TSubclassOf<UUserWidget> MainMenuWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG System")
		TSubclassOf<UUserWidget> Notice1WidgetClass;

	UPROPERTY()
		UUserWidget *CurrentWidget;
	UPROPERTY()
		UUserWidget *Notice1Widget;

	AUIGameMode();

protected:
	virtual void BeginPlay() override;
};
