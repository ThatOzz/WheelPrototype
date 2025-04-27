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

    MovementComponent->SetDriveTorquePerWheel(1, LeftInput * MaxTorque);  // Front Left
    MovementComponent->SetDriveTorquePerWheel(3, LeftInput * MaxTorque);  // Rear Left
    MovementComponent->SetDriveTorquePerWheel(0, RightInput * MaxTorque); // Front Right
    MovementComponent->SetDriveTorquePerWheel(2, RightInput * MaxTorque); // Rear Right
}