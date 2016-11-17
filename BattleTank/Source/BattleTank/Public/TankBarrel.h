// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))   // This anotation let's you add this class to the Blueprint Script - by adding "hidecategories = (Collision)" you can hide sections in the BP Details
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is a max up movement
	void Elevate(float RelativeSpeed);


private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 5;  // Sensible default
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;  // Sensible default
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;  // Sensible default
};
