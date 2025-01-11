// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)  
enum class EEnemyBaseState : uint8
{  
	Walking			UMETA(DisplayName = "Walking"),  
	Chasing			UMETA(DisplayName = "Chasing"),
	Attacking		UMETA(DisplayName = "Attacking")
};