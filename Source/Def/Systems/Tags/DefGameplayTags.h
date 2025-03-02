// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FDefGameplayTags
{
public:
	static const FDefGameplayTags & Get() { return Tags; };
	static void InitializeTags();

	
private:
	static FDefGameplayTags Tags;

	// ===============================================
	// Primary Stats
	// ===============================================
	
	// Strength stat gameplay tag.
	FGameplayTag Attributes_Primary_Strength;
	// Intelligence stat gameplay tag.
	FGameplayTag Attributes_Primary_Intelligence;
	// Dexterity stat gameplay tag.
	FGameplayTag Attributes_Primary_Dexterity;
	// Luck stat gameplay tag.
	FGameplayTag Attributes_Primary_Luck;

	// ===============================================
	// Secondary Stats (Modified by Primary Stats)
	// ===============================================
	
	// -- Strength Driven --
	// Health Regeneration stat gameplay tag.
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	// Max Health stat gameplay tag.
	FGameplayTag Attributes_Secondary_MaxHealth;
	// Attack Power stat gameplay tag.
	FGameplayTag Attributes_Secondary_AttackPower;
	
	// -- Intelligence Driven --
	// Mana Regeneration stat gameplay tag.
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	// Max Mana stat gameplay tag.
	FGameplayTag Attributes_Secondary_MaxMana;
	// Cooldown Reduction stat gameplay tag.
	FGameplayTag Attributes_Secondary_CooldownReduction;
	
	// -- Luck Driven --
	// Critical Chance stat gameplay tag.
	FGameplayTag Attributes_Secondary_CriticalChance;
	
	// -- Dexterity Driven --
	// Critical Damage stat gameplay tag.
	FGameplayTag Attributes_Secondary_CriticalDamage;
	// Speed stat gameplay tag.
	FGameplayTag Attributes_Secondary_Speed;
	// Attack Speed stat gameplay tag.
	FGameplayTag Attributes_Secondary_AttackSpeed;

	// ===============================================
	// Defensive Stats
	// ===============================================
	
	// Armor gameplay tag.
	FGameplayTag Attributes_Core_Armor;
	// Elemental Resistance gameplay tag.
	FGameplayTag Attributes_Core_ElementalResistance;

	// ===============================================
	// Elemental Stats
	// ===============================================
	
	// Fire Affinity gameplay tag.
	FGameplayTag Attributes_Elemental_FireAffinity;
	// Ice Affinity gameplay tag.
	FGameplayTag Attributes_Elemental_IceAffinity;
	// Lightning Affinity gameplay tag.
	FGameplayTag Attributes_Elemental_LightningAffinity;
	// Void Affinity gameplay tag.
	FGameplayTag Attributes_Elemental_VoidAffinity;

	// ===============================================
	// Resource Stats
	// ===============================================
	
	// Health (resource) gameplay tag.
	FGameplayTag Attributes_Core_Health;
	// Mana (resource) gameplay tag.
	FGameplayTag Attributes_Core_Mana;

};