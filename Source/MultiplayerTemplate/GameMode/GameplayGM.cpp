// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayGM.h"
#include "MultiplayerTemplate/PlayerController/GameplayPC.h"
#include "MultiplayerTemplate/GameInstance/GameInfoInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void AGameplayGM::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGameplayGM, AllPlayerControllers);
}

void AGameplayGM::SwapPlayerControllers(APlayerController * OldPC, APlayerController * NewPC)
{
	UE_LOG(IntruderDebug, Verbose, TEXT("SwapPlayerControllers - Begin"));

	Super::SwapPlayerControllers(OldPC, NewPC);

	AllPlayerControllers.Add(NewPC);

	UE_LOG(IntruderDebug, Verbose, TEXT("SwapPlayerControllers - End"));
}

void AGameplayGM::Logout(AController* Exiting)
{
	UE_LOG(IntruderDebug, Verbose, TEXT("Logout - Begin"));

	Super::Logout(Exiting);

	AGameplayPC * GameplayPC = Cast<AGameplayPC>(Exiting);
	if (!GameplayPC) {
		return;
	}

	UGameInfoInstance * GameInstance = Cast<UGameInfoInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (!GameInstance) {
		return;
	}

	GameInstance->DestroySessionCaller(GameplayPC);

	UE_LOG(IntruderDebug, Verbose, TEXT("Logout - End"));
}

bool AGameplayGM::RespawnPlayer_Validate(APlayerController* PlayerController, TSubclassOf<ACharacter> CharacterClass)
{
	return true;
}

void AGameplayGM::RespawnPlayer_Implementation(APlayerController* PlayerController, TSubclassOf<ACharacter> CharacterClass)
{
	UE_LOG(IntruderDebug, Verbose, TEXT("RespawnPlayer - Begin"));

	// Destroy the previous pawn, if there's one
	if (PlayerController->GetPawn()) {
		PlayerController->GetPawn()->Destroy();
	}

	// Spawn the new character at a random spawn point
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), SpawnPoints);
	int RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, SpawnPoints.Num() - 1);
	FTransform SpawnTransform = SpawnPoints[RandomIndex]->GetActorTransform();
	ACharacter * NewCharacter = GetWorld()->SpawnActor<ACharacter>(CharacterClass, SpawnTransform);

	// Assing the new pawn to the player controller
	PlayerController->Possess(NewCharacter);

	UE_LOG(IntruderDebug, Verbose, TEXT("RespawnPlayer - End"));
}