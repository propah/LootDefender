// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerState.h"

#include "Systems/GAS/LDAbilitySystemComponent.h"
#include "Systems/GAS/AttributeSets/LDAttributeSet.h"

AMainPlayerState::AMainPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<ULDAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<ULDAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 60.f;
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AMainPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
