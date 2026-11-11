#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h" // Added this for USoundBase
#include "Keypad.generated.h"

UCLASS()
class MYPROJECT_API AKeypad : public AActor
{
    GENERATED_BODY()

public:
    AKeypad();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keypad")
    FString CorrectPassword;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Keypad")
    FString CurrentInput;

    // --- Audio Section ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keypad|Audio")
    class USoundBase* ClickSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Keypad|Audio")
    class USoundBase* ErrorSound;

    // --- Functions ---
    UFUNCTION(BlueprintCallable, Category = "Keypad")
    void HandleInput(FString Digit);

    UFUNCTION(BlueprintCallable, Category = "Keypad")
    void ClearInput();

    UFUNCTION(BlueprintCallable, Category = "Keypad")
    void HandleBackspace();

    UFUNCTION(BlueprintCallable, Category = "Keypad")
    void ResetKeypad();

    // Success Event for Blueprints
    UFUNCTION(BlueprintImplementableEvent, Category = "Keypad")
    void OnCodeCorrect();

protected:
    // Removed "= false" here. We set this in the .cpp constructor instead.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Keypad")
    bool bIsSolved;

    void CheckPassword();
};