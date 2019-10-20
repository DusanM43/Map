// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralMap.h"
#include <random>
#include <algorithm>
#include <vector>

// Sets default values
AProceduralMap::AProceduralMap() : continents(3)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CustomMesh");
	SetRootComponent(CustomMesh);
	CustomMesh->bUseAsyncCooking = true;
}

// Called when the game starts or when spawned
void AProceduralMap::BeginPlay()
{
	Super::BeginPlay();
	GenerateCubeMesh();
}

// Called every frame
void AProceduralMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool inRange(std::vector<FVector> vecs, FVector loc, float range) {
	for (int i = 0; i < vecs.size(); i++)
		if ((loc - vecs[i]).Size() < range) return true;
	return false;
}

void AProceduralMap::AddTriangle(int32 V1, int32 V2, int32 V3)
{
	Triangles.Add(V1);
	Triangles.Add(V2);
	Triangles.Add(V3);
}


void AProceduralMap::GenerateCubeMesh()
{
	std::random_device rd1; // obtain a random number from hardware
	std::mt19937 eng(rd1()); // seed the generator
	std::uniform_int_distribution<> distr1(0, size.X); // define the range
	std::uniform_int_distribution<> distr2(0, size.Y); // define the range

	// Sets coordinates of the continents
	std::vector<FVector> vContinents;
	vContinents.resize(continents);
	for (int i = 0; i < continents; i++) {
		FVector newLoc;
		do {
			newLoc = FVector(distr1(eng), distr2(eng), 0.f);
			break;
		} while (!inRange(vContinents, newLoc, 1500));
		vContinents[i] = newLoc;
	}




	//6 sides on cube, 4 verts each (corners)
	for (int x = 0; x < resolution.X; x++) {
		for (int y = 0; y < resolution.Y; y++)
		{			
			float verX = x * (size.X / resolution.X);
			float verY = y * (size.Y / resolution.Y);
			FVector point = FVector(verX, verY, 0);

			if (inRange(vContinents, point, 500)) {
				Vertices.Add(FVector(verX, verY, 100));
			}
			else if (inRange(vContinents, point, 600)) {
				Vertices.Add(FVector(verX, verY, 50));
			}
			else {
				Vertices.Add(FVector(verX, verY, 2));
			}

			// Adds triangles
			if (x != 0 && y != 0) {
				AddTriangle(resolution.Y * (x - 1) + y - 1, resolution.Y * x + y, resolution.Y * x + y - 1);
				AddTriangle(resolution.Y * (x - 1) + y - 1, resolution.Y * (x - 1) + y, resolution.Y * x + y);
			}
		}
	}


	TArray<FLinearColor> VertexColors;
	VertexColors.Add(FLinearColor(0.f, 0.f, 1.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 0.f, 0.f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(0.5f, 1.f, 0.5f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(1.f, 1.f, 0.f));
	VertexColors.Add(FLinearColor(0.f, 1.f, 1.f));

	CustomMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), VertexColors, TArray<FProcMeshTangent>(), true);
}

