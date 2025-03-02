// Fill out your copyright notice in the Description page of Project Settings.


#include "MMCMaxMana.h"

#include "Systems/Combat/Interfaces/CombatInterface.h"
#include "Systems/GAS/AttributeSets/DefAttributeSet.h"

UMMCMaxMana::UMMCMaxMana()
{
	IntelligenceDef.AttributeToCapture = UDefAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMCMaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float IntelligenceMagnitude = 0.f;

	GetCapturedAttributeMagnitude(IntelligenceDef, Spec, EvaluationParameters, IntelligenceMagnitude);
	IntelligenceMagnitude = FMath::Max<float>(IntelligenceMagnitude, 0.f);

	const ICombatInterface* SourceObject = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 CharacterLevel = SourceObject->GetCharacterLevel();

	return 10 + IntelligenceMagnitude * 2.f + CharacterLevel * 2.f;
}
