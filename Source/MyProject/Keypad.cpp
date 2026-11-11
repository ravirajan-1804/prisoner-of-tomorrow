#include "Keypad.h"
#include "Kismet/GameplayStatics.h"

AKeypad::AKeypad()
{
    PrimaryActorTick.bCanEverTick = false;
    CorrectPassword = "1234";
    CurrentInput = "";
    bIsSolved = false;
}

void AKeypad::HandleInput(FString Digit)
{
    // 1. EXIT IMMEDIATELY IF SOLVED
    // This is the absolute first check. Nothing runs if bIsSolved is true.
    if (bIsSolved) return;

    // 2. PLAY 3D SOUND (Optimized for Mobile)
    if (ClickSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ClickSound, GetActorLocation());
    }

    // 3. LOGIC
    if (CurrentInput.Len() < 4)
    {
        CurrentInput += Digit;
        if (CurrentInput.Len() == 4)
        {
            CheckPassword();
        }
    }
}

void AKeypad::CheckPassword()
{
    if (CurrentInput == CorrectPassword)
    {
        // SET TRUE BEFORE CALLBACK
        bIsSolved = true;

        CurrentInput = "OPEN";
        OnCodeCorrect();

        UE_LOG(LogTemp, Warning, TEXT("Keypad Solved. Input Disabled."));
    }
    else
    {
        if (ErrorSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, ErrorSound, GetActorLocation());
        }
        ResetKeypad();
    }
}

void AKeypad::ClearInput()
{
    if (!bIsSolved)
    {
        CurrentInput = "";
    }
}

void AKeypad::HandleBackspace()
{
    if (!bIsSolved && CurrentInput.Len() > 0)
    {
        CurrentInput.RemoveAt(CurrentInput.Len() - 1);
    }
}

void AKeypad::ResetKeypad()
{
    CurrentInput = "";
}