// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  //Must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
	ATank* GetControlledTank() const;

private:
		virtual void BeginPlay() override;

		virtual void Tick(float DeltaTime) override;

		// Start the tank moving the barrel so that a shot would hit where
		// the crosshair intersects the world
		void AimTowardsCrossHair();

		// Return an OUT parameter, true if hit landscape
		bool GetSightRayHitLocation(FVector &HitLocation) const;
		bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

		UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5;

		UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333;

		UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;
		
};
