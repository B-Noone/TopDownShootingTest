#include "SpawnTiles.h"
#include "Tile.h"
#include "Goal.h"

// Sets default values
ASpawnTiles::ASpawnTiles() {
	// Set this actor to call Tick() every frame.  	PrimaryActorTick.bCanEverTick = true;
	xGap = yGap = 2080.0f;
	xStart = yStart = zStart = 0.0f;
	numHorizTiles = numVertTiles = seed = 5;
	CustomSeed = 0;
	grid = CreateDefaultSubobject<AGridLevel>(TEXT("grid"));
}

// Called when the game starts or when spawned
void ASpawnTiles::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ASpawnTiles::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

FRandomStream ASpawnTiles::GetSeed()
{
	return RandomStream;
}

void ASpawnTiles::SetSeed(int NewSeed)
{
	seed = NewSeed;
}

void ASpawnTiles::SpawnMap()
{
	grid->initConnections(numHorizTiles, numVertTiles);
	TArray<FConnections> connections = grid->createGrid(seed, FVector2D(0, 0)); //start with seed, and init cell
	RandomStream.Initialize(seed);
	int goalPos = RandomStream.RandRange(numHorizTiles*numVertTiles / 2, numHorizTiles*numVertTiles - 1);
	for (int i = 0; i < connections.Num(); i++) {
		//	for (int i = 0; i < 1; i++) {
		int x = xStart + float(i % numHorizTiles)*xGap;
		int y = yStart + float(i / numHorizTiles)*yGap;
		if (i == goalPos) {
			spawnGoal(goal, x, y, zStart);
			continue; //get out of loop, but carry on
		}
		spawnATile(floorTile, x, y, zStart);
		if (i > 0) {
			spawnATile(boxCollider, x, y, zStart);
		}
		for (int j = 0; j < 4; j++) {
			int dx = grid->NEIGHBOURS[j].dx;
			int dy = grid->NEIGHBOURS[j].dy;
			int idx = grid->NEIGHBOURS[j].index;
			if (connections[i].directions[j] != 1) {
				if (dx != 0)
					spawnATile(vertWall, x + (float)dx*(xGap + 2.0f) / 2.0f, y, zStart);
				else
					spawnATile(horizWall, x, y + (float)dy*(yGap + 2.0f) / 2.0f, zStart);
			}
			else if (dx != 0) {
				spawnATile(vertDoorWall, x + (float)dx*(xGap + 2.0f) / 2.0f, y, zStart);
				//spawnATile(vertDoor, x + (float)dx*(xGap + 2.0f) / 2.0f, y, zStart);
			}
			else {
				spawnATile(horizDoorWall, x, y + (float)dy*(xGap + 2.0f) / 2.0f, zStart);
				//spawnATile(horizDoor, x, y + (float)dy*(xGap + 2.0f) / 2.0f, zStart);
			}
		}
	}
}

void ASpawnTiles::spawnATile(TSubclassOf<class ATile> tileClass, float x, float y, float z) {
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	FVector spawnLoc = FVector(x, y, z);
	FRotator rot = FRotator::ZeroRotator;
	AActor* a = GetWorld()->SpawnActor<ATile>(tileClass, spawnLoc, rot, spawnParams);
}

void ASpawnTiles::spawnGoal(TSubclassOf<class AGoal> goal, float x, float y, float z) {
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	FVector spawnLoc = FVector(x, y, z);
	FRotator rot = FRotator::ZeroRotator;
	AActor* a = GetWorld()->SpawnActor<AGoal>(goal, spawnLoc, rot, spawnParams);
}
