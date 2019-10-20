// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <cmath>
#include "CoreMinimal.h"
#include "ATile.h"
#include "GameFramework/Actor.h"
#include "AMap.generated.h"

UCLASS()
class MARS_FINAL_API AAMap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAMap();
	~AAMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		TSubclassOf<class AATile> plainTerrain1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		TSubclassOf<class AATile> plainTerrain2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		TSubclassOf<class AATile> plainTerrain3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		TSubclassOf<class AATile> plainTerrain4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		TSubclassOf<class AATile> plainTerrain5;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		float tileRadius = 1.;

private:
	enum TileTypes { Desert = 0, River, GrassPlane };

	// Generates new Map
	void GenerateMap(int sizeW = 50, int sizeH = 20);

	// Creates 3D represenatation of the map
	void CreateMap(int sizeW = 300, int sizeH = 100);
};
