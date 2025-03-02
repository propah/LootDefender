// Fill out your copyright notice in the Description page of Project Settings.


#include "DefAbilitySystemComponent.h"

void UDefAbilitySystemComponent::InitAbilityInfo()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UDefAbilitySystemComponent::EffectApplied);
}

void UDefAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
											  const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer Tags;
	GameplayEffectSpec.GetAllAssetTags(Tags);

	EffectAssetTagsDelegate.Broadcast(Tags);
}
