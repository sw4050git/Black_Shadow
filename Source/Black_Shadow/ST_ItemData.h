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

template<typename ValueType>
struct TST_ItemDataMapKeyFuncs :
	BaseKeyFuncs<
		TPair<FST_ItemData, ValueType>,
		int32
	>
{
private:
	typedef BaseKeyFuncs <
		TPair<FST_ItemData, ValueType>,
		int32
	> Super;

public:
	typedef typename Super::ElementInitType ElementInitType;
	typedef typename Super::KeyInitType KeyInitType;

	static KeyInitType GetSetKey(ElementInitType Element)
	{
		return Element.Key.ItemData->ID;
	}

	static bool Matches(KeyInitType A, KeyInitType B)
	{
		return A == B;
	}

	static uint32 GetKeyHash(KeyInitType Key)
	{
		return GetTypeHash(Key);
	}
};

