// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LDAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTagsDelegate, const FGameplayTagContainer&)

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEF_API ULDAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:

	void InitAbilityInfo();

	FEffectAssetTagsDelegate EffectAssetTagsDelegate;
	
protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);
};
