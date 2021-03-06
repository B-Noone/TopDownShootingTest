// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TopDownShooterPawn.generated.h"

UCLASS(Blueprintable)
class ATopDownShooterPawn : public APawn
{
	GENERATED_BODY()

	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* ShipMeshComponent;

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ATopDownShooterProjectile> BulletClass;

public:
	ATopDownShooterPawn();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite )
	FVector GunOffset;
	
	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int PlayerScore;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float PlayerCurrentHealth;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float PlayerCurrentMaxHealth;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float PlayerDamage;

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	/* Fire a shot in the specified direction */
	void FireShot(FVector FireDirection);

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();
	UFUNCTION(BlueprintCallable)
		void SetCurrentMaxHealth(float NewHealth);
	UFUNCTION(BlueprintCallable)
		float GetCurrentMaxHealth();
	UFUNCTION(BlueprintCallable)
		void SetCurrentHealth(float NewHealth);
	UFUNCTION(BlueprintCallable)
		float GetCurrentHealth();
	UFUNCTION(BlueprintCallable)
		float GetFireRate();
	UFUNCTION(BlueprintCallable)
		void SetFireRate(float NewFireRate);
	UFUNCTION(BlueprintCallable)
		float GetMoveSpeed();
	UFUNCTION(BlueprintCallable)
		void SetMoveSpeed(float NewSpeed);
	UFUNCTION(BlueprintCallable)
		float GetDamage();
	UFUNCTION(BlueprintCallable)
		void SetDamage(float NewDamage);

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
	static const FName FireForwardBinding;
	static const FName FireRightBinding;

private:

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

public:
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return ShipMeshComponent; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};

