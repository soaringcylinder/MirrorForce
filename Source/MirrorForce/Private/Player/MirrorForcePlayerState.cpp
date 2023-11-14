// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/MirrorForcePlayerState.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"


AMirrorForcePlayerState::AMirrorForcePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UAttributeSet>(TEXT("AttributeSet"));
	
}

UAbilitySystemComponent* AMirrorForcePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
