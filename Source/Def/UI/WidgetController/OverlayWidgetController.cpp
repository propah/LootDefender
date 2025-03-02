// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayWidgetController.h"

#include "Systems/GAS/DefAbilitySystemComponent.h"
#include "Systems/GAS/AttributeSets/DefAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDefAttributeSet* LDAttributeSet = CastChecked<UDefAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(LDAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(LDAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UDefAttributeSet* LDAttributeSet = CastChecked<UDefAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(LDAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(LDAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	UDefAbilitySystemComponent* LDAbilitySystemComponent = Cast<UDefAbilitySystemComponent>(AbilitySystemComponent);
	
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
