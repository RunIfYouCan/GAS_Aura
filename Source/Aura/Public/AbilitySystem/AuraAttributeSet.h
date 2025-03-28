// Copyright Valera & Co

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FGameplayEffectModCallbackData;

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){};

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatar = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;
	
	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;
	
	UPROPERTY()
	AActor* TargetAvatar = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

// Unreal engine guideline says you should use a type for prefix in typedefs
// In this case we use F, instead of T from TBaseStatis..., because it's not a template anymore
// It's a pointer to a function the returns Struct(F).
// Note: TBaseStatic... can be replaced with FGameplayAttribute(*)();
using FAttrFuncPointer = TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen) const;

	UFUNCTION()
	void OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen) const;
	
	// Is a function pointer to a function that returns a FGameplayAttribute
	// Used to map a GameplayTag to an attribute
	// TMap<FGameplayTag, FAttrFuncPointer> TagsToAttribute;
	TMap<FGameplayTag, FGameplayAttribute> TagsToAttribute;

	/* Primary Attributes */
	UPROPERTY(ReplicatedUsing=OnRep_Strength, BlueprintReadOnly, Category="Attributes|Primary")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);
	
	UPROPERTY(ReplicatedUsing=OnRep_Intelligence, BlueprintReadOnly, Category="Attributes|Primary")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);
	
	UPROPERTY(ReplicatedUsing=OnRep_Resilience, BlueprintReadOnly, Category="Attributes|Primary")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);
	
	UPROPERTY(ReplicatedUsing=OnRep_Vigor, BlueprintReadOnly, Category="Attributes|Primary")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);
	/* Primary Attributes */

	/* Vital Attributes */
	UPROPERTY(ReplicatedUsing=OnRep_Health, BlueprintReadOnly, Category="Attributes|Vitals")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	
	UPROPERTY(ReplicatedUsing=OnRep_MaxHealth, BlueprintReadOnly, Category="Attributes|Vitals")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UPROPERTY(ReplicatedUsing=OnRep_Mana, BlueprintReadOnly, Category="Attributes|Vitals")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	UPROPERTY(ReplicatedUsing=OnRep_MaxMana, BlueprintReadOnly, Category="Attributes|Vitals")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);
	/* Vital Attributes */

	/* Secondary Attributes */
	UPROPERTY(ReplicatedUsing=OnRep_Armor, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	UPROPERTY(ReplicatedUsing=OnRep_ArmorPenetration, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration);

	UPROPERTY(ReplicatedUsing=OnRep_BlockChance, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	UPROPERTY(ReplicatedUsing=OnRep_CriticalHitChance, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance);

	UPROPERTY(ReplicatedUsing=OnRep_CriticalHitDamage, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage);

	UPROPERTY(ReplicatedUsing=OnRep_CriticalHitResistance, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance);

	UPROPERTY(ReplicatedUsing=OnRep_HealthRegen, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegen);

	UPROPERTY(ReplicatedUsing=OnRep_ManaRegen, BlueprintReadOnly, Category="Attributes|Secondary")
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegen);
	/* Secondary Attributes */
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& OutProps) const;
};
