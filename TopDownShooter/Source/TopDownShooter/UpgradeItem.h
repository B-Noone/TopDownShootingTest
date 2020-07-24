// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TopDownShooterPawn.h"
#include "UpgradeItem.generated.h"

UCLASS()
class TOPDOWNSHOOTER_API AUpgradeItem : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AUpgradeItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Upgrade, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* UpgradeMesh;
	UFUNCTION(BlueprintCallable)
		void ApplyUpgrades(ATopDownShooterPawn* TargetPlayer, int UpgradeNum);
	UFUNCTION(BlueprintCallable)
		void SetRandVal(int NewRandVal);
	UFUNCTION(BlueprintCallable)
		int GetRandVal();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int RandVal;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* CollisionComp;

	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
