#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridLevel.h"	//Based on Millington's Maze alg
#include "SpawnTiles.generated.h"

UCLASS()
class TOPDOWNSHOOTER_API ASpawnTiles : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnTiles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = Tile)
		AGridLevel *grid;

	UPROPERTY(VisibleAnywhere, Category = Tile)
	FRandomStream RandomStream;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int CustomSeed;

	UFUNCTION(BlueprintCallable)
		FRandomStream GetSeed();

	UFUNCTION(BlueprintCallable)
		void SetSeed(int NewSeed);

	UFUNCTION(BlueprintCallable)
		void SpawnMap();

	// Tile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> floorTile;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class AGoal> goal;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> vertWall;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> horizWall;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> vertDoorWall;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> horizDoorWall;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> vertDoor;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> horizDoor;
	UPROPERTY(EditDefaultsOnly, Category = Tile)
		TSubclassOf<class ATile> boxCollider;
	//UPROPERTY(EditDefaultsOnly, Category = Tile)
	//	TSubclassOf<class ARoom> room;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		int seed;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		int numHorizTiles;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		int numVertTiles;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float xGap;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float yGap;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float xStart;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float yStart;
	UPROPERTY(EditAnywhere, Category = CreateTiles)
		float zStart;
	void spawnATile(TSubclassOf<class ATile> tileClass, float x, float y, float z);
	void spawnGoal(TSubclassOf<class AGoal> goal, float x, float y, float z);
};
