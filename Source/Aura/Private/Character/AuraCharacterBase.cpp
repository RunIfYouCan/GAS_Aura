// Copyright Valera & Co


#include "Character/AuraCharacterBase.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::InitializePrimaryAttributes()
{
	check(DefaultPrimaryAttributes);
	check(IsValid(GetAbilitySystemComponent()));
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(
		DefaultPrimaryAttributes,
		1,
		ContextHandle
	);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(
		*SpecHandle.Data,
		GetAbilitySystemComponent()
	);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}
