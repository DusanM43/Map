// Fill out your copyright notice in the Description page of Project Settings.


#include "AMap.h"

// Sets default values
AAMap::AAMap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AAMap::BeginPlay()
{
	Super::BeginPlay();



	CreateMap(20, 10);
}

// Called every frame
void AAMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAMap::GenerateMap(int sizeW, int sizeH)
{
}

void AAMap::CreateMap(int sizeW, int sizeH)
{
	// Distance from parallel edges of the hexagon
	float d = tileRadius * sqrt(3);

	float tileOffsetX = d / 2;

	for (int i = 0; i < sizeW; i++)
		for (int j = 0; j < sizeH; j++)
		{

			FVector location;
			FRotator rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			if (j % 2 == 0)
				location = FVector((i *d) * 100, (j * 3. * tileRadius / 2.) * 100, 0.);
			else
				location = FVector((i *d + tileOffsetX) * 100, (j * 3. * tileRadius / 2.) * 100, 0.);
			UWorld* const World = GetWorld();

			if (World && plainTerrain1 != NULL && (i + j) % 5 == 0)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				World->SpawnActor<AATile>(plainTerrain1, location, rotation);
			}

			else if (World && plainTerrain2 != NULL && (i + j) % 5 == 1)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				World->SpawnActor<AATile>(plainTerrain2, location, rotation);
			}
			else if (World && plainTerrain3 != NULL && (i + j) % 5 == 2)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				World->SpawnActor<AATile>(plainTerrain3, location, rotation);
			}
			else if (World && plainTerrain4 != NULL && (i + j) % 5 == 3)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				World->SpawnActor<AATile>(plainTerrain4, location, rotation);
			}
			else if (World && plainTerrain5 != NULL && (i + j) % 5 == 4)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				World->SpawnActor<AATile>(plainTerrain5, location, rotation);
			}

		}
}

AAMap::~AAMap() {
}
