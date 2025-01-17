// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMCMaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class DEF_API UMMCMaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UMMCMaxHealth();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition StrengthDef;
};
