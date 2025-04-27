#include "WheelControlComponent.h"
#include "CustomVehicleMovementController.h"
#include "GameFramework/Actor.h"

UWheelControlComponent::UWheelControlComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UWheelControlComponent::BeginPlay()
{
    Super::BeginPlay();

    MovementComponent = GetOwner()->FindComponentByClass<UCustomVehicleMovementController>();
    if (!MovementComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("WheelControlComponent: Could not find UCustomVehicleMovementController!"));
    }
}

void UWheelControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!MovementComponent) return;

    UE_LOG(LogTemp, Log, TEXT("CurrentSpeed: %f"), (MovementComponent->GetForwardSpeed() * 0.036f));
    if ((MovementComponent->GetForwardSpeed() * 0.036f) < MaxSpeed)
    {
        MovementComponent->SetDriveTorquePerWheel(1, LeftInput * MaxTorque);  // Front Left
        MovementComponent->SetDriveTorquePerWheel(3, LeftInput * MaxTorque);  // Rear Left
        MovementComponent->SetDriveTorquePerWheel(0, RightInput * MaxTorque); // Front Right
        MovementComponent->SetDriveTorquePerWheel(2, RightInput * MaxTorque); // Rear Right
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            MovementComponent->SetDriveTorquePerWheel(i, 0);
        }
    }
}