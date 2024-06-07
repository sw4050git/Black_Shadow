// Fill out your copyright notice in the Description page of Project Settings.


#include "GMMC_IncreaseHeartRate.h"
#include "CPP_PlayerCharacterAttributeSet.h"

UGMMC_IncreaseHeartRate::UGMMC_IncreaseHeartRate()
{
	HeartRateIncrementDef.AttributeToCapture = UCPP_PlayerCharacterAttributeSet::GetHeartRateIncrementAttribute();
	HeartRateIncrementDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	HeartRateIncrementDef.bSnapshot = true;
	RelevantAttributesToCapture.Add(HeartRateIncrementDef);
}

float UGMMC_IncreaseHeartRate::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec)const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();


	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float HeartRateIncrement = 0.f;

	GetCapturedAttributeMagnitude(HeartRateIncrementDef, Spec, EvaluationParameters, HeartRateIncrement);
	
	UE_LOG(LogTemp, Log, TEXT("Increment=%f"), HeartRateIncrement);
	return HeartRateIncrement;
}