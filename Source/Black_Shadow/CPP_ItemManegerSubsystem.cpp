// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_ItemManegerSubsystem.h"

void UCPP_ItemManegerSubsystem::AddItemData(FST_ItemData NewItem)
{
	FST_ItemData* ItemPtr = Items.FindByPredicate([NewItem](const FST_ItemData Item) {return Item.ItemData == NewItem.ItemData;});
	if (ItemPtr != nullptr)
	{
		ItemPtr->Count = FMath::Clamp(NewItem.Count + ItemPtr->Count, 0, NewItem.ItemData->MaxCount);
	}
	else
	{
		Items.Add(NewItem);
		SortItems();
	}
	ED_UpdateItem.Broadcast();
}

void UCPP_ItemManegerSubsystem::ConsumeItem(UCPP_ItemDataAsset* ItemData)
{
	int32 Index = Items.IndexOfByPredicate([ItemData](const FST_ItemData Item) {return Item.ItemData == ItemData; });
	if (Index!=INDEX_NONE)
	{
		if (Items[Index].ItemData->Consumable)
		{
			Items[Index].Count -= 1;
			if (Items[Index].Count == 0)
			{
				Items.RemoveAt(Index);
				SortItems();
			}
			ED_UpdateItem.Broadcast();
		}
	}
}

void UCPP_ItemManegerSubsystem::SelectItem(bool IsRight) {
	if (!Items.IsEmpty()) {
		SelectedItemIndex += IsRight ? 1 : -1;
		SelectedItemIndex = ((SelectedItemIndex % Items.Num()) + Items.Num()) % Items.Num();
		SelectedItemData = Items[SelectedItemIndex].ItemData;
	}
}

void UCPP_ItemManegerSubsystem::SortItems() 
{
	Items.Sort([](const FST_ItemData A, const FST_ItemData B) {return A.ItemData->ID < B.ItemData->ID; });
	int32 TempIndex = Items.IndexOfByPredicate([this](const FST_ItemData Item) {return Item.ItemData == SelectedItemData; });
	if (TempIndex != INDEX_NONE) 
	{
		SelectedItemIndex = TempIndex;
		SelectedItemData = Items[SelectedItemIndex].ItemData;
	}
	else 
	{
		if (!Items.IsEmpty()) 
		{
			SelectedItemIndex %= Items.Num();
			SelectedItemData = Items[SelectedItemIndex].ItemData;
		}
	} 
}
