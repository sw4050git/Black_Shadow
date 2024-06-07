// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ST_ItemData.h"
#include "Subsystems/WorldSubsystem.h"
#include "CPP_ItemManegerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BLACK_SHADOW_API UCPP_ItemManegerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	TMap<FST_ItemData, int32, FDefaultSetAllocator,TST_ItemDataMapKeyFuncs<int32>> Items;
	/*
	UFUNCTION(BlueprintCallable,Category="ItemDataManager")
	bool ContainItemData(FST_ItemData Item) 
	{
		return Items.Contains(Item);
	}



	UFUNCTION(BlueprintCallable, Category = "ItemDataManager")
	void AddItemData(FST_ItemData Item) 
	{
		Items[Item] = 0;
	}
	*/
};
