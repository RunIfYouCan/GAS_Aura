// Copyright Valera & Co


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer Tags;
	Spec.GetAllAssetTags(Tags);

	EffectAssetTags.Broadcast(Tags);
}
