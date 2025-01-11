// Fill out your copyright notice in the Description page of Project Settings.


#include "LDAbilitySystemComponent.h"

void ULDAbilitySystemComponent::InitAbilityInfo()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ULDAbilitySystemComponent::EffectApplied);
}

void ULDAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
											  const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer Tags;
	GameplayEffectSpec.GetAllAssetTags(Tags);

	EffectAssetTagsDelegate.Broadcast(Tags);
}
