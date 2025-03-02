// Fill out your copyright notice in the Description page of Project Settings.


#include "DefWidgetController.h"

void UDefWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UDefWidgetController::BroadcastInitialValues()
{
}

void UDefWidgetController::BindCallbacksToDependencies()
{
}
