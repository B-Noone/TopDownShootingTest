// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

// Sets default values
AEnemyPawn::AEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EnemyMaxHealth = 100;
	EnemyHealth = EnemyMaxHealth;
}

// Called when the game starts or when spawned
void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyPawn::SetHealth(float NewHealth)
{
	EnemyHealth = NewHealth;
}

float AEnemyPawn::GetHealth()
{
	return EnemyHealth;
}

void AEnemyPawn::TakeDamage(float DamageValue)
{
	EnemyHealth -= DamageValue;
}

void AEnemyPawn::SetMaxHealth(float NewMaxHealth)
{
	EnemyMaxHealth = NewMaxHealth;
}

float AEnemyPawn::GetMaxHealth()
{
	return EnemyMaxHealth;
}

void AEnemyPawn::SetSpawnRoom(ATile* NewSpawnRoom)
{
	SpawnRoom = NewSpawnRoom;
}

ATile* AEnemyPawn::GetSpawnRoom()
{
	return SpawnRoom;
}