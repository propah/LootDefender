// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerState.h"

#include "Net/UnrealNetwork.h"
#include "Systems/GAS/DefAbilitySystemComponent.h"
#include "Systems/GAS/AttributeSets/DefAttributeSet.h"

AMainPlayerState::AMainPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UDefAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UDefAttributeSet>("AttributeSet");
	
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
