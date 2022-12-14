/**
* @file		Test_List.cpp
* @brief	双方向リストのテスト
* @data		2022/10/04
*/

//===== インクルード =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "TestHelper.h"

/**
* @namespace	ex01_LinkedList
* @brief		双方向リストのテスト
*/
namespace ex01_LinkedList
{

//===== 型エイリアス =====

using InserDataF = LinkedListTestFixture;
using DeleteDataF = LinkedListTestFixture;
using GetBeginIteratorF = LinkedListTestFixture;
using GetBeginConstIteratorF = LinkedListTestFixture;
using GetEndIteratorF = LinkedListTestFixture;
using GetEndConstIteratorF = LinkedListTestFixture;

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

	auto Itr = List.GetEnd();	// イテレータ
	ASSERT_FALSE(List.Delete(Itr));

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
TEST(InsertData, WhenEmptyTo)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 9;
	Data.Name = "Test9";

	// 先頭イテレータ
	{
		auto Itr = List.GetBegin();
		EXPECT_TRUE(List.Insert(Itr, Data));
	}

	// 末尾イテレータ
	{
		auto ConstItr = List.GetEnd();
		EXPECT_TRUE(List.Insert(ConstItr, Data));
	}
}

/**
* @brief	リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
* @details	ID:10
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、先頭にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(InserDataF, WhenSomeDataExistToBegin)
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
	auto& TestData = *Itr;
	EXPECT_EQ(0 ,TestData.Score);
	EXPECT_EQ("Test0", TestData.Name);
}

/**
* @brief	リストに複数の要素がある場合に、末尾コンストイテレータの取得を渡して、挿入した際の挙動
* @details	ID:11
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、末尾にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(InserDataF, WhenSomeDataExistToEnd)
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
	auto& TestData = *Itr;
	EXPECT_EQ(11, TestData.Score);
	EXPECT_EQ("Test11", TestData.Name);
}

/**
* @brief	リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
* @details	ID:12
*			データの挿入のテストです。
*			リストに複数の要素がある状態で、先頭でも末尾でもない場所にデータの挿入を行ったときの挙動を確認します。
*			戻り値がTrueで、他のデータに影響がなければ成功です。
*/
TEST_F(InserDataF, WhenSomeDataExistToCenter)
{
	//*** 先頭の次のイテレータを指定してデータを新しく挿入する
	auto Itr = pList->GetBegin();
	{
		ScoreData Data;
		Data.Score = 12;
		Data.Name = "Test12";
		++Itr;
		EXPECT_TRUE(pList->Insert(Itr, Data));
	}

	//*** 先頭から2進んだ位置に元のデータがあればOK
	{
		Itr = pList->GetBegin();
		++Itr;
		++Itr;
		auto& Data = *Itr;
		EXPECT_EQ(1, Data.Score);
		EXPECT_EQ("Test1", Data.Name);
	}

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
*			リストに複数の要素がある状態で、コンストなイテレータを利用して先頭, 末尾, 先頭でも末尾でもない要素にデータの挿入を行ったときの挙動を確認します。
*			trueであれば成功です。
*/
TEST_F(InserDataF, InsertWithConstIteratorToBegin)
{
	//*** 先頭を示すコンストなイテレータを使ってデータを挿入する。
	{
		auto ConstItr = pList->GetConstBegin();
		ScoreData Data;
		Data.Score = 13;
		Data.Name = "Test13";
		EXPECT_TRUE(pList->Insert(ConstItr, Data));
	}

	//*** もともと先頭にあったデータが2番目に来ているかチェック
	{
		auto Itr = pList->GetBegin();
		++Itr;
		auto& Data = *Itr;
		EXPECT_EQ(0, Data.Score);
		EXPECT_EQ("Test0", Data.Name);
	}

	//*** 格納済みのデータに影響がないかチェック
	{
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

	//*** 末尾を指すコンストなイテレータを使ってデータを挿入する
	{
		auto ConstItr = pList->GetConstEnd();
		ScoreData Data;
		Data.Score = 14;
		Data.Name = "Test13_End";
		EXPECT_TRUE(pList->Insert(ConstItr, Data));
	}

	//*** 期待される位置に入っているかチェック
	{
		auto Itr = pList->GetEnd();
		--Itr;
		auto& Data = *Itr;
		EXPECT_EQ(14, Data.Score);
		EXPECT_EQ("Test13_End", Data.Name);
	}

	//*** 格納済みのデータに影響がないかチェック
	{
		// 前から順番に
		// Score == 13;
		// Name == "Test13";
		// Score == 0;
		// Name == "Test0";
		// Score == 1;
		// Name == "Test1";
		// Score == 2;
		// Name == "Test2";
		// Score == 14
		// Name == "Test13_End"
		// ならOK

		ScoreData TestData[5];
		TestData[0].Score = 13;
		TestData[0].Name = "Test13";
		TestData[1].Score = 0;
		TestData[1].Name = "Test0";
		TestData[2].Score = 1;
		TestData[2].Name = "Test1";
		TestData[3].Score = 2;
		TestData[3].Name = "Test2";
		TestData[4].Score = 14;
		TestData[4].Name = "Test13_End";

		TestListItem(*pList, TestData, _countof(TestData));
	}

	//*** 先頭の次を示すコンストなイテレータを使ってデータを挿入する。
	{
		auto ConstItr = pList->GetConstBegin();
		ScoreData Data;
		Data.Score = 15;
		Data.Name = "Test13_Center";
		++ConstItr;
		EXPECT_TRUE(pList->Insert(ConstItr, Data));
	}

	//*** 先頭の2つ次にずれているかチェック
	{
		auto Itr = pList->GetBegin();
		++Itr;
		++Itr;
		auto& Data = *Itr;
		EXPECT_EQ(0, Data.Score);
		EXPECT_EQ("Test0", Data.Name);
	}

	//*** 格納済みのデータに影響がないかチェック
	{
		// 前から順番に
		// Score == 13;
		// Name == "Test13";
		// Score == 15;
		// Name == "Test13_Center";
		// Score == 0;
		// Name == "Test0";
		// Score == 1;
		// Name == "Test1";
		// Score == 2;
		// Name == "Test2";
		// Score == 14;
		// Name == "Test13_End";
		// ならOK

		ScoreData TestData[6];
		TestData[0].Score = 13;
		TestData[0].Name = "Test13";
		TestData[1].Score = 15;
		TestData[1].Name = "Test13_Center";
		TestData[2].Score = 0;
		TestData[2].Name = "Test0";
		TestData[3].Score = 1;
		TestData[3].Name = "Test1";
		TestData[4].Score = 2;
		TestData[4].Name = "Test2";
		TestData[5].Score = 14;
		TestData[5].Name = "Test13_End";

		TestListItem(*pList, TestData, _countof(TestData));
	}
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
	ScoreData Data;
	Data.Score = 14;
	Data.Name = "Test14";

	// 何も参照していないイテレータで挿入
	LinkedList::Iterator InvalidItr;
	EXPECT_FALSE(List1.Insert(InvalidItr, Data));

	// 別のリストを参照しているイテレータで挿入
	LinkedList List2;
	auto InvalidRefItr = List2.GetBegin();
	EXPECT_FALSE(List1.Insert(InvalidRefItr, Data));
}
#pragma endregion

#pragma region ***** データの削除 *****
/**
* @brief	リストが空である場合に、削除を行った際の挙動
* @details	ID:16
*			データの削除のテストです。
*			リストが空の時に、先頭イテレータ、末尾イテレータを指定して削除した時の挙動をチェックします。
*			falseであれば成功です。
*/
TEST(DeleteData, WithEmptyListBegin)
{
	LinkedList List;

	// 先頭イテレータ
	{
		// 先頭イテレータ取得
		auto Itr = List.GetBegin();

		// 挙動チェック
		EXPECT_FALSE(List.Delete(Itr));
	}

	// 末尾イテレータ
	{
		// 末尾イテレータ取得
		auto Itr = List.GetEnd();

		// 挙動チェック
		EXPECT_FALSE(List.Delete(Itr));
	}
}

/**
* @brief	リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
* @details	ID:17
*			データの削除のテストです。
*			複数の要素がある時に、先頭イテレータを指定して削除した時の挙動をチェックします。
*			trueであれば成功です。
*/
TEST_F(DeleteDataF, WithBegin)
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
TEST_F(DeleteDataF, WithEnd)
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
TEST_F(DeleteDataF, Anywhere)
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
TEST_F(DeleteDataF, AnywhereWithConstIterator)
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
TEST_F(DeleteDataF, InvalidIterator)
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
*			ダミーノードを指すイテレータを介してデータにアクセスすると
*			Assertが発生し、stderrに Reference To DummyNode を含む文字列が
*			出力されるので、EXPECT_DEATH()を利用してテストします。
*/
TEST(GetBeginIterator, WhenEmpty)
{
#if _DEBUG
	LinkedList List;

	// 先頭イテレータ取得
	auto Itr = List.GetBegin();

	// 挙動チェック
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
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
	auto& TestData = *BeginItr;
	EXPECT_EQ(24, TestData.Score);
	EXPECT_EQ("Test24", TestData.Name);
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
	auto& TestData = *BeginItr;
	EXPECT_EQ(0, TestData.Score);
	EXPECT_EQ("Test0", TestData.Name);
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:26
*			先頭イテレータの取得のテストです。
*			先頭, 末尾, 先頭でも末尾でもない位置に挿入した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetBeginIterator, WhenInsertBegin)
{
	// リスト
	LinkedList List;

	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26_Begin";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = List.GetBegin();

	// 挙動チェック
	{
		auto& TestData = *BeginItr;
		EXPECT_EQ(26, TestData.Score);
		EXPECT_EQ("Test26_Begin", TestData.Name);
	}

	// 末尾にデータを追加する
	Data.Score = 27;
	Data.Name = "Test26_End";
	Itr = List.GetEnd();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを再取得
	BeginItr = List.GetBegin();

	// 挙動チェック
	{
		auto& TestData = *BeginItr;
		EXPECT_EQ(26, TestData.Score);
		EXPECT_EQ("Test26_Begin", TestData.Name);
	}

	// 先頭でも末尾でもない位置にデータを挿入する
	Data;
	Data.Score = 28;
	Data.Name = "Test26_Center";
	Itr = List.GetBegin();
	++Itr;
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを再取得
	BeginItr = List.GetBegin();

	// 挙動チェック
	{
		auto& TestData = *BeginItr;
		EXPECT_EQ(26, TestData.Score);
		EXPECT_EQ("Test26_Begin", TestData.Name);
	}
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:27
*			先頭イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭要素, 末尾要素, 先頭でも末尾でもない要素を削除した後に先頭イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(GetBeginIteratorF, WhenDelete)
{
	// 中央(先頭でも末尾でもない)要素を削除
	// 先頭要素を削除
	// 末尾要素を削除
	// の順で確認する。
	// なので、データが4つ以上必要になるためもう1つ追加する。
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	// 先頭イテレータを取得して、先頭でも末尾でもない要素に進める
	auto CenterItr = pList->GetBegin();
	++CenterItr;

	// 先頭でも末尾でもない要素を削除して、先頭要素を確認する
	pList->Delete(CenterItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(0, TestData.Score);
		EXPECT_EQ("Test0", TestData.Name);
	}

	// 先頭要素を削除して、先頭要素を確認する
	auto BeginItr = pList->GetBegin();
	pList->Delete(BeginItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}

	// 末尾要素を削除して、先頭要素を確認する
	auto EndItr = pList->GetEnd();
	--EndItr;
	pList->Delete(EndItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

#pragma region ***** 先頭コンストイテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:29
*			先頭コンストイテレータの取得のテストです。
*			リストが空の時に、先頭コンストイテレータを取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*			ダミーノードを指すイテレータを介してデータにアクセスすると
*			Assertが発生し、stderrに Reference To DummyNode を含む文字列が
*			出力されるので、EXPECT_DEATH()を利用してテストします。
*/
TEST(GetBeginConstIterator, WhenEmpty)
{
#ifdef _DEBUG
	LinkedList List;

	// 先頭コンストイテレータ取得
	auto Itr = List.GetConstBegin();

	// 挙動チェック
	EXPECT_DEATH({
		auto& Data = *Itr;
		}, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
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
	auto& TestData = *BeginItr;
	EXPECT_EQ(30, TestData.Score);
	EXPECT_EQ("Test30", TestData.Name);
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
	auto& TestData = *BeginItr;
	EXPECT_EQ(0, TestData.Score);
	EXPECT_EQ("Test0", TestData.Name);
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:32
*			先頭コンストイテレータの取得のテストです。
*			先頭, 末尾, 先頭でも末尾でもない位置に挿入した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetBeginConstIterator, WhenInsertBegin)
{
	// リスト
	LinkedList List;

	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32_Begin";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを取得
	auto BeginItr = List.GetConstBegin();

	// 挙動チェック
	{
		auto& TestData = *BeginItr;
		EXPECT_EQ(32, TestData.Score);
		EXPECT_EQ("Test32_Begin", TestData.Name);
	}

	// 末尾にデータを追加する
	Data.Score = 33;
	Data.Name = "Test33_End";
	Itr = List.GetEnd();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを再取得
	BeginItr = List.GetConstBegin();

	// 挙動チェック
	{
		auto& TestData = *BeginItr;
		EXPECT_EQ(32, TestData.Score);
		EXPECT_EQ("Test32_Begin", TestData.Name);
	}

	// 先頭でも末尾でもない位置にデータを挿入する
	Data;
	Data.Score = 34;
	Data.Name = "Test34_Center";
	Itr = List.GetBegin();
	++Itr;
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 先頭イテレータを再取得
	BeginItr = List.GetConstBegin();

	// 挙動チェック
	{
		auto& TestData = *BeginItr;
		EXPECT_EQ(32, TestData.Score);
		EXPECT_EQ("Test32_Begin", TestData.Name);
	}
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:33
*			先頭コンストイテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭要素, 末尾要素, 先頭でも末尾でもない要素を削除した後に先頭コンストイテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(GetBeginConstIteratorF, WhenDelete)
{
	// 中央(先頭でも末尾でもない)要素を削除
	// 先頭要素を削除
	// 末尾要素を削除
	// の順で確認する。
	// なので、データが4つ以上必要になるためもう1つ追加する。
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	// 先頭イテレータを取得して、先頭でも末尾でもない要素に進める
	auto CenterItr = pList->GetBegin();
	++CenterItr;

	// 先頭でも末尾でもない要素を削除して、先頭要素を確認する
	pList->Delete(CenterItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetConstBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(0, TestData.Score);
		EXPECT_EQ("Test0", TestData.Name);
	}

	// 先頭要素を削除して、先頭要素を確認する
	auto BeginItr = pList->GetBegin();
	pList->Delete(BeginItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetConstBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}

	// 末尾要素を削除して、先頭要素を確認する
	auto EndItr = pList->GetEnd();
	--EndItr;
	pList->Delete(EndItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetConstBegin();
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

#pragma region ***** 末尾イテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:35
*			末尾イテレータの取得のテストです。
*			リストが空の時に、末尾イテレータを取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*			ダミーノードを指すイテレータを介してデータにアクセスすると
*			Assertが発生し、stderrに Reference To DummyNode を含む文字列が
*			出力されるので、EXPECT_DEATH()を利用してテストします。
*/
TEST(GetEndIterator, WhenEmpty)
{
#ifdef _DEBUG
	LinkedList List;

	// 末尾イテレータ取得
	auto Itr = List.GetEnd();

	// 挙動チェック
	EXPECT_DEATH(*Itr, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
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
	Data.Score = 36;
	Data.Name = "Test36";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = List.GetEnd();
	--EndItr;

	// 挙動チェック
	auto& TestData = *EndItr;
	EXPECT_EQ(36, TestData.Score);
	EXPECT_EQ("Test36", TestData.Name);
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
	auto& TestData = *EndItr;
	EXPECT_EQ(1, TestData.Score);
	EXPECT_EQ("Test1", TestData.Name);
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:38
*			末尾イテレータの取得のテストです。
*			先頭, 末尾, 先頭でも末尾でもない位置に挿入した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetEndIterator, WhenInsertBegin)
{
	// リスト
	LinkedList List;

	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 38;
	Data.Name = "Test38_Begin";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = List.GetEnd();
	--EndItr;	// 適切に値を参照できないので前に進める

	// 挙動チェック
	{
		auto& TestData = *EndItr;
		EXPECT_EQ(38, TestData.Score);
		EXPECT_EQ("Test38_Begin", TestData.Name);
	}

	// 末尾にデータを追加する
	Data.Score = 39;
	Data.Name = "Test39_End";
	Itr = List.GetEnd();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを再取得
	EndItr = List.GetEnd();
	--EndItr;	// 適切に値を参照できないので前に進める

	// 挙動チェック
	{
		auto& TestData = *EndItr;
		EXPECT_EQ(39, TestData.Score);
		EXPECT_EQ("Test39_End", TestData.Name);
	}

	// 先頭でも末尾でもない位置にデータを挿入する
	Data;
	Data.Score = 40;
	Data.Name = "Test40_Center";
	Itr = List.GetBegin();
	++Itr;
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを再取得
	EndItr = List.GetEnd();
	--EndItr;	// 適切に値を参照できないので前に進める

	// 挙動チェック
	{
		auto& TestData = *EndItr;
		EXPECT_EQ(39, TestData.Score);
		EXPECT_EQ("Test39_End", TestData.Name);
	}
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:39
*			末尾イテレータの取得のテストです。
*			リストに複数の要素があるとき、先頭要素, 末尾要素, 先頭でも末尾でもない要素を削除した後に末尾イテレータを取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(GetEndIteratorF, WhenDelete)
{
	// 中央(先頭でも末尾でもない)要素を削除
	// 先頭要素を削除
	// 末尾要素を削除
	// の順で確認する。
	// なので、データが4つ以上必要になるためもう1つ追加する。
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	// 先頭イテレータを取得して、先頭でも末尾でもない要素に進める
	auto CenterItr = pList->GetBegin();
	++CenterItr;

	// 先頭でも末尾でもない要素を削除して、末尾要素を確認する
	pList->Delete(CenterItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetEnd();
		--TestItr;		// 適切に値を参照できないので前に進める
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	// 先頭要素を削除して、末尾要素を確認する
	auto BeginItr = pList->GetBegin();
	pList->Delete(BeginItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetEnd();
		--TestItr;		// 適切に値を参照できないので前に進める
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	// 末尾要素を削除して、末尾要素を確認する
	auto EndItr = pList->GetEnd();
	--EndItr;
	pList->Delete(EndItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetEnd();
		--TestItr;		// 適切に値を参照できないので前に進める
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

#pragma region ***** 末尾コンストイテレータの取得 *****

/**
* @brief	リストが空である場合に、呼び出した際の挙動
* @details	ID:41
*			末尾コンストイテレータの取得の取得のテストです。
*			リストが空の時に、末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			ダミーノードを指すイテレータを取得できれば成功です。
*			ダミーノードを指すイテレータを介してデータにアクセスすると
*			Assertが発生し、stderrに Reference To DummyNode を含む文字列が
*			出力されるので、EXPECT_DEATH()を利用してテストします。
*/
TEST(GetEndConstIterator, WhenEmpty)
{
#ifdef _DEBUG
	LinkedList List;

	// 末尾コンストイテレータの取得取得
	auto Itr = List.GetConstEnd();

	// 挙動チェック
	EXPECT_DEATH({
		auto& Data = *Itr;
		}, ".*Reference To DummyNode.*");
#else
	SUCCEED();
#endif
}

/**
* @brief	リストに要素が一つある場合に、呼び出した際の挙動
* @details	ID:42
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに1つの要素があるとき、末尾コンストイテレータを取得した時の挙動をチェックします。
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

	// 末尾コンストイテレータの取得
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// 挙動チェック
	auto& TestData = *EndItr;
	EXPECT_EQ(42, TestData.Score);
	EXPECT_EQ("Test42", TestData.Name);
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
	auto& TestData = *EndItr;
	EXPECT_EQ(1, TestData.Score);
	EXPECT_EQ("Test1", TestData.Name);
}

/**
* @brief	データの挿入を行った後に、呼び出した際の挙動
* @details	ID:44
*			末尾コンストイテレータの取得の取得のテストです。
*			先頭, 末尾, 先頭でも末尾でもない位置に挿入した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST(GetEndConstIterator, WhenInsert)
{
	// リスト
	LinkedList List;

	// 先頭にデータを挿入する
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44_Begin";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを取得
	auto EndItr = List.GetConstEnd();
	--EndItr;	// 適切に値を参照できないので前に進める

	// 挙動チェック
	{
		auto& TestData = *EndItr;
		EXPECT_EQ(44, TestData.Score);
		EXPECT_EQ("Test44_Begin", TestData.Name);
	}

	// 末尾にデータを追加する
	Data.Score = 45;
	Data.Name = "Test45_End";
	Itr = List.GetEnd();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを再取得
	EndItr = List.GetConstEnd();
	--EndItr;	// 適切に値を参照できないので前に進める

	// 挙動チェック
	{
		auto& TestData = *EndItr;
		EXPECT_EQ(45, TestData.Score);
		EXPECT_EQ("Test45_End", TestData.Name);
	}

	// 先頭でも末尾でもない位置にデータを挿入する
	Data;
	Data.Score = 46;
	Data.Name = "Test46_Center";
	Itr = List.GetBegin();
	++Itr;
	ASSERT_TRUE(List.Insert(Itr, Data));

	// 末尾イテレータを再取得
	EndItr = List.GetConstEnd();
	--EndItr;	// 適切に値を参照できないので前に進める

	// 挙動チェック
	{
		auto& TestData = *EndItr;
		EXPECT_EQ(45, TestData.Score);
		EXPECT_EQ("Test45_End", TestData.Name);
	}
}

/**
* @brief	データの削除を行った後に、呼び出した際の挙動
* @details	ID:45
*			末尾コンストイテレータの取得の取得のテストです。
*			リストに複数の要素があるとき、先頭要素, 末尾要素, 先頭でも末尾でもない要素を削除した後に末尾コンストイテレータの取得を取得した時の挙動をチェックします。
*			先頭要素を指すイテレータを取得できれば成功です。
*/
TEST_F(GetEndConstIteratorF, WhenDelete)
{
	// 中央(先頭でも末尾でもない)要素を削除
	// 先頭要素を削除
	// 末尾要素を削除
	// の順で確認する。
	// なので、データが4つ以上必要になるためもう1つ追加する。
	{
		ScoreData Data{ 3, "Test3" };
		auto Itr = pList->GetEnd();
		pList->Insert(Itr, Data);
	}

	// 先頭イテレータを取得して、先頭でも末尾でもない要素に進める
	auto CenterItr = pList->GetBegin();
	++CenterItr;

	// 先頭でも末尾でもない要素を削除して、末尾要素を確認する
	pList->Delete(CenterItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetConstEnd();
		--TestItr;		// 適切に値を参照できないので前に進める

		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	// 先頭要素を削除して、末尾要素を確認する
	auto BeginItr = pList->GetBegin();
	pList->Delete(BeginItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetConstEnd();
		--TestItr;		// 適切に値を参照できないので前に進める
		auto& TestData = *TestItr;
		EXPECT_EQ(3, TestData.Score);
		EXPECT_EQ("Test3", TestData.Name);
	}

	// 末尾要素を削除して、末尾要素を確認する
	auto EndItr = pList->GetEnd();
	--EndItr;
	pList->Delete(EndItr);

	// 挙動チェック
	{
		auto TestItr = pList->GetConstEnd();
		--TestItr;		// 適切に値を参照できないので前に進める
		auto& TestData = *TestItr;
		EXPECT_EQ(2, TestData.Score);
		EXPECT_EQ("Test2", TestData.Name);
	}
}

#pragma endregion

}	// ex01_LinkedList
