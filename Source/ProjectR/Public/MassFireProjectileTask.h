// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "MassStateTreeTypes.h"
#include "MassEntityConfigAsset.h"
#include "MassFireProjectileTask.generated.h"

class UMassSignalSubsystem;
struct FTransformFragment;

USTRUCT()
struct PROJECTR_API FMassFireProjectileTaskInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FMassEntityConfig EntityConfig;

	UPROPERTY(EditAnywhere, Category = Parameter)
	float InitialVelocity = 100.f;

	UPROPERTY(EditAnywhere, Category = Parameter)
	float ForwardVectorMagnitude = 100.f;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector ProjectileLocationOffset = FVector::ZeroVector;
};

USTRUCT(meta = (DisplayName = "Fire Projectile"))
struct PROJECTR_API FMassFireProjectileTask : public FMassStateTreeTaskBase
{
	GENERATED_BODY()

protected:
	virtual bool Link(FStateTreeLinker& Linker) override;
	virtual const UStruct* GetInstanceDataType() const override { return FMassFireProjectileTaskInstanceData::StaticStruct(); }
	virtual EStateTreeRunStatus EnterState(FStateTreeExecutionContext& Context, const EStateTreeStateChangeType ChangeType, const FStateTreeTransitionResult& Transition) const override;
	virtual EStateTreeRunStatus Tick(FStateTreeExecutionContext& Context, const float DeltaTime) const override;

	TStateTreeExternalDataHandle<UMassSignalSubsystem> MassSignalSubsystemHandle;
	TStateTreeExternalDataHandle<FTransformFragment> EntityTransformHandle;

	TStateTreeInstanceDataPropertyHandle<FMassEntityConfig> EntityConfigHandle;
	TStateTreeInstanceDataPropertyHandle<float> InitialVelocityHandle;
	TStateTreeInstanceDataPropertyHandle<float> ForwardVectorMagnitudeHandle;
	TStateTreeInstanceDataPropertyHandle<FVector> ProjectileLocationOffsetHandle;
};