// Fill out your copyright notice in the Description page of Project Settings.


#include "ATile.h"

// Sets default values
AATile::AATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false ;

	// Create a static mesh component
	tileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	RootComponent = tileMesh;

	terrainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TerrainMesh"));
	terrainMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AATile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AATile::hasBuilding() const { return bBuilding; };

bool AATile::hasRoad() const { return bRoad; };

bool AATile::isTraversable() const { return bTraversable; };

bool AATile::isBuildable() const { return bBuildable; };

void AATile::build(){}

void AATile::demolish(){}

void AATile::buildRoad(){}

void AATile::demolishRoad(){}

