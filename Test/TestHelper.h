#pragma once

//===== インクルード =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"

/**
* @class	LinkedListTestFixture
* @brief	複数要素が既に入っているリストの準備を簡略化するためのフィクスチャ
*/
class LinkedListTestFixture : public ::testing::Test
{
	//=== メンバ変数
protected:

	LinkedList* pList;	// リスト

	//=== メンバ関数
protected:

	virtual void SetUp(void)
	{
		pList = new LinkedList;
		ScoreData Data;

		//*** データを3件末尾に挿入する
		Data.Score = 0;
		Data.Name = "Test0";
		pList->Pushback(Data);

		Data.Score = 1;
		Data.Name = "Test1";
		pList->Pushback(Data);

		Data.Score = 2;
		Data.Name = "Test2";
		pList->Pushback(Data);
	}

	virtual void TearDown(void)
	{
		delete pList;
	}
};

//===== 関数定義 =====

/**
* @fn		TestListItem(LinkedList&, ScoreData*, size_t)
* @brief	リスト内にデータが順番に入っているかチェックする。
*/
inline void TestListItem(LinkedList& List, ScoreData* pData, size_t DataCount)
{
	ASSERT_TRUE(List.GetSize() == DataCount);
	ASSERT_TRUE(pData);
	ASSERT_GT(DataCount, 0u);

	//*** 先頭から順番に確認していく
	auto Itr = List.GetBegin();
	for (decltype(DataCount) i = 0; i < DataCount; ++i)
	{
		// 正しいかチェック
		EXPECT_EQ(pData[i].Score, Itr->Score);
		EXPECT_EQ(pData[i].Name, Itr->Name);

		++Itr;
	}
}
