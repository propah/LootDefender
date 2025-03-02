// Fill out your copyright notice in the Description page of Project Settings.


#include "DefAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

namespace
{
	FEffectProperties CreateEffectProperties(const FGameplayEffectModCallbackData& Data)
	{
		FEffectProperties EffectProperties;

		EffectProperties.EffectContextHandle = Data.EffectSpec.GetContext();
		EffectProperties.SourceAbilitySystemComponent = EffectProperties.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
		if (IsValid(EffectProperties.SourceAbilitySystemComponent) && EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo.IsValid() && EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.IsValid())
		{
			EffectProperties.SourceAvatarActor = EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.Get();
			EffectProperties.SourceController = EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get();
			if (EffectProperties.SourceController == nullptr && EffectProperties.SourceAvatarActor != nullptr)
			{
				if (const APawn* Pawn = Cast<APawn>(EffectProperties.SourceAvatarActor))
				{
					EffectProperties.SourceController = Pawn->GetController();
				}
			}
			if (EffectProperties.SourceController)
			{
				ACharacter* SourceCharacter = Cast<ACharacter>(EffectProperties.SourceController->GetPawn());
			}
		}
		if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
		{
			EffectProperties.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
			EffectProperties.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
			EffectProperties.TargetCharacter = Cast<ACharacter>(EffectProperties.TargetAvatarActor);
			EffectProperties.SourceAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(EffectProperties.TargetAvatarActor);
		}
		
		EffectProperties.TargetAbilitySystemComponent = &Data.Target;
		
		return EffectProperties;
	}
}

UDefAttributeSet::UDefAttributeSet()
{
	InitHealth(50.f);
	InitMana(10.f);
}

void UDefAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Core Stats (Critical, frequently updated, and need notifications)
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);

	// Critical Stats
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDefAttributeSet, CriticalDamage, COND_None, REPNOTIFY_Always);

	// Secondary Stats (Less frequently updated, no need for immediate notifications)
	DOREPLIFETIME(UDefAttributeSet, Strength);
	DOREPLIFETIME(UDefAttributeSet, Intelligence);
	DOREPLIFETIME(UDefAttributeSet, Dexterity);
	DOREPLIFETIME(UDefAttributeSet, Luck);

	// Elemental Stats
	DOREPLIFETIME(UDefAttributeSet, FireAffinity);
	DOREPLIFETIME(UDefAttributeSet, IceAffinity);
	DOREPLIFETIME(UDefAttributeSet, LightningAffinity);
	DOREPLIFETIME(UDefAttributeSet, VoidAffinity);

	// Utility/Defensive Stats
	DOREPLIFETIME(UDefAttributeSet, CooldownReduction);
	DOREPLIFETIME(UDefAttributeSet, HealthRegeneration);
	DOREPLIFETIME(UDefAttributeSet, ManaRegeneration);
}

void UDefAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxHealthAttribute())
	{
		SetHealth(FMath::Clamp(NewValue, 0.0f, GetMaxHealth()));
	}
}

void UDefAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
}

void UDefAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties EffectProperties = CreateEffectProperties(Data);
}

void UDefAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Health, OldValue);
}

void UDefAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, MaxHealth, OldValue);
}

void UDefAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Mana, OldValue);
}

void UDefAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, MaxMana, OldValue);
}

void UDefAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Strength, OldValue);
}

void UDefAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Intelligence, OldValue);
}

void UDefAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Dexterity, OldValue);
}

void UDefAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Luck, OldValue);
}

void UDefAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, AttackPower, OldValue);
}

void UDefAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Armor, OldValue);
}

void UDefAttributeSet::OnRep_ElementalResistance(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, ElementalResistance, OldValue);
}

void UDefAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, Speed, OldValue);
}

void UDefAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, AttackSpeed, OldValue);
}

void UDefAttributeSet::OnRep_CriticalChance(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, CriticalChance, OldValue);
}

void UDefAttributeSet::OnRep_CriticalDamage(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, CriticalDamage, OldValue);
}

void UDefAttributeSet::OnRep_FireAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, FireAffinity, OldValue);
}

void UDefAttributeSet::OnRep_IceAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, IceAffinity, OldValue);
}

void UDefAttributeSet::OnRep_LightningAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, LightningAffinity, OldValue);
}

void UDefAttributeSet::OnRep_VoidAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, VoidAffinity, OldValue);
}

void UDefAttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, CooldownReduction, OldValue);
}

void UDefAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, HealthRegeneration, OldValue);
}

void UDefAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UDefAttributeSet, ManaRegeneration, OldValue);
}
