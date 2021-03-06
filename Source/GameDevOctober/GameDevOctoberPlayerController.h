// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameDevOctoberCharacter.h"
#include "HeroComponent.h"
#include "LuuxHeroComponent.h"
#include "GameDevOctoberPlayerController.generated.h"


UCLASS()
class AGameDevOctoberPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGameDevOctoberPlayerController();

	void CastHeroQAbility();

	void CastHeroWAbility();

	void CastHeroEAbility();

	void CastHeroRAbility();

	// Return current HeroComponent of current Pawn
	class UHeroComponent * GetHeroComponent() {
		AGameDevOctoberCharacter* MyPawn = Cast<AGameDevOctoberCharacter>(GetPawn());
		return MyPawn->GetCurrentHeroComponent();
	};

	// Causes Pawn to change its HeroComponent
	void ChangeHeroComponent() {
		UClass* newHeroComponentClass = ULuuxHeroComponent::StaticClass();
		AGameDevOctoberCharacter* MyPawn = Cast<AGameDevOctoberCharacter>(GetPawn());
		MyPawn->SetCurrentHeroComponent(newHeroComponentClass);
	};

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();


};


