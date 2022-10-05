/**
* @file		ManualTest_List.cpp
* @brief	双方向リスト 手動テスト
* @data		2022/10/04
*/

//===== インクルード =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "ManualTest_List.h"

namespace ex01_ManualTest
{

/**
* @brief	データ件数取得機能について、constのメソッドであるか
* @details	ID:8
*			データ件数取得のテストです。
*			constな関数であるか確認しています。
*			有効にした時、コンパイルが通れば成功です。
*/
TEST(GetDataNum, FunctionIsConst)
{
#ifdef LIST_GETSIZE_IS_CONST
	const LinkedList List;
	EXPECT_EQ(0, List.GetSize());
#else
	SUCCEED();
#endif
}

/**
* @brief	データ挿入機能について、非constのメソッドであるか
* @details	ID:15
*			データ挿入取得のテストです。
*			非constな関数であるか確認しています。
*			有効にした時、コンパイルが通らなければ成功です。
*/
TEST(InsertData, FunctionIsNotConst)
{
#ifdef LIST_INSERT_IS_NOT_CONST
	
	const LinkedList List;
	auto Itr = List.GetConstBegin();

	ScoreData Data;
	Data.Score = 15;
	Data.Name = "Test15";

	EXPECT_TRUE(List.Insert(Itr, Data));
#else
	SUCCEED();
#endif
}

/**
* @brief	データ削除機能について、非constのメソッドであるか
* @details	ID:22
*			データ削除取得のテストです。
*			非constな関数であるか確認しています。
*			有効にした時、コンパイルが通らなければ成功です。
*/
TEST(DeleteData, FunctionIsNotConst)
{
#ifdef LIST_DELETE_IS_NOT_CONST

	const LinkedList List;
	auto Itr = List.GetConstBegin();
	EXPECT_TRUE(List.Delete(Itr));
#else
	SUCCEED();
#endif
}

/**
* @brief	constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
* @details	ID:28
*			先頭イテレータ取得のテストです。
*			非constな関数であるか確認しています。
*			有効にした時、コンパイルが通らなければ成功です。
*/
TEST(GetBeginIterator, FunctionIsNotConst)
{
#ifdef LIST_GETBEGIN_IS_NOT_CONST

	const LinkedList List;
	List.GetBegin();

#else
	SUCCEED();
#endif
}

/**
* @brief	constな先頭イテレータ取得機能について、constな関数かチェック
* @details	ID:34
*			先頭イテレータ取得のテストです。
*			constな関数であるか確認しています。
*			有効にした時、コンパイルが通れば成功です。
*/
TEST(GetBeginConstIterator, FunctionIsConst)
{
#ifdef LIST_GETCONSTBEGIN_IS_CONST

	const LinkedList List;
	List.GetConstBegin();

#else
	SUCCEED();
#endif
}

/**
* @brief	constのリストから、ConstIteratorでないIteratorの取得が行えないかをチェック
* @details	ID:40
*			末尾イテレータ取得のテストです。
*			非constな関数であるか確認しています。
*			有効にした時、コンパイルが通らなければ成功です。
*/
TEST(GetEndIterator, FunctionIsNotConst)
{
#ifdef LIST_GETEND_IS_NOT_CONST

	const LinkedList List;
	List.GetEnd();

#else
	SUCCEED();
#endif
}

/**
* @brief	constな先頭イテレータ取得機能について、constな関数かチェック
* @details	ID:34
*			末尾イテレータ取得のテストです。
*			constな関数であるか確認しています。
*			有効にした時、コンパイルが通れば成功です。
*/
TEST(GetEndConstIterator, FunctionIsConst)
{
#ifdef LIST_GETCONSTEND_IS_CONST

	const LinkedList List;
	List.GetConstEnd();

#else
	SUCCEED();
#endif
}

}	// ex01_ManualTest