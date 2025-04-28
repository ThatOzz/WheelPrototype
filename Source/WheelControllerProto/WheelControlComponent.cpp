#include "WheelControlComponent.h"
#include "CustomVehicleMovementController.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

UWheelControlComponent::UWheelControlComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UWheelControlComponent::BeginPlay()
{
    Super::BeginPlay();

    MovementComponent = GetOwner()->FindComponentByClass<UCustomVehicleMovementController>();
    
}

void UWheelControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    bool overMaxSpeed = false;
    bool skipLeft = false;
    bool skipRight = false;
    
    //Check if over max speed
    if (abs(MovementComponent->GetForwardSpeed() * 0.036f) > MaxSpeed) //Check for max speed
    {
        overMaxSpeed = true;
    }
    
    //Left Throttle
    if ((MovementComponent->GetForwardSpeed()*LeftInput) > 0) //Check if accelerating or decelerating
    {
        if (overMaxSpeed) //Check if already at max speed (Forwards and Backwards)
        {
            LeftInput = 0;
            MovementComponent->SetDriveTorquePerWheel(0, LeftInput * MaxTorque);  // Front Left
            MovementComponent->SetDriveTorquePerWheel(2, LeftInput * MaxTorque);  // Rear Left
            skipLeft = true;
        }
    }
    
    //Right Throttle
    if ((MovementComponent->GetForwardSpeed() * RightInput) > 0) //Check if accelerating or decelerating
    {
        if (overMaxSpeed) //Check if already at max speed (Forwards and Backwards)
        {
            RightInput = 0;
            MovementComponent->SetDriveTorquePerWheel(1, RightInput * MaxTorque);  // Front Right
            MovementComponent->SetDriveTorquePerWheel(3, RightInput * MaxTorque); // Rear Right
            skipRight = true;
        }
    }

    if (!skipLeft)
    {
        MovementComponent->SetDriveTorquePerWheel(0, LeftInput * MaxTorque);  // Front Left
        MovementComponent->SetDriveTorquePerWheel(2, LeftInput * MaxTorque);  // Rear Left
    }
    if (!skipRight)
    {
        MovementComponent->SetDriveTorquePerWheel(1, RightInput * MaxTorque); // Front Right
        MovementComponent->SetDriveTorquePerWheel(3, RightInput * MaxTorque); // Rear Right
    }
}