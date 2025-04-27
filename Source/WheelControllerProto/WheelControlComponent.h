#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WheelControlComponent.generated.h"

class UCustomVehicleMovementController;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WHEELCONTROLLERPROTO_API UWheelControlComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UWheelControlComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Throttle inputs
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wheel Input")
    float LeftInput;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wheel Input")
    float RightInput;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wheel Input")
    float MaxTorque = 5000.f;

private:
    UCustomVehicleMovementController* MovementComponent;
};