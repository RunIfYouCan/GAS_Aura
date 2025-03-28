﻿// Copyright Valera & Co


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	AbilitySystemComponent->
		GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).
		AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->
		GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).
		AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->
		GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).
		AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->
		GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).
		AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	UAuraAbilitySystemComponent* AuraASC = Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent);
	AuraASC->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (!Tag.MatchesTag(MessageTag)) return;
				
				const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageTable, Tag);
				MessageWidgetRowDelegate.Broadcast(*Row);
			}
		}
	);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
