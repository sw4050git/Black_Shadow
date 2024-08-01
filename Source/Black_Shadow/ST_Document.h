// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MediaSource.h"
#include "ST_Document.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FST_Document
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (MultiLine = true))
	FText Text;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* Image;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMediaSource* Movie;
};
