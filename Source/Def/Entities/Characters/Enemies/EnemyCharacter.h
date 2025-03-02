// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Entities/Characters/DefCharacter.h"
#include "Logging/LogMacros.h"

#include "EnemyCharacter.generated.h"


struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateEnemy, Log, All);

UCLASS()
class AEnemyCharacter : public ADefCharacter
{
	GENERATED_BODY()

public:
	
	AEnemyCharacter();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;


	// Combat Interface
	virtual int32 GetCharacterLevel() const override;
	
protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	virtual void BeginPlay();

	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_Level)
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};

