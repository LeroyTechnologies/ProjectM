#pragma once

#if WITH_GAMEPLAY_DEBUGGER

#include "CoreMinimal.h"
#include "GameplayDebuggerCategory.h"

class APlayerController;
class AActor;
struct FMassNavMeshMoveFragment;

class FGameplayDebuggerCategory_ProjectM : public FGameplayDebuggerCategory
{
public:
  FGameplayDebuggerCategory_ProjectM();
  void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;
  void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;

  static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

protected:
	void DrawTargetEntityLocations(const TArray<FVector>& TargetEntityLocations, const FColor& Color, const FVector& EntityLocation);
	void CollectDataForNavMeshMoveProcessor(const APlayerController* OwnerPC);
	void DrawEntityInfo(const FMassNavMeshMoveFragment& NavMeshMoveFragment, const FTransform& Transform);
};

#endif // WITH_GAMEPLAY_DEBUGGER