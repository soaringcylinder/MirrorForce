// Copyright Mirror Force

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MirrorForceBulletBase.generated.h"

class USphereComponent;

UCLASS()
class MIRRORFORCE_API AMirrorForceBulletBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMirrorForceBulletBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Applied Effect")
	void ApplyEffectToTargetActor(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
};

