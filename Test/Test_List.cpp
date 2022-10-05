/**
* @file		Test_List.cpp
* @brief	双方向リストテスト
* @data		2022/10/04
*/

//===== インクルード =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "TestHelper.h"

namespace ex01_LinkedList
{

#pragma region ***** データ数の取得 *****
/**
* @brief	リストが空である場合の戻り値
* @details	ID:0
*			データ件数取得のテストです。
*			リストが空の場合の戻り値の確認です。
*			0であれば成功です。
*/
TEST(GetDataNum, WhenEmpty)
{
	LinkedList List;
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	リスト末尾への挿入を行った際の戻り値
* @details	ID:1
*			データ件数取得のテストです。
*			リスト末尾に挿入を行ったあとの場合の戻り値の確認です。
*			1であれば成功です。
*/
TEST(GetDataNum, WhenInsertEnd)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 0;
	Data.Name = "Test0";

	auto Itr = List.GetEnd();
	ASSERT_TRUE(List.Insert(Itr, Data));
	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	リスト末尾への挿入が失敗した際の戻り値
* @details	ID:2
*			データ件数取得のテストです。
*			リスト末尾に挿入を行い、挿入が失敗した場合の戻り値の確認です。
*			0であれば成功です。
*/
TEST(GetDataNum, WhenInsertEndFailed)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = -1;
	Data.Name.clear();

	auto Itr = List.GetEnd();
	ASSERT_FALSE(List.Insert(Itr, Data));
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	データの挿入を行った際の戻り値
* @details	ID:3
*			データ件数取得のテストです。
*			リストに挿入を行ったあと場合の戻り値の確認です。
*			1であれば成功です。
*/
TEST(GetDataNum, WhenInsert)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 3;
	Data.Name = "Test3";

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	データの挿入に失敗した際の戻り値
* @details	ID:4
*			データ件数取得のテストです。
*			リストに挿入を行い、挿入が失敗した場合の戻り値の確認です。
*			0であれば成功です。
*/
TEST(GetDataNum, WhenInsertFailed)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = -1;
	Data.Name.clear();

	auto Itr = List.GetBegin();
	ASSERT_FALSE(List.Insert(Itr, Data));
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	データの削除を行った際の戻り値
* @details	ID:5
*			データ件数取得のテストです。
*			データの削除を行った場合の戻り値の確認です。
*			0であれば成功です。
*/
TEST(GetDataNum, WhenDelete)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 5;
	Data.Name = "Test5";

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	Itr = List.GetBegin();	// 取得しなおす
	ASSERT_TRUE(List.Delete(Itr));
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	データの削除を行った際の戻り値
* @details	ID:6
*			データ件数取得のテストです。
*			データの削除を行い、削除に失敗した場合の戻り値の確認です。
*			1であれば成功です。
*/
TEST(GetDataNum, WhenDeleteFailed)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 6;
	Data.Name = "Test6";

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	LinkedList::ConstIterator InvalidItr;	// 無効なイテレータ
	ASSERT_FALSE(List.Delete(InvalidItr));

	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	リストが空である場合に、データの削除を行った際の戻り値
* @details	ID:7
*			データ件数取得のテストです。
*			リストが空の状態でデータの削除を行った場合の戻り値の確認です。
*			0であれば成功です。
*/
TEST(GetDataNum, WhenDeleteEmptyList)
{
	LinkedList List;

	LinkedList::ConstIterator InvalidItr;	// 無効なイテレータ
	ASSERT_FALSE(List.Delete(InvalidItr));

	EXPECT_EQ(List.GetSize(), 0);
}
#pragma endregion

#pragma region ***** データの挿入 *****
/**
* @brief	リストが空である場合に、挿入した際の挙動
* @details	ID:9
*			データの挿入のテストです。
*			リストが空の状態で先頭にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST(InsertData, WhenEmptyToBegin)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 9;
	Data.Name = "Test9";

	auto Itr = List.GetBegin();
	EXPECT_TRUE(List.Insert(Itr, Data));
}

/**
* @brief	リストが空である場合に、挿入した際の挙動
* @details	ID:9
*			データの挿入のテストです。
*			リストが空の状態で末尾にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST(InsertData, WhenEmptyToEnd)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 9;
	Data.Name = "Test9_1";

	auto Itr = List.GetEnd();
	EXPECT_TRUE(List.Insert(Itr, Data));
}

/**
* @brief	リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
* @details	ID:10
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、先頭にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, WhenSomeDataExistToBegin)
{
	//*** 先頭のイテレータを指定してデータを新しく挿入する
	auto Itr = pList->GetBegin();
	ScoreData Data;
	Data.Score = 10;
	Data.Name = "Test10";
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** 以前の先頭要素が2番目にあることを確認する
	Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(Itr->Score == 0);
	EXPECT_TRUE(Itr->Name == "Test0");
}

/**
* @brief	リストに複数の要素がある場合に、末尾コンストイテレータの取得を渡して、挿入した際の挙動
* @details	ID:11
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、末尾にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, WhenSomeDataExistToEnd)
{
	//*** 末尾のイテレータを指定してデータを新しく挿入する
	auto Itr = pList->GetEnd();
	ScoreData Data;
	Data.Score = 11;
	Data.Name = "Test11";
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** 末尾の1つ前に追加されているか確認する
	Itr = pList->GetEnd();
	--Itr;
	EXPECT_TRUE(Itr->Score == 11);
	EXPECT_TRUE(Itr->Name == "Test11");
}

/**
* @brief	リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
* @details	ID:12
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、先頭でも末尾でもない場所にデータの挿入を行ったときの挙動を確認します。
*			戻り値がTrueで、他のデータに影響がなければ成功です。
*/
TEST_F(LinkedListTestFixture, WhenSomeDataExistToCenter)
{
	//*** 先頭の次のイテレータを指定してデータを新しく挿入する
	auto Itr = pList->GetBegin();
	ScoreData Data;
	Data.Score = 12;
	Data.Name = "Test12";
	++Itr;
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** 先頭から2進んだ位置に元のデータがあればOK
	Itr = pList->GetBegin();
	++Itr;
	++Itr;
	EXPECT_TRUE(Itr->Score == 1);
	EXPECT_TRUE(Itr->Name == "Test1");

	//*** 格納済みのデータに影響がないかチェック
	// 前から順番に
	// Score == 0;
	// Name == "Test0";
	// Score == 12;
	// Name == "Test12";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// ならOK

	ScoreData TestData[4];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 12;
	TestData[1].Name = "Test12";
	TestData[2].Score = 1;
	TestData[2].Name = "Test1";
	TestData[3].Score = 2;
	TestData[3].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIteratorを指定して挿入を行った際の挙動
* @details	ID:13
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、コンストなイテレータを利用して先頭にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, InsertWithConstIteratorToBegin)
{
	//*** 先頭を示すコンストなイテレータを使ってデータを挿入する。
	auto ConstItr = pList->GetConstBegin();
	ScoreData Data;
	Data.Score = 13;
	Data.Name = "Test13";
	EXPECT_TRUE(pList->Insert(ConstItr, Data));

	//*** もともと先頭にあったデータが2番目に来ているかチェック
	auto Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(Itr->Score == 0);
	EXPECT_TRUE(Itr->Name == "Test0");

	//*** 格納済みのデータに影響がないかチェック
	// 前から順番に
	// Score == 13;
	// Name == "Test13";
	// Score == 0;
	// Name == "Test0";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// ならOK

	ScoreData TestData[4];
	TestData[0].Score = 13;
	TestData[0].Name = "Test13";
	TestData[1].Score = 0;
	TestData[1].Name = "Test0";
	TestData[2].Score = 1;
	TestData[2].Name = "Test1";
	TestData[3].Score = 2;
	TestData[3].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIteratorを指定して挿入を行った際の挙動
* @details	ID:13
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、コンストなイテレータを利用して末尾にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, InsertWithConstIteratorToEnd)
{
	//*** 末尾を示すコンストなイテレータを使ってデータを挿入する。
	auto ConstItr = pList->GetConstEnd();
	ScoreData Data;
	Data.Score = 13;
	Data.Name = "Test13";
	EXPECT_TRUE(pList->Insert(ConstItr, Data));

	//*** 期待される位置に挿入されているかチェック
	auto Itr = pList->GetEnd();
	--Itr;
	EXPECT_TRUE(Itr->Score == 13);
	EXPECT_TRUE(Itr->Name == "Test13");

	//*** 格納済みのデータに影響がないかチェック
	// 前から順番に
	// Score == 0;
	// Name == "Test0";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// Score == 13;
	// Name == "Test13";
	// ならOK

	ScoreData TestData[4];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 1;
	TestData[1].Name = "Test1";
	TestData[3].Score = 13;
	TestData[3].Name = "Test13";
	TestData[2].Score = 2;
	TestData[2].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIteratorを指定して挿入を行った際の挙動
* @details	ID:13
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、コンストなイテレータを利用して先頭でも末尾でもない位置にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, InsertWithConstIteratorToCenter)
{
	//*** 先頭の次を示すコンストなイテレータを使ってデータを挿入する。
	auto ConstItr = pList->GetConstBegin();
	ScoreData Data;
	Data.Score = 13;
	Data.Name = "Test13";
	++ConstItr;
	EXPECT_TRUE(pList->Insert(ConstItr, Data));

	//*** 先頭の2つ次にずれているかチェック
	auto Itr = pList->GetBegin();
	++Itr;
	++Itr;
	EXPECT_TRUE(Itr->Score == 1);
	EXPECT_TRUE(Itr->Name == "Test1");

	//*** 格納済みのデータに影響がないかチェック
	// 前から順番に
	// Score == 0;
	// Name == "Test0";
	// Score == 13;
	// Name == "Test13";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// ならOK

	ScoreData TestData[4];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 13;
	TestData[1].Name = "Test13";
	TestData[2].Score = 1;
	TestData[2].Name = "Test1";
	TestData[3].Score = 2;
	TestData[3].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	不正なイテレータを渡して、挿入した場合の挙動
* @details	ID:14
*			データの挿入のテストです。
*			不正なイテレータを使用して挿入した時の挙動をチェックします。
*			falseであれば成功です。
*/
TEST(InsertData, WithInvalidIterator)
{
	LinkedList List1;
	LinkedList List2;

	ScoreData Data;
	Data.Score = 14;
	Data.Name = "Test14";

	// 何も参照していないイテレータで挿入
	LinkedList::Iterator InvalidItr;
	EXPECT_FALSE(List1.Insert(InvalidItr, Data));

	// 別のリストを参照しているイテレータで挿入
	auto InvalidRefItr = List2.GetBegin();
	EXPECT_FALSE(List1.Insert(InvalidRefItr, Data));
}
#pragma endregion

#pragma region ***** データの削除 *****
/**
* @brief	リストが空である場合に、削除を行った際の挙動
* @details	ID:16
*			データの削除のテストです。
*			リストが空の時に、先頭イテレータを指定して削除した時の挙動をチェックします。
*			falseであれば成功です。
*/
TEST(DeleteData, WithEmptyListBegin)
{
	LinkedList List;

	// 先頭イテレータ取得
	auto Itr = List.GetBegin();

	// 挙動チェック
	EXPECT_FALSE(List.Delete(Itr));
}

/**
* @brief	リストが空である場合に、削除を行った際の挙動
* @details	ID:16
*			データの削除のテストです。
*			リストが空の時に、末尾イテレータを指定して削除した時の挙動をチェックします。
*			falseであれば成功です。
*/
TEST(DeleteData, WithEmptyListEnd)
{
	LinkedList List;

	// 末尾イテレータ取得
	auto Itr = List.GetEnd();

	// 挙動チェック
	EXPECT_FALSE(List.Delete(Itr));
}

/**
* @brief	リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
* @details	ID:17
*			データの削除のテストです。
*			複数の要素がある時に、先頭イテレータを指定して削除した時の挙動をチェックします。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, DeleteWithBegin)
{
	// 先頭イテレータを指定して削除
	auto Itr = pList->GetBegin();
	EXPECT_TRUE(pList->Delete(Itr));
}

/**
* @brief	リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
* @details	ID:18
*			データの削除のテストです。
*			複数の要素がある時に、末尾イテレータを指定して削除した時の挙動をチェックします。
*			falseであれば成功です。
*/
TEST_F(LinkedListTestFixture, DeleteWithEnd)
{
	// 末尾イテレータを指定して削除
	auto Itr = pList->GetEnd();
	EXPECT_FALSE(pList->Delete(Itr));
}

/**
* @brief	リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動
* @details	ID:19
*			データの削除のテストです。
*			複数の要素がある時に、先頭でも末尾でもないイテレータを指定して削除した時の挙動をチェックします。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, DeleteAnywhere)
{
	// 先頭イテレータの次のイテレータを指定して削除
	auto Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(pList->Delete(Itr));

	// 期待される位置に配置されているか、他の要素に影響がないかチェック
	ScoreData TestData[2];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 2;
	TestData[1].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIteratorを指定して削除を行った際の挙動
* @details	ID:20
*			データの削除のテストです。
*			コンストなイテレータを指定して削除した時の挙動をチェックします。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, DeleteAnywhereWithConstIterator)
{
	// 先頭イテレータの次のイテレータを指定して削除
	auto Itr = pList->GetConstBegin();
	++Itr;
	EXPECT_TRUE(pList->Delete(Itr));

	// 期待される位置に配置されているか、他の要素に影響がないかチェック
	ScoreData TestData[2];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 2;
	TestData[1].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	不正なイテレータを渡して、削除した場合の挙動
* @details	ID:21
*			データの削除のテストです。
*			不正なイテレータを指定して削除した時の挙動をチェックします。
*			trueであれば成功です。
*/
TEST_F(LinkedListTestFixture, DeleteInvalidIterator)
{
	// 不正なイテレータを指定して削除する
	LinkedList::Iterator Itr;
	EXPECT_FALSE(pList->Delete(Itr));
}

#pragma endregion

#pragma region ***** 先頭イテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:23
*			先頭イテレータの取得のテストです。
*			リストが空の時に、先頭イテレータを取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*/
TEST(GetBeginIterator, WhenEmpty)
{
	LinkedList List;

	// 先頭イテレータ取得
	auto Itr = List.GetBegin();

	// 挙動チェック
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	リストに要素が一つある場合に、呼び出した際の挙動
* @details	ID:24
*			先頭イテレータの取得のテストです。
*			リストに1つの要素があるとき、先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetBeginIterator, When1ItemExist)
{
	LinkedList List;

	// データを1件追加
	ScoreData Data;
	Data.Score = 24;
	Data.Name = "Test24";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = List.GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 24);
	EXPECT_TRUE(BeginItr->Name == "Test24");
}

/**
* @brief	リストに二つ以上の要素がある場合に、呼び出した際の挙動
* @details	ID:25
*			先頭イテレータの取得のテストです。
*			リストに2つ以上の要素があるとき、先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素をを指すイテレータを取得できれば成功です。
*/
TEST(GetBeginIterator, When2ItemExist)
{
	LinkedList List;

	// データを2件追加
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = List.GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:26
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭に挿入した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenInsertBegin)
{
	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = pList->GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 26);
	EXPECT_TRUE(BeginItr->Name == "Test26");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:26
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、末尾に挿入した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenInsertEnd)
{
	// 末尾にデータを挿入する
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = pList->GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:26
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない位置に挿入した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenInsertCenter)
{
	// 先頭でも末尾でもない位置にデータを挿入する
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = pList->GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:27
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭要素を削除した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenDeleteBegin)
{
	// 先頭要素を削除する
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// 先頭イテレータを取得
	auto BeginItr = pList->GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 1);
	EXPECT_TRUE(BeginItr->Name == "Test1");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:27
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、末尾要素を削除した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenDeleteEnd)
{
	// 末尾要素を削除する
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 先頭イテレータを取得
	auto BeginItr = pList->GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:27
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない要素を削除した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenDeleteCenter)
{
	// 先頭でも末尾でもない要素を削除する
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 先頭イテレータを取得
	auto BeginItr = pList->GetBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

#pragma endregion

#pragma region ***** 先頭コンストイテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:29
*			先頭コンストイテレータの取得のテストです。
*			リストが空の時に、先頭コンストイテレータを取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*/
TEST(GetBeginConstIterator, WhenEmpty)
{
	LinkedList List;

	// 先頭コンストイテレータ取得
	auto Itr = List.GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	リストに要素が一つある場合に、呼び出した際の挙動
* @details	ID:30
*			先頭コンストイテレータの取得のテストです。
*			リストに1つの要素があるとき、先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetBeginConstIterator, When1ItemExist)
{
	LinkedList List;

	// データを1件追加
	ScoreData Data;
	Data.Score = 30;
	Data.Name = "Test30";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭コンストイテレータを取得
	auto BeginItr = List.GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 30);
	EXPECT_TRUE(BeginItr->Name == "Test30");
}

/**
* @brief	リストに二つ以上の要素がある場合に、呼び出した際の挙動
* @details	ID:31
*			先頭コンストイテレータの取得のテストです。
*			リストに2つ以上の要素があるとき、先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素をを指すイテレータを取得できれば成功です。
*/
TEST(GetBeginConstIterator, When2ItemExist)
{
	LinkedList List;

	// データを2件追加
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭コンストイテレータを取得
	auto BeginItr = List.GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:32
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭に挿入した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenInsertBegin)
{
	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 先頭コンストイテレータを取得
	auto BeginItr = pList->GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 32);
	EXPECT_TRUE(BeginItr->Name == "Test32");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:32
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、末尾に挿入した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenInsertEnd)
{
	// 末尾にデータを挿入する
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 先頭コンストイテレータを取得
	auto BeginItr = pList->GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:32
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない位置に挿入した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenInsertCenter)
{
	// 先頭でも末尾でもない位置にデータを挿入する
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 先頭コンストイテレータを取得
	auto BeginItr = pList->GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:33
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭要素を削除した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenDeleteBegin)
{
	// 先頭要素を削除する
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// 先頭コンストイテレータを取得
	auto BeginItr = pList->GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 1);
	EXPECT_TRUE(BeginItr->Name == "Test1");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:33
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、末尾要素を削除した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenDeleteEnd)
{
	// 末尾要素を削除する
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 先頭コンストイテレータを取得
	auto BeginItr = pList->GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:33
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない要素を削除した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenDeleteCenter)
{
	// 先頭でも末尾でもない要素を削除する
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 先頭コンストイテレータを取得
	auto BeginItr = pList->GetConstBegin();

	// 挙動チェック
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

#pragma endregion

#pragma region ***** 末尾イテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:35
*			末尾イテレータの取得のテストです。
*			リストが空の時に、末尾イテレータを取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*/
TEST(GetEndIterator, WhenEmpty)
{
	LinkedList List;

	// 末尾イテレータ取得
	auto Itr = List.GetEnd();

	// 挙動チェック
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	リストに要素が一つある場合に、呼び出した際の挙動
* @details	ID:36
*			末尾イテレータの取得のテストです。
*			リストに1つの要素があるとき、末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetEndIterator, When1ItemExist)
{
	LinkedList List;

	// データを1件追加
	ScoreData Data;
	Data.Score = 24;
	Data.Name = "Test24";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = List.GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 24);
	EXPECT_TRUE(EndItr->Name == "Test24");
}

/**
* @brief	リストに二つ以上の要素がある場合に、呼び出した際の挙動
* @details	ID:37
*			末尾イテレータの取得のテストです。
*			リストに2つ以上の要素があるとき、末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素をを指すイテレータを取得できれば成功です。
*/
TEST(GetEndIterator, When2ItemExist)
{
	LinkedList List;

	// データを2件追加
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = List.GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:38
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭に挿入した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenInsertBegin)
{
	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 38;
	Data.Name = "Test38";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = pList->GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:38
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、末尾に挿入した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenInsertEnd)
{
	// 末尾にデータを挿入する
	ScoreData Data;
	Data.Score = 38;
	Data.Name = "Test38";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = pList->GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 38);
	EXPECT_TRUE(EndItr->Name == "Test38");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:38
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない位置に挿入した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenInsertCenter)
{
	// 先頭でも末尾でもない位置にデータを挿入する
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = pList->GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:39
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭要素を削除した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenDeleteBegin)
{
	// 先頭要素を削除する
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// 末尾イテレータを取得
	auto EndItr = pList->GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:39
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、末尾要素を削除した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenDeleteEnd)
{
	// 末尾要素を削除する
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 末尾イテレータを取得
	auto EndItr = pList->GetEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:39
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない要素を削除した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenDeleteCenter)
{
	// 先頭でも末尾でもない要素を削除する
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 末尾イテレータを取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

#pragma endregion

#pragma region ***** 末尾コンストイテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:41
*			末尾コンストイテレータの取得の取得のテストです。
*			リストが空の時に、末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*/
TEST(GetEndConstIterator, WhenEmpty)
{
	LinkedList List;

	// 末尾コンストイテレータの取得取得
	auto Itr = List.GetConstEnd();

	// 挙動チェック
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	リストに要素が一つある場合に、呼び出した際の挙動
* @details	ID:42
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに1つの要素があるとき、末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetEndConstIterator, When1ItemExist)
{
	LinkedList List;

	// データを1件追加
	ScoreData Data;
	Data.Score = 42;
	Data.Name = "Test42";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 42);
	EXPECT_TRUE(EndItr->Name == "Test42");
}

/**
* @brief	リストに二つ以上の要素がある場合に、呼び出した際の挙動
* @details	ID:43
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに2つ以上の要素があるとき、末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素をを指すイテレータを取得できれば成功です。
*/
TEST(GetEndConstIterator, When2ItemExist)
{
	LinkedList List;

	// データを2件追加
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:44
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、先頭に挿入した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenInsertBegin)
{
	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:44
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、末尾に挿入した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenInsertEnd)
{
	// 末尾にデータを挿入する
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 44);
	EXPECT_TRUE(EndItr->Name == "Test44");
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:44
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない位置に挿入した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenInsertCenter)
{
	// 先頭でも末尾でもない位置にデータを挿入する
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:45
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、先頭要素を削除した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenDeleteBegin)
{
	// 先頭要素を削除する
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:45
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、末尾要素を削除した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenDeleteEnd)
{
	// 末尾要素を削除する
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:45
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、先頭でも末尾でもない要素を削除した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenDeleteCenter)
{
	// 先頭でも末尾でもない要素を削除する
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// 末尾コンストイテレータの取得を取得
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// 挙動チェック
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

#pragma endregion

}	// ex01_LinkedList
