// Copyright Mirror Force

#include "Actor/MirrorForceBulletBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/MirrorAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
AMirrorForceBulletBase::AMirrorForceBulletBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AMirrorForceBulletBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UMirrorAttributeSet* MirrorAttributeSet = Cast<UMirrorAttributeSet>(
			ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UMirrorAttributeSet::StaticClass()));

		UMirrorAttributeSet* MirrorAttributeSetNonConst = const_cast<UMirrorAttributeSet*>(MirrorAttributeSet);
		MirrorAttributeSetNonConst->SetHealth(MirrorAttributeSet->GetHealth() - 10);
	}
}

void AMirrorForceBulletBase::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void AMirrorForceBulletBase::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AMirrorForceBulletBase::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AMirrorForceBulletBase::EndOverlap);
}





