// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EnemyMaxHealth = 100;
	EnemyHealth = EnemyMaxHealth;
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyActor::SetHealth(float NewHealth)
{
	EnemyHealth = NewHealth;
}

float AEnemyActor::GetHealth()
{
	return EnemyHealth;
}

void AEnemyActor::TakeDamage(float DamageValue)
{
	EnemyHealth -= DamageValue;
}

void AEnemyActor::SetMaxHealth(float NewMaxHealth)
{
	EnemyMaxHealth = NewMaxHealth;
}

float AEnemyActor::GetMaxHealth()
{
	return EnemyMaxHealth;
}

void AEnemyActor::SetSpawnRoom(ATile* NewSpawnRoom)
{
	SpawnRoom = NewSpawnRoom;
}

ATile* AEnemyActor::GetSpawnRoom()
{
	return SpawnRoom;
}