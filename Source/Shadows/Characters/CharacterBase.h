// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "DataAssets/InventoryContainer.h"
#include "Components/SkeletalMeshComponent.h" 
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "CharacterBase.generated.h"


UCLASS()
class TEST1_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	/*Movement functions*/


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		virtual void MoveForward(float value);
	UFUNCTION()
		virtual void MoveRight(float value);
	UFUNCTION()
		virtual void Interact();
	void AttachToActor(AActor * actor, FName attachPoint);
	UPROPERTY(EditDefaultsOnly)
		class UInventoryContainer* inventory;
};
