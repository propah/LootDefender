// Fill out your copyright notice in the Description page of Project Settings.


#include "MMCMaxHealth.h"

#include "Entities/Characters/LDCharacter.h"
#include "Systems/GAS/AttributeSets/LDAttributeSet.h"

UMMCMaxHealth::UMMCMaxHealth()
{
	StrengthDef.AttributeToCapture = ULDAttributeSet::GetStrengthAttribute();
	StrengthDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	StrengthDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(StrengthDef);
}

float UMMCMaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float StrengthMagnitude = 0.f;

	GetCapturedAttributeMagnitude(StrengthDef, Spec, EvaluationParameters, StrengthMagnitude);
	StrengthMagnitude = FMath::Max<float>(StrengthMagnitude, 0.f);

	const ICombatInterface* SourceObject = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 CharacterLevel = SourceObject->GetCharacterLevel();

	return StrengthMagnitude * 2.f + CharacterLevel * 10.f;
}
