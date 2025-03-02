// Fill out your copyright notice in the Description page of Project Settings.


#include "DefAssetManager.h"

#include "Systems/Tags/DefGameplayTags.h"

UDefAssetManager* UDefAssetManager::Get()
{
	return Cast<UDefAssetManager>(GEngine->AssetManager);
}

void UDefAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FDefGameplayTags::InitializeTags();
}
