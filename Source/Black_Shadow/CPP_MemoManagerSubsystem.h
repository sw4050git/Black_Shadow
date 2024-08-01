// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_MemoDataAsset.h"
#include "CPP_MemoManagerSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_UpdateMemos);

UCLASS()
class BLACK_SHADOW_API UCPP_MemoManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<UCPP_MemoDataAsset*> Memos;

	UFUNCTION(BlueprintCallable, Category = "MemoManager")
	void AddMemoData(UCPP_MemoDataAsset* Memo);

	void SortMemos();

	UPROPERTY(BlueprintAssignable, Category = "MemoManager")
	FED_UpdateMemos ED_UpdateMomos;
	
};
