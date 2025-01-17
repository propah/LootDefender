// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerState.h"

#include "Net/UnrealNetwork.h"
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

void AMainPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerState, Level);
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AMainPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

int32 AMainPlayerState::GetCharacterLevel() const
{
	return Level;
}

void AMainPlayerState::SetCharacterLevel(int32 NewLevel)
{
	Level = NewLevel;
}

void AMainPlayerState::OnRep_Level(int32 OldLevel)
{
	
}
