// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MultiplayerTemplate/UI/AllLevels/ChatWindow.h"
#include "GameplayChat.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERTEMPLATE_API UGameplayChat : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FORCEINLINE UChatWindow* GetChatWindow() { return ChatWindowWB; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BlueprintProtected = "true"))
	UChatWindow* ChatWindowWB;
};
