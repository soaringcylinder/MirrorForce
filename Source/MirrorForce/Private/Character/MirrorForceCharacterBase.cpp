// Copyright Mirror Force

#include "Character/MirrorForceCharacterBase.h"


AMirrorForceCharacterBase::AMirrorForceCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AMirrorForceCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
