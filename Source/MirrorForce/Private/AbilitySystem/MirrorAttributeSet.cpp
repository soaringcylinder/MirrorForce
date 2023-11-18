// Copyright Mirror Force

#include "AbilitySystem/MirrorAttributeSet.h"

UMirrorAttributeSet::UMirrorAttributeSet()
{
	InitHealth(3.0f);
	InitMaxHealth(3.0f);
}

void UMirrorAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max<float>(NewValue, 0.f);
	}
}
