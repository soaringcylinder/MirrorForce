// Copyright Epic Games, Inc. All Rights Reserved.

#include "MirrorForceGameMode.h"
#include "MirrorForcePlayerController.h"
#include "MirrorForceCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMirrorForceGameMode::AMirrorForceGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMirrorForcePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}