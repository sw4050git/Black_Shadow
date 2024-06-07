// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GA_ItemBase.h"
#include "Engine/DataAsset.h"
#include "CPP_ItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BLACK_SHADOW_API UCPP_ItemDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* Image;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGA_ItemBase> ItemAbility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Consumable;

};
