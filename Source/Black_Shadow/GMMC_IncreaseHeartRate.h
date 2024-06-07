// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "GMMC_IncreaseHeartRate.generated.h"

/**
 * 
 */
UCLASS()
class BLACK_SHADOW_API UGMMC_IncreaseHeartRate : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UGMMC_IncreaseHeartRate();

	UPROPERTY()
	FGameplayEffectAttributeCaptureDefinition HeartRateIncrementDef;

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
