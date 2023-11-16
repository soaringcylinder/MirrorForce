// Copyright Mirror Force

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MirrorForceUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MIRRORFORCE_API UMirrorForceUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
