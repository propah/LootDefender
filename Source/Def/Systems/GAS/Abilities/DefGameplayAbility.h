// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityInputID.h"
#include "Abilities/GameplayAbility.h"
#include "DefGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class DEF_API UDefGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UDefGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	EAbilityInputID InputID;
};
