// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.h"
#include "Engine/World.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TOPDOWNSHOOTER_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(BlueprintReadWrite)
		TSubclassOf <class AEnemyActor> Enemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void SpawnEnemy();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
