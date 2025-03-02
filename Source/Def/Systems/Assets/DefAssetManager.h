// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "DefAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class DEF_API UDefAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UDefAssetManager* Get();

protected:
	virtual void StartInitialLoading() override;
};
