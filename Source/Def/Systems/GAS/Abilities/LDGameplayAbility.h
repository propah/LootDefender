// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityInputID.h"
#include "Abilities/GameplayAbility.h"
#include "LDGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class DEF_API ULDGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	ULDGameplayAbility();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
	EAbilityInputID InputID;
};
