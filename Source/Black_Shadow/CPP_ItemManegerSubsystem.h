// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_ItemData.h"
#include "CPP_ItemDataAsset.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_ItemManegerSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FED_UpdateItem);

UCLASS()
class BLACK_SHADOW_API UCPP_ItemManegerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<FST_ItemData> Items;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCPP_ItemDataAsset* SelectedItemData;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	int32 SelectedItemIndex;

	UFUNCTION(BlueprintCallable, Category = "ItemDataManager")
	void AddItemData(FST_ItemData Item);

	UFUNCTION(BlueprintCallable, Category = "ItemDataManager")
	void ConsumeItem(UCPP_ItemDataAsset* Item);

	UFUNCTION(BlueprintCallable, Category = "ItemDataManager")
	void SelectItem(bool IsRight);

	void SortItems();

	UPROPERTY(BlueprintAssignable, Category = "ItemDataBase")
	FED_UpdateItem ED_UpdateItem;

};
