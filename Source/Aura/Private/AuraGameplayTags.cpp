// Copyright Valera & Co


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
    UGameplayTagsManager& GameplayTagsManager = UGameplayTagsManager::Get();

    // Primary Attributes
    GameplayTags.Attributes_Primary_Strength = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Primary.Strength"),
        FString("Increases physical damage and critical hit chance")
    );

    GameplayTags.Attributes_Primary_Intelligence = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Primary.Intelligence"),
        FString("Increases magical damage and mana pool")
    );

    GameplayTags.Attributes_Primary_Resilience = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Primary.Resilience"),
        FString("Increases Armor and Armor Penetration")
    );

    GameplayTags.Attributes_Primary_Vigor = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Primary.Vigor"),
        FString("Increases Health and Health Regeneration")
    );

    // Secondary Attributes
    GameplayTags.Attributes_Secondary_Armor = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.Armor"),
        FString("Reduces damage taken, improves block chance")
    );

    GameplayTags.Attributes_Secondary_ArmorPenetration = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.ArmorPenetration"),
        FString("Ignores percentage of enemy Armor")
    );

    GameplayTags.Attributes_Secondary_BlockChance = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.BlockChance"),
        FString("Chance to block incoming damage")
    );

    GameplayTags.Attributes_Secondary_CriticalHitChance = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.CriticalHitChance"),
        FString("Chance to deal critical hit")
    );

    GameplayTags.Attributes_Secondary_CriticalHitDamage = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.CriticalHitDamage"),
        FString("Multiplier for critical hit damage")
    );

    GameplayTags.Attributes_Secondary_CriticalHitResistance = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.CriticalHitResistance"),
        FString("Reduces critical hit chance of attacking enemies")
    );

    GameplayTags.Attributes_Secondary_HealthRegen = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.HealthRegen"),
        FString("Amount of Health regenerated per second")
    );

    GameplayTags.Attributes_Secondary_ManaRegen = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.ManaRegen"),
        FString("Amount of Mana regenerated per second")
    );

    GameplayTags.Attributes_Secondary_MaxHealth = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.MaxHealth"),
        FString("Maximum amount of Health obtainable")
    );

    GameplayTags.Attributes_Secondary_MaxMana = GameplayTagsManager.AddNativeGameplayTag(
        FName("Attributes.Secondary.MaxMana"),
        FString("Maximum amount of Mana obtainable")
    );
}
