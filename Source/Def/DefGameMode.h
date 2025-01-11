// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DefGameMode.generated.h"

UCLASS(minimalapi)
class ADefGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	ADefGameMode();

protected:

	virtual void BeginPlay() override;
};



