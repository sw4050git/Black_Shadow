// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_ItemDataAsset.h"
#include "ST_ItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FST_ItemData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UCPP_ItemDataAsset* ItemData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Count;
};
