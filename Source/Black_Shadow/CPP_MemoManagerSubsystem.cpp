// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MemoManagerSubsystem.h"


void UCPP_MemoManagerSubsystem::AddMemoData(UCPP_MemoDataAsset* Memo)
{
	Memos.AddUnique(Memo);
	SortMemos();
	ED_UpdateMomos.Broadcast();
}

void UCPP_MemoManagerSubsystem::SortMemos()
{
	Memos.Sort([](const UCPP_MemoDataAsset& A, const UCPP_MemoDataAsset& B) {return A.ID < B.ID; });
}