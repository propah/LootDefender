// Copyright Epic Games, Inc. All Rights Reserved.

#include "DefGameMode.h"

#include "GameFramework/PlayerState.h"
#include "UObject/ConstructorHelpers.h"

ADefGameMode::ADefGameMode()
{
	/*// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/Player/BP_Player"));
	static ConstructorHelpers::FClassFinder<APlayerState> PlayerStateBPClass(TEXT("/Game/Blueprints/Characters/Player/BP_MainPlayerState"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	check(PlayerStateBPClass.Class)
	PlayerStateClass = PlayerStateBPClass.Class;*/
}

void ADefGameMode::BeginPlay()
{
	Super::BeginPlay();
}
