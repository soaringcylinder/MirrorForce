// Copyright Mirror Force

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MirrorAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class MIRRORFORCE_API UMirrorAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UMirrorAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "AttributeSet")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMirrorAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "AttributeSet")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMirrorAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "AttributeSet")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UMirrorAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, Category = "AttributeSet")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UMirrorAttributeSet, MaxMana);
};
