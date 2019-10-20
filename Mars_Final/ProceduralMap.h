// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralMap.generated.h"

UCLASS()
class MARS_FINAL_API AProceduralMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ATerrain")
		UProceduralMeshComponent* CustomMesh;

	/* The vertices of the mesh */
	TArray<FVector> Vertices;

	/* The triangles of the mesh */
	TArray<int32> Triangles;

	/* Creates a triangle that connects the given vertices */
	void AddTriangle(int32 V1, int32 V2, int32 V3);

	UFUNCTION(BlueprintCallable, Category = "ATerrain")
	void GenerateCubeMesh();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATerrain")
		FVector size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATerrain")
		FVector2D resolution;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATerrain", meta = (ClampMin = "0", UIMin = "0"))
		int continents;

};
