// Copyright Mirror Force


#include "UI/Widget/MirrorForceUserWidget.h"

void UMirrorForceUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
