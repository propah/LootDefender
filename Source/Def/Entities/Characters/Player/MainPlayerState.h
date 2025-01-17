// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "Systems/Combat/Interfaces/CombatInterface.h"
#include "MainPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class DEF_API AMainPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMainPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent * GetAbilitySystemComponent() const override;
	virtual UAttributeSet * GetAttributeSet() const;
	
	int32 GetCharacterLevel() const;
	void SetCharacterLevel(int32 NewLevel);

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

private:

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
