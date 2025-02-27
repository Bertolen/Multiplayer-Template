// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IntruderMulti.h"
#include "Blueprint/UserWidget.h"
#include "ChatWindow.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERTEMPLATE_API UChatWindow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Client, Reliable)
		void UpdateChatWindow(const FText & Sender, const FText & Text);

	UFUNCTION(BlueprintCallable)
		void CommitText(FText Text);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BlueprintProtected = "true"))
		class UScrollBox * ChatLogWB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (BlueprintProtected = "true"))
		class UEditableTextBox * ChatEntryWB;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ChatWindow|WidgetClasses", meta = (BlueprintProtected = "true"))
		TSubclassOf<class UChatText> ChatTextClass;
};
