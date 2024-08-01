// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ST_Document.h"
#include "CPP_MemoDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BLACK_SHADOW_API UCPP_MemoDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Title;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FST_Document> Documents;

};
