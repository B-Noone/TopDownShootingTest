// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DrawDebugHelpers.h"
#include "EnemyPawn.generated.h"

UCLASS()
class TOPDOWNSHOOTER_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float EnemyHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float EnemyMaxHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Tile)
		ATile* SpawnRoom;

	UFUNCTION(BlueprintCallable)
		void SetSpawnRoom(ATile* NewSpawnRoom);

	UFUNCTION(BlueprintCallable)
		ATile* GetSpawnRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void SetHealth(float NewHealth);
	UFUNCTION(BlueprintCallable)
		float GetHealth();
	UFUNCTION(BlueprintCallable)
		void TakeDamage(float DamageValue);
	UFUNCTION(BlueprintCallable)
		void SetMaxHealth(float NewMaxHealth);
	UFUNCTION(BlueprintCallable)
		float GetMaxHealth();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
