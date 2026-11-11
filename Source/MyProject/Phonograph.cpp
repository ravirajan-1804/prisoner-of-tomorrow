#include "Phonograph.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

// The Constructor: Runs when the object is created
APhonograph::APhonograph()
{
    // Disable ticking to save performance
    PrimaryActorTick.bCanEverTick = false;

    // 1. Create the Mesh
    PhonographMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PhonographMesh"));
    RootComponent = PhonographMesh;

    // 2. Create the Audio Component
    RiddleAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("RiddleAudio"));
    RiddleAudio->SetupAttachment(RootComponent);

    // Prevent it from playing automatically
    RiddleAudio->bAutoActivate = false;
}

// The Interaction: Plays the sound if it's not already playing
void APhonograph::PlayRiddle()
{
    if (RiddleAudio && !RiddleAudio->IsPlaying())
    {
        RiddleAudio->Play();
        UE_LOG(LogTemp, Warning, TEXT("Phonograph is playing the riddle!"));
    }
}