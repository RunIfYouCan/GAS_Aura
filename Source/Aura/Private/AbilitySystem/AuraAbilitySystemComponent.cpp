// Copyright Valera & Co


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle ActiveHandle)
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		8.f,
		FColor::Red,
		FString::Printf(TEXT("Effect Applied: %s"), *Spec.Def->GetName())
	);
}
