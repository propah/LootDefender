// Fill out your copyright notice in the Description page of Project Settings.


#include "LDWidgetController.h"

void ULDWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void ULDWidgetController::BroadcastInitialValues()
{
}

void ULDWidgetController::BindCallbacksToDependencies()
{
}
