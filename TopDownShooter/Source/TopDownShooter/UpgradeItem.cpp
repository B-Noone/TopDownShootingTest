// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeItem.h"
#include "Components/BoxComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "TopDownShooterPawn.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AUpgradeItem::AUpgradeItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> UpgradeMeshAsset(TEXT("/Game/StaticMeshCube.StaticMeshCube"));

	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	CollisionComp->SetSimulatePhysics(true);
	CollisionComp->SetNotifyRigidBodyCollision(true);
	CollisionComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	CollisionComp->OnComponentHit.AddDynamic(this, &AUpgradeItem::OnCompHit);

	RootComponent = CollisionComp;

	UpgradeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UpgradeMesh0"));
	UpgradeMesh->SetStaticMesh(UpgradeMeshAsset.Object);
	UpgradeMesh->SetupAttachment(RootComponent);

	//UpgradeMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AUpgradeItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUpgradeItem::ApplyUpgrades(ATopDownShooterPawn* TargetPlayer, int UpgradeNum)
{
	if (UpgradeNum == 0) {
		TargetPlayer->SetMoveSpeed(TargetPlayer->GetMoveSpeed() + 50.0f);
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Move Speed: %f"), TargetPlayer->GetMoveSpeed()));
		}
	}
	else if(UpgradeNum == 1){
		TargetPlayer->SetFireRate(TargetPlayer->GetFireRate() - 0.10);
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Fire Rate: %f"), TargetPlayer->GetFireRate()));
			if (TargetPlayer->GetFireRate() <= 0.01f) {
				TargetPlayer->SetFireRate(0.01);
			}
		}
	}
	else if (UpgradeNum == 2) {
		TargetPlayer->SetDamage(TargetPlayer->GetDamage() + 10.0f);
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Damage: %f"), TargetPlayer->GetDamage()));
		}
	}
	else {
		TargetPlayer->SetCurrentMaxHealth(TargetPlayer->GetCurrentMaxHealth() + 10.0f);
		TargetPlayer->SetCurrentHealth(TargetPlayer->GetCurrentMaxHealth());
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Health: %f"), TargetPlayer->GetCurrentHealth()));
		}
	}
}

void AUpgradeItem::SetRandVal(int NewRandVal)
{
	RandVal = NewRandVal;
}

int AUpgradeItem::GetRandVal()
{
	return RandVal;
}

// Called every frame
void AUpgradeItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUpgradeItem::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ATopDownShooterPawn* PlayerClass; 
	PlayerClass = Cast<ATopDownShooterPawn>(OtherActor);
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && (PlayerClass != NULL))
	{
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
		}
		ApplyUpgrades(PlayerClass, RandVal);
		Destroy();
	}
}