// Copyright Mirror Force


#include "UI/WidgetController/OverlayWidgetController.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	if (const UMirrorAttributeSet* MirrorAttributeSet = Cast<UMirrorAttributeSet>(AttributeSet))
	{
		OnHealthChanged.Broadcast(MirrorAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(MirrorAttributeSet->GetMaxHealth());
	}
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UMirrorAttributeSet* MirrorAttributeSet = CastChecked<UMirrorAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MirrorAttributeSet->GetHealthAttribute()).AddUObject(
		this, &UOverlayWidgetController::HealthChangedCallback);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(MirrorAttributeSet->GetMaxHealthAttribute()).AddUObject(
	 	this, &UOverlayWidgetController::MaxHealthChangedCallback);
}

void UOverlayWidgetController::HealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
