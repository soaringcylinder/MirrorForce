// Copyright Mirror Force

#include "AbilitySystem/MirrorAttributeSet.h"

UMirrorAttributeSet::UMirrorAttributeSet()
{
	InitHealth(3.0f);
	InitMaxHealth(3.0f);
}

void UMirrorAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max<float>(NewValue, 0.f);
	}
}


