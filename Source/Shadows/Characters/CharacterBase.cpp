// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Engine/Engine.h"
#include "Containers/Array.h"
#include "Components/InteractableComponent.h"
// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::MoveForward(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void ACharacterBase::MoveRight(float value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}
void ACharacterBase::Interact() 
{
	TArray<AActor*> overlappingActors;
	GetCapsuleComponent()->GetOverlappingActors(overlappingActors);
	for (AActor* actor : overlappingActors)
	{
		UActorComponent* acomp = actor->GetComponentByClass(UInteractableComponent::StaticClass());
		UInteractableComponent* comp = Cast<UInteractableComponent>(acomp);
		comp->Interact(this);
		break;
	}
}
void ACharacterBase::AttachToActor(AActor* actor,FName attachPoint)
{
	actor->SetActorTransform(GetMesh()->GetSocketTransform(attachPoint));
	actor->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, attachPoint);
}
