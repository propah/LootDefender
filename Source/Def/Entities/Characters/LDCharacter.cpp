// Fill out your copyright notice in the Description page of Project Settings.


#include "LDCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

// Sets default values
ALDCharacter::ALDCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

UAbilitySystemComponent* ALDCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ALDCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ALDCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ALDCharacter::InitAbilityActorInfo()
{
}


void ALDCharacter::InitDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
}

void ALDCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffect, float Level) const
{
	check(GetAbilitySystemComponent());
	check(DefaultSecondaryAttributes);
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(
		GameplayEffect, Level, ContextHandle);
	if (SpecHandle.IsValid())
	{
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}
