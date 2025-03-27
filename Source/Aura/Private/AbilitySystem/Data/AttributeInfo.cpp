// Copyright Valera & Co


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag,
	const bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributesInformation)
	{
		if (Info.AttributeTag == AttributeTag)
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find attribute info for %s"), *AttributeTag.ToString());
	}
	return FAuraAttributeInfo();
}
