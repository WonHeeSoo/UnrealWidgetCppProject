// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "UIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API AUIPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AUIPlayerController();
	
protected:
	virtual void BeginPlay() override;
};
