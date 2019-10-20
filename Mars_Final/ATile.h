// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "ATile.generated.h"

UCLASS()
class MARS_FINAL_API AATile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AATile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		class UStaticMeshComponent* tileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tile", meta = (AllowPrivateAcess = "true"))
		class UStaticMeshComponent* terrainMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int height;
	bool bTraversable;
	bool bBuildable;
	bool bBuilding;
	bool bRoad;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool hasBuilding() const;
	bool hasRoad() const;
	bool isTraversable() const;
	bool isBuildable() const;

	void build();
	void demolish();
	void buildRoad();
	void demolishRoad();
};
