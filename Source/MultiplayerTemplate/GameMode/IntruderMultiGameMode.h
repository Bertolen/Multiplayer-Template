// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IntruderMultiGameMode.generated.h"

UCLASS(minimalapi)
class AIntruderMultiGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AIntruderMultiGameMode();

protected:
	// Called when placed or spawned into the world
	virtual void BeginPlay() override;
};



