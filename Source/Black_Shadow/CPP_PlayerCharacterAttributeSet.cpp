// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacterAttributeSet.h"
#include "CPP_PlayerCharacterBase.h"
#include "GameplayEffect.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayEffectExtension.h"

UCPP_PlayerCharacterAttributeSet::UCPP_PlayerCharacterAttributeSet()
{
	Speed = 250.f;
	HeartRate = 0.f;
	HeartRateIncrement = 0.0001f;
	Loudness = 10.f;
}

void UCPP_PlayerCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	AActor* TargetActor = Data.Target.GetAvatarActor();
	ACPP_PlayerCharacterBase* TargetCharacter = Cast<ACPP_PlayerCharacterBase>(TargetActor);
	AActor* SourceActor = Data.EffectSpec.GetContext().GetOriginalInstigator();
	
	if (Data.EvaluatedData.Attribute == GetHeartRateAttribute())
	{
		if (TargetCharacter)
		{
			if (GetHeartRate() >= 1.f) {
				TargetCharacter->Alert();
			}
		}
		SetHeartRate(FMath::Clamp(GetHeartRate(), 0.f, 1.f));
	}
}

void UCPP_PlayerCharacterAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	if (Attribute == GetSpeedAttribute()) {
		ACPP_PlayerCharacterBase* Player = Cast<ACPP_PlayerCharacterBase>(UGameplayStatics::GetPlayerCharacter(this->GetWorld(), 0));
		if (Player)
		{
			Player->SetWalkSpeed(NewValue);
		}
	}
}