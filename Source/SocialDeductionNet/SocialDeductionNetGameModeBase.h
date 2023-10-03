// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Interfaces/OnlineSessionInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "SocialDeductionNetGameModeBase.generated.h"

// Guide: https://unrealcommunity.wiki/online-multiplayer-vkje2zyn

// Trigger event when session setup complete
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCSOnCreateSessionComplete, bool, Successful);

/**
 * 
 */
UCLASS()
class SOCIALDEDUCTIONNET_API ASocialDeductionNetGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public: 
	ASocialDeductionNetGameModeBase();

	void CreateLobby(int32 PlayerLimit, bool IsLANMatch);

	FCSOnCreateSessionComplete OnCreateSessionCompleteEvent;

protected:
	TArray<APlayerController> PlayerControllers;
	void OnCreateSessionCompleted(FName SessionName, bool Successful);

private:
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FDelegateHandle CreateSessionCompleteDelegateHandle;
	TSharedPtr<FOnlineSessionSettings> LastSessionSettings;
};
