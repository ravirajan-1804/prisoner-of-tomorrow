#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Phonograph.generated.h"

// Forward declarations to keep compile times fast
class UStaticMeshComponent;
class UAudioComponent;

UCLASS()
class MYPROJECT_API APhonograph : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    APhonograph();

    // The 3D model component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* PhonographMesh;

    // The Audio component for the riddle
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAudioComponent* RiddleAudio;

    // The function the player calls to hear the code
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void PlayRiddle();
};