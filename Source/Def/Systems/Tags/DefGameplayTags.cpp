// Fill out your copyright notice in the Description page of Project Settings.


#include "DefGameplayTags.h"
#include "GameplayTagsManager.h"

FDefGameplayTags FDefGameplayTags::Tags;

void FDefGameplayTags::InitializeTags()
{
	// ===============================================
	// Primary Stats
	// ===============================================
	Tags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Strength attribute, enhances physical power"));

	Tags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Intelligence attribute, enhances magical power and mana"));

	Tags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Dexterity"),
		FString("Dexterity attribute, influences speed and critical damage"));

	Tags.Attributes_Primary_Luck = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Luck"),
		FString("Luck attribute, affects chance-based stats"));

	// ===============================================
	// Secondary Stats (Driven by Primary Stats)
	// ===============================================
	// -- Strength Driven --
	Tags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HealthRegeneration"),
		FString("Health regeneration driven by strength"));

	Tags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("Maximum health driven by strength"));

	Tags.Attributes_Secondary_AttackPower = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.AttackPower"),
		FString("Attack power driven by strength"));

	// -- Intelligence Driven --
	Tags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ManaRegeneration"),
		FString("Mana regeneration driven by intelligence"));

	Tags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("Maximum mana driven by intelligence"));

	Tags.Attributes_Secondary_CooldownReduction = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CooldownReduction"),
		FString("Cooldown reduction driven by intelligence"));

	// -- Luck Driven --
	Tags.Attributes_Secondary_CriticalChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalChance"),
		FString("Critical chance driven by luck"));

	// -- Dexterity Driven --
	Tags.Attributes_Secondary_CriticalDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalDamage"),
		FString("Critical damage driven by dexterity"));

	Tags.Attributes_Secondary_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Speed"),
		FString("Speed attribute driven by dexterity"));

	Tags.Attributes_Secondary_AttackSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.AttackSpeed"),
		FString("Attack speed driven by dexterity"));

	// ===============================================
	// Defensive Stats
	// ===============================================
	Tags.Attributes_Core_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Core.Armor"),
		FString("Reduces physical damage taken"));

	Tags.Attributes_Core_ElementalResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Core.ElementalResistance"),
		FString("Reduces elemental damage taken"));

	// ===============================================
	// Elemental Stats
	// ===============================================
	Tags.Attributes_Elemental_FireAffinity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Elemental.FireAffinity"),
		FString("Affinity for fire elements"));

	Tags.Attributes_Elemental_IceAffinity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Elemental.IceAffinity"),
		FString("Affinity for ice elements"));

	Tags.Attributes_Elemental_LightningAffinity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Elemental.LightningAffinity"),
		FString("Affinity for lightning elements"));

	Tags.Attributes_Elemental_VoidAffinity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Elemental.VoidAffinity"),
		FString("Affinity for void elements"));

	// ===============================================
	// Resource Stats
	// ===============================================
	Tags.Attributes_Core_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Core.Health"),
		FString("Current health resource"));

	Tags.Attributes_Core_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Core.Mana"),
		FString("Current mana resource"));
}
