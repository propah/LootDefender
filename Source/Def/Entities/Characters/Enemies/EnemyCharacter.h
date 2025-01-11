// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/Characters/LDCharacter.h"
#include "Logging/LogMacros.h"

#include "EnemyCharacter.generated.h"


struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateEnemy, Log, All);

UCLASS()
class AEnemyCharacter : public ALDCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	virtual void BeginPlay();

	virtual void InitAbilityActorInfo() override;
};

