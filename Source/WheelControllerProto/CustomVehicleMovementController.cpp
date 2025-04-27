// Fill out your copyright notice in the Description page of Project Settings.

#include "WheelSystem.h"
#include "CustomVehicleMovementController.h"

void UCustomVehicleMovementController::SetDriveTorquePerWheel(int32 WheelIndex, float TorqueAmount)
{
    SetDriveTorque(TorqueAmount, WheelIndex);
}

void UCustomVehicleMovementController::SetSteerAnglePerWheel(int32 WheelIndex, float SteerAngle)
{
    
}
