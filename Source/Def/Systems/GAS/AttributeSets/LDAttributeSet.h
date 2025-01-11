﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"


#include "LDAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* TargetAbilitySystemComponent = nullptr;
	
	UPROPERTY()
	UAbilitySystemComponent* SourceAbilitySystemComponent = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
	
	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;
};

UCLASS()
class DEF_API ULDAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	ULDAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	// Primary Stats

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Luck, Category = "Attributes|Luck")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Luck);
	
	// Secondary Stats
	// Stats that are increased by primary Stats (% based)

	// Strength
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Attributes|Secondary")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, HealthRegeneration);
	
	// Strength
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes|Secondary")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, MaxHealth);

	// Strength
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackPower, Category = "Attributes|Core")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, AttackPower);

	// Intelligence
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Attributes|Secondary")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, ManaRegeneration);
	
	// Intelligence
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Attributes|Secondary")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, MaxMana);

	// Intelligence
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CooldownReduction, Category = "Attributes|Secondary")
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, CooldownReduction);

	// Luck
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalChance, Category = "Attributes|Secondary")
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, CriticalChance);

	// Dexterity
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalDamage, Category = "Attributes|Secondary")
	FGameplayAttributeData CriticalDamage;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, CriticalDamage);

	// Dexterity
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed, Category = "Attributes|Secondary")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Speed);

	// Dexterity
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackSpeed, Category = "Attributes|Secondary")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, AttackSpeed);

	// Defensive Stats

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Attributes|Core")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ElementalResistance, Category = "Attributes|Core")
	FGameplayAttributeData ElementalResistance;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, ElementalResistance);


	// Elemental Stats
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FireAffinity, Category = "Attributes|Elemental")
	FGameplayAttributeData FireAffinity;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, FireAffinity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_IceAffinity, Category = "Attributes|Elemental")
	FGameplayAttributeData IceAffinity;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, IceAffinity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_LightningAffinity, Category = "Attributes|Elemental")
	FGameplayAttributeData LightningAffinity;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, LightningAffinity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VoidAffinity, Category = "Attributes|Elemental")
	FGameplayAttributeData VoidAffinity;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, VoidAffinity);
	
	// Resource Stats
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes|Core")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Attributes|Core")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(ULDAttributeSet, Mana);

	// Replication Notifications
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Strength(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Intelligence(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Dexterity(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_Luck(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackPower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Armor(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ElementalResistance(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_CriticalChance(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_CriticalDamage(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FireAffinity(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_IceAffinity(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_LightningAffinity(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_VoidAffinity(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_CooldownReduction(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_HealthRegeneration(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	virtual void OnRep_ManaRegeneration(const FGameplayAttributeData& OldValue);

};

