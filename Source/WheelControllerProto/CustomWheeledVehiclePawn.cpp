// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomWheeledVehiclePawn.h"
#include "CustomVehicleMovementController.h"

// Sets default values
ACustomWheeledVehiclePawn::ACustomWheeledVehiclePawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomVehicleMovementController>(VehicleMovementComponentName))
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomWheeledVehiclePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomWheeledVehiclePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomWheeledVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

