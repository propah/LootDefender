// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "Systems/GAS/LDAbilitySystemComponent.h"
#include "Systems/GAS/AttributeSets/LDAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const ULDAttributeSet* LDAttributeSet = CastChecked<ULDAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(LDAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(LDAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const ULDAttributeSet* LDAttributeSet = CastChecked<ULDAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(LDAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(LDAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	ULDAbilitySystemComponent* LDAbilitySystemComponent = Cast<ULDAbilitySystemComponent>(AbilitySystemComponent);
	
	LDAbilitySystemComponent->EffectAssetTagsDelegate.AddLambda([](const FGameplayTagContainer& AssetTags)
	{
		for (auto & Tag : AssetTags)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, FString::Printf(TEXT("Effect applied tag: %s"), *Tag.ToString()));


		}
	});
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& ChangeData) const
{
	OnHealthChanged.Broadcast(ChangeData.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& ChangeData) const
{
	OnMaxHealthChanged.Broadcast(ChangeData.NewValue);
}
