// Copyright Valera & Co

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemyCharacter();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/* Combat Interface */
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Chracter Class Defaults")
	int32 Level = 1;
};
