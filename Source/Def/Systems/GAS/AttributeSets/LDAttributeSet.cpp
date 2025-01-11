// Fill out your copyright notice in the Description page of Project Settings.


#include "LDAttributeSet.h"

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

ULDAttributeSet::ULDAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(10.f);
	InitMaxMana(100.f);
}

void ULDAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Core Stats (Critical, frequently updated, and need notifications)
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);

	// Critical Stats
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULDAttributeSet, CriticalDamage, COND_None, REPNOTIFY_Always);

	// Secondary Stats (Less frequently updated, no need for immediate notifications)
	DOREPLIFETIME(ULDAttributeSet, Strength);
	DOREPLIFETIME(ULDAttributeSet, Intelligence);
	DOREPLIFETIME(ULDAttributeSet, Dexterity);
	DOREPLIFETIME(ULDAttributeSet, Luck);

	// Elemental Stats
	DOREPLIFETIME(ULDAttributeSet, FireAffinity);
	DOREPLIFETIME(ULDAttributeSet, IceAffinity);
	DOREPLIFETIME(ULDAttributeSet, LightningAffinity);
	DOREPLIFETIME(ULDAttributeSet, VoidAffinity);

	// Utility/Defensive Stats
	DOREPLIFETIME(ULDAttributeSet, CooldownReduction);
	DOREPLIFETIME(ULDAttributeSet, HealthRegeneration);
	DOREPLIFETIME(ULDAttributeSet, ManaRegeneration);
}

void ULDAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxHealthAttribute())
	{
		SetHealth(FMath::Clamp(NewValue, 0.0f, GetMaxHealth()));
	}
}

void ULDAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
}

void ULDAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties EffectProperties = CreateEffectProperties(Data);
}

void ULDAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Health, OldValue);
}

void ULDAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, MaxHealth, OldValue);
}

void ULDAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Mana, OldValue);
}

void ULDAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, MaxMana, OldValue);
}

void ULDAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Strength, OldValue);
}

void ULDAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Intelligence, OldValue);
}

void ULDAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Dexterity, OldValue);
}

void ULDAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Luck, OldValue);
}

void ULDAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, AttackPower, OldValue);
}

void ULDAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Armor, OldValue);
}

void ULDAttributeSet::OnRep_ElementalResistance(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, ElementalResistance, OldValue);
}

void ULDAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, Speed, OldValue);
}

void ULDAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, AttackSpeed, OldValue);
}

void ULDAttributeSet::OnRep_CriticalChance(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, CriticalChance, OldValue);
}

void ULDAttributeSet::OnRep_CriticalDamage(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, CriticalDamage, OldValue);
}

void ULDAttributeSet::OnRep_FireAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, FireAffinity, OldValue);
}

void ULDAttributeSet::OnRep_IceAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, IceAffinity, OldValue);
}

void ULDAttributeSet::OnRep_LightningAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, LightningAffinity, OldValue);
}

void ULDAttributeSet::OnRep_VoidAffinity(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, VoidAffinity, OldValue);
}

void ULDAttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, CooldownReduction, OldValue);
}

void ULDAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, HealthRegeneration, OldValue);
}

void ULDAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldValue)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ULDAttributeSet, ManaRegeneration, OldValue);
}
