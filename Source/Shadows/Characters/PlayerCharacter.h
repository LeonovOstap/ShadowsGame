// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "PlayerCharacter.generated.h"


/**
 * 
 */
UCLASS()
class TEST1_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()
		/** Camera boom positioning the camera behind the character */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
			class USpringArmComponent* CameraBoom;

		/** Follow camera */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
			class UCameraComponent* FollowCamera;
		public:
			APlayerCharacter();
			/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
			UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
				float BaseTurnRate;

			/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
			UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
				float BaseLookUpRate;

		protected:
			virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
			/**
			* Called via input to turn at a given rate.
			* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
			*/
			void TurnAtRate(float Rate);

			/**
			 * Called via input to turn look up/down at a given rate.
			 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
			 */
			void LookUpAtRate(float Rate);

		public:
			/** Returns CameraBoom subobject **/
				FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
			/** Returns FollowCamera subobject **/
				FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
