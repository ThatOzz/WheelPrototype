// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "CustomVehicleMovementController.generated.h"

/**
 * 
 */
UCLASS()
class WHEELCONTROLLERPROTO_API UCustomVehicleMovementController : public UChaosWheeledVehicleMovementComponent
{
    GENERATED_BODY()

public:
    // Set drive torque on a specific wheel
    UFUNCTION(BlueprintCallable, Category = "Custom Vehicle Control")
    void SetDriveTorquePerWheel(int32 WheelIndex, float TorqueAmount);
};
