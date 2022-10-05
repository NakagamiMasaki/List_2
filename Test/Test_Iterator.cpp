/**
* @file		Test_Iterator.cpp
* @brief	イテレータの単体テスト用
* @data		2022/10/04
*/

//===== インクルード =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "TestHelper.h"

namespace ex02_Iterator
{

#pragma region ***** イテレータの指す要素を取得する *****

/**
* @brief	リストの参照がない状態で呼び出した際の挙動
* @details	ID:0
*			イテレータの指す要素を取得するテストです。
*			リストの参照がないイテレータから要素を取り出そうとした時の挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(GetIteratorData, InvalidReference)
{
	LinkedList::Iterator Itr;
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	リストの参照がない状態で呼び出した際の挙動
* @details	ID:0
*			イテレータの指す要素を取得するテストです。
*			リストの参照がないコンストなイテレータから要素を取り出そうとした時の挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(GetConstIteratorData, InvalidReference)
{
	LinkedList::ConstIterator Itr;
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	Iteratorから取得した要素に対して、値の代入が行えるかをチェック
* @details	ID:1
*			イテレータの指す要素を取得するテストです。
*			イテレータから取得した要素に代入ができるかの確認をします。
*			値を代入したあと、再び取得した時にデータが変わっていたら成功です。
*/
TEST(GetIteratorData, AfterAssignment)
{
	// 1件データを追加しておく
	LinkedList List;
	ScoreData Data;
	Data.Score = 0;
	Data.Name = "Test0";
	List.Pushback(Data);

	// 値を代入する
	auto Itr = List.GetBegin();
	auto& Element = *Itr;
	Element.Name = "Test1";
	Element.Score = 1;

	// イテレータを取得しなおして確認する
	Itr = List.GetBegin();
	EXPECT_EQ(1, Itr->Score);
	EXPECT_EQ("Test1", Itr->Name);
}

/**
* @brief	リストが空の際の、先頭イテレータに対して呼び出した際の挙動
* @details	ID:3
*			イテレータの指す要素を取得するテストです。
*			リストが空の時、先頭イテレータから要素を取り出そうとしたときの挙動の確認をします。
*			Assertが発生したら成功です。
*/
TEST(GetIteratorData, EmptyListBeginIterator)
{
	// 空のリストを用意する
	LinkedList List;

	// イテレータを取得して確認する
	auto Itr = List.GetBegin();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	リストが空の際の、先頭イテレータに対して呼び出した際の挙動
* @details	ID:3
*			イテレータの指す要素を取得するテストです。
*			リストが空の時、コンストな先頭イテレータから要素を取り出そうとしたときの挙動の確認をします。
*			Assertが発生したら成功です。
*/
TEST(GetConstIteratorData, EmptyListBeginIterator)
{
	// 空のリストを用意する
	LinkedList List;

	// イテレータを取得して確認する
	auto Itr = List.GetConstBegin();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	末尾イテレータに対して呼び出した際の挙動
* @details	ID:4
*			イテレータの指す要素を取得するテストです。
*			リストが空の時、末尾イテレータから要素を取り出そうとしたときの挙動の確認をします。
*			Assertが発生したら成功です。
*/
TEST(GetIteratorData, EndIterator)
{
	// 空のリストを用意する
	LinkedList List;

	// イテレータを取得して確認する
	auto Itr = List.GetEnd();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	末尾イテレータに対して呼び出した際の挙動
* @details	ID:4
*			イテレータの指す要素を取得するテストです。
*			リストが空の時、コンストな末尾イテレータから要素を取り出そうとしたときの挙動の確認をします。
*			Assertが発生したら成功です。
*/
TEST(GetConstIteratorData, EndIterator)
{
	// 空のリストを用意する
	LinkedList List;

	// イテレータを取得して確認する
	auto Itr = List.GetConstEnd();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

#pragma endregion

#pragma region ***** イテレータをリストの末尾に向かって一つ進める *****

/**
* @brief	リストの参照がない状態で呼び出した際の挙動
* @details	ID:5
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			リストの参照がないとき、末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(IteratorIncrement, InvalidReference)
{
	LinkedList::Iterator Itr;
	EXPECT_DEATH(++Itr , "");
}

/**
* @brief	リストの参照がない状態で呼び出した際の挙動
* @details	ID:5
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			リストの参照がないとき、コンストなイテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(ConstIteratorIncrement, InvalidReference)
{
	LinkedList::ConstIterator Itr;
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	リストが空の際の、先頭イテレータに対して呼び出した際の挙動
* @details	ID:6
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			リストが空の時、末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(IteratorIncrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetBegin();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	リストが空の際の、先頭イテレータに対して呼び出した際の挙動
* @details	ID:6
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			リストが空の時、コンストなイテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(ConstIteratorIncrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetConstBegin();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	末尾イテレータに対して呼び出した際の挙動
* @details	ID:7
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			末尾イテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(IteratorIncrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetEnd();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	末尾イテレータに対して呼び出した際の挙動
* @details	ID:7
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			コンストな末尾イテレータをコンストなイテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(ConstIteratorIncrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetConstEnd();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	リストに二つ以上の要素がある場合に呼び出した際の挙動
* @details	ID:8
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			先頭から末尾まで呼び出しを行い、期待される要素が入っているか確認します。
*			期待される要素が入っていれば成功です。
*/
TEST_F(LinkedListTestFixture, IteratorIncrementBeginToEnd)
{
	ScoreData TestData[3];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 1;
	TestData[1].Name = "Test1";
	TestData[2].Score = 2;
	TestData[2].Name = "Test2";

	auto Itr = pList->GetBegin();
	for (int i = 0; i < 3; ++i)
	{
		// 正しいかチェック
		EXPECT_EQ(TestData[i].Score, Itr->Score);
		EXPECT_EQ(TestData[i].Name, Itr->Name);

		++Itr;
	}
}

/**
* @brief	リストに二つ以上の要素がある場合に呼び出した際の挙動
* @details	ID:8
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			コンストなイテレータで先頭から末尾まで呼び出しを行い、期待される要素が入っているか確認します。
*			期待される要素が入っていれば成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorIncrementBeginToEnd)
{
	ScoreData TestData[3];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 1;
	TestData[1].Name = "Test1";
	TestData[2].Score = 2;
	TestData[2].Name = "Test2";

	auto Itr = pList->GetConstBegin();
	for (int i = 0; i < 3; ++i)
	{
		// 正しいかチェック
		EXPECT_EQ(TestData[i].Score, Itr->Score);
		EXPECT_EQ(TestData[i].Name, Itr->Name);

		++Itr;
	}
}

/**
* @brief	前置インクリメントを行った際の挙動
* @details	ID:9
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			インクリメント時の値とインクリメント後の値を確認します。
*			次の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, IteratorPrefixIncrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetBegin();

	EXPECT_EQ(1, (++Itr)->Score);	// 前置インクリメントなので戻り値は変更後のはず
	EXPECT_EQ(1, Itr->Score);		// 次を指しているかチェック
}

/**
* @brief	前置インクリメントを行った際の挙動
* @details	ID:9
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			コンストなイテレータの、インクリメント時の値とインクリメント後の値を確認します。
*			次の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorPrefixIncrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetConstBegin();

	EXPECT_EQ(1, (++Itr)->Score);	// 前置インクリメントなので戻り値は変更後のはず
	EXPECT_EQ(1, Itr->Score);		// 次を指しているかチェック
}

/**
* @brief	後置インクリメントを行った際の挙動
* @details	ID:10
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			インクリメント時の値とインクリメント後の値を確認します。
*			次の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, IteratorPostfixIncrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetBegin();

	EXPECT_EQ(0, (Itr++)->Score);	// 後置インクリメントなので戻り値は変更前のはず
	EXPECT_EQ(1, Itr->Score);		// 次を指しているかチェック
}

/**
* @brief	後置インクリメントを行った際の挙動
* @details	ID:10
*			イテレータをリストの末尾に向かって一つ進めるテストです。
*			コンストなイテレータの、インクリメント時の値とインクリメント後の値を確認します。
*			次の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorPostfixIncrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetConstBegin();

	EXPECT_EQ(0, (Itr++)->Score);	// 前置インクリメントなので戻り値は変更前のはず
	EXPECT_EQ(1, Itr->Score);		// 次を指しているかチェック
}

#pragma endregion

#pragma region ***** イテレータをリストの先頭に向かって一つ進める *****

/**
* @brief	リストの参照がない状態で呼び出した際の挙動
* @details	ID:11
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			リストの参照がないとき、末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(IteratorDecrement, InvalidReference)
{
	LinkedList::Iterator Itr;
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	リストの参照がない状態で呼び出した際の挙動
* @details	ID:11
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			リストの参照がないとき、コンストなイテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(ConstIteratorDecrement, InvalidReference)
{
	LinkedList::ConstIterator Itr;
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	リストが空の際の、先頭イテレータに対して呼び出した際の挙動
* @details	ID:12
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			リストが空の時、末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(IteratorDecrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetBegin();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	リストが空の際の、先頭イテレータに対して呼び出した際の挙動
* @details	ID:12
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			リストが空の時、コンストなイテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(ConstIteratorDecrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetConstBegin();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	末尾イテレータに対して呼び出した際の挙動
* @details	ID:13
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			末尾イテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(IteratorDecrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetEnd();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	末尾イテレータに対して呼び出した際の挙動
* @details	ID:13
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			コンストな末尾イテレータをコンストなイテレータを末尾に向かって進めたときの挙動をチェックします。
*			Assertが発生したら成功です。
*/
TEST(ConstIteratorDecrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetConstEnd();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	リストに二つ以上の要素がある場合に呼び出した際の挙動
* @details	ID:14
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			先頭から末尾まで呼び出しを行い、期待される要素が入っているか確認します。
*			期待される要素が入っていれば成功です。
*/
TEST_F(LinkedListTestFixture, IteratorDecrementEndToBegin)
{
	ScoreData TestData[3];
	TestData[0].Score = 2;
	TestData[0].Name = "Test2";
	TestData[1].Score = 1;
	TestData[1].Name = "Test1";
	TestData[2].Score = 0;
	TestData[2].Name = "Test0";

	auto Itr = pList->GetEnd();
	for (int i = 0; i < 3; ++i)
	{
		--Itr;
		EXPECT_EQ(TestData[i].Score, Itr->Score);
		EXPECT_EQ(TestData[i].Name, Itr->Name);
	}
}

/**
* @brief	リストに二つ以上の要素がある場合に呼び出した際の挙動
* @details	ID:14
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			コンストなイテレータで先頭から末尾まで呼び出しを行い、期待される要素が入っているか確認します。
*			期待される要素が入っていれば成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorDecrementEndToBegin)
{
	ScoreData TestData[3];
	TestData[0].Score = 2;
	TestData[0].Name = "Test2";
	TestData[1].Score = 1;
	TestData[1].Name = "Test1";
	TestData[2].Score = 0;
	TestData[2].Name = "Test0";

	auto Itr = pList->GetConstEnd();
	for (int i = 0; i < 3; ++i)
	{
		--Itr;
		EXPECT_EQ(TestData[i].Score, Itr->Score);
		EXPECT_EQ(TestData[i].Name, Itr->Name);
	}
}

/**
* @brief	前置デクリメント行った際の挙動
* @details	ID:15
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			デクリメント時の値とデクリメント後の値を確認します。
*			前の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, IteratorPrefixDecrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetEnd();

	EXPECT_EQ(2, (--Itr)->Score);	// 前置デクリメントなので戻り値は変更後のはず
	EXPECT_EQ(2, Itr->Score);		// 前を指しているかチェック
}

/**
* @brief	前置デクリメント行った際の挙動
* @details	ID:15
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			コンストなイテレータの、デクリメント時の値とデクリメント後の値を確認します。
*			前の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorPrefixDecrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetConstEnd();

	EXPECT_EQ(2, (--Itr)->Score);	// 前置デクリメントなので戻り値は変更後のはず
	EXPECT_EQ(2, Itr->Score);		// 前を指しているかチェック
}

/**
* @brief	後置デクリメントを行った際の挙動
* @details	ID:16
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			デクリメント時の値とデクリメント後の値を確認します。
*			前の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, IteratorPostfixDecrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetEnd();

	--Itr;	// ここでデクリメントしておかないとダミーノードにアクセスしてしまう

	EXPECT_EQ(2, (Itr--)->Score);	// 後置デクリメントなので戻り値は変更前のはず
	EXPECT_EQ(1, Itr->Score);		// 前を指しているかチェック
}

/**
* @brief	後置デクリメントを行った際の挙動
* @details	ID:16
*			イテレータをリストの先頭に向かって一つ進めるテストです。
*			コンストなイテレータの、デクリメント時の値とデクリメント後の値を確認します。
*			前の要素を指していたら成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorPostfixDecrement)
{
	// 先頭イテレータ
	auto Itr = pList->GetConstEnd();

	--Itr;	// ここでデクリメントしておかないとダミーノードにアクセスしてしまう

	EXPECT_EQ(2, (Itr--)->Score);	// 前置インクリメントなので戻り値は変更前のはず
	EXPECT_EQ(1, Itr->Score);		// 前を指しているかチェック
}

#pragma endregion

#pragma region ***** イテレータのコピーを行う *****

/**
* @brief	コピーコンストラクト後の値がコピー元と等しいことをチェック
* @details	ID:18
*			コピーコンストラクタでコピーしたイテレータがコピー元と同一であることを確認するテストです。
*			コピーして作成したイテレータとコピー元が同一であれば成功です。
*/
TEST_F(LinkedListTestFixture, IteratorCopyConstractor)
{
	auto Itr = pList->GetBegin();

	// コピー
	LinkedList::Iterator CopyItr(Itr);

	// チェック
	EXPECT_TRUE(CopyItr == Itr);
}

/**
* @brief	コピーコンストラクト後の値がコピー元と等しいことをチェック
* @details	ID:18
*			コピーコンストラクタでコピーしたコンストなイテレータがコピー元と同一であることを確認するテストです。
*			コピーして作成したイテレータとコピー元が同一であれば成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorCopyConstractor)
{
	auto Itr = pList->GetConstBegin();

	// コピー
	LinkedList::ConstIterator CopyItr(Itr);

	// チェック
	EXPECT_TRUE(CopyItr == Itr);
}

#pragma endregion

#pragma region ***** イテレータの代入を行う *****

/**
* @brief	代入後の値がコピー元と等しいことをチェック
* @details	ID:20
*			コピー代入ででコピーしたイテレータがコピー元と同一であることを確認するテストです。
*			コピーして作成したイテレータとコピー元が同一であれば成功です。
*/
TEST_F(LinkedListTestFixture, IteratorCopyAssignmentConstractor)
{
	auto Itr = pList->GetBegin();

	// コピー
	LinkedList::Iterator CopyItr;
	CopyItr = Itr;

	// チェック
	EXPECT_TRUE(CopyItr == Itr);
}

/**
* @brief	代入後の値がコピー元と等しいことをチェック
* @details	ID:20
*			コピー代入でコピーしたコンストなイテレータがコピー元と同一であることを確認するテストです。
*			コピーして作成したイテレータとコピー元が同一であれば成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorCopyAssignmentConstractor)
{
	auto Itr = pList->GetConstBegin();

	// コピー
	LinkedList::ConstIterator CopyItr;
	CopyItr = Itr;

	// チェック
	EXPECT_TRUE(CopyItr == Itr);
}

#pragma endregion

#pragma region ***** 2つのイテレータが同一のものであるか比較を行う *****

/**
* @brief	リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
* @details	ID:21
*			空のリストから取得した先頭イテレータと末尾イテレータを比較するテストです。
*			trueが返れば成功です。
*/
TEST(IteratorCompareEQ, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetBegin();
	auto EndItr = List.GetEnd();

	// 同一であるか確認
	EXPECT_TRUE(BeginItr == EndItr);
}

/**
* @brief	リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
* @details	ID:21
*			空のリストから取得したコンストな先頭イテレータとコンストな末尾イテレータを比較するテストです。
*			trueが返れば成功です。
*/
TEST(ConstIteratorCompareEQ, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetConstBegin();
	auto EndItr = List.GetConstEnd();

	// 同一であるか確認
	EXPECT_TRUE(BeginItr == EndItr);
}

/**
* @brief	同一のイテレータを比較した際の挙動
* @details	ID:22
*			同一のイテレータどうしで比較した時の挙動をチェックします。
*			trueが返れば成功です。
*/
TEST_F(LinkedListTestFixture, IteratorCompareEQ)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	// 同一であるか確認
	EXPECT_TRUE(BeginItr == Itr);
}

/**
* @brief	同一のイテレータを比較した際の挙動
* @details	ID:22
*			同一のコンストなイテレータどうしで比較した時の挙動をチェックします。
*			trueが返れば成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorCompareEQ)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	// 同一であるか確認
	EXPECT_TRUE(BeginItr == Itr);
}

/**
* @brief	異なるイテレータを比較した際の挙動
* @details	ID:23
*			異なるイテレータどうしで比較した時の挙動をチェックします。
*			falseが返れば成功です。
*/
TEST_F(LinkedListTestFixture, DiffrentIteratorCompareEQ)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	++Itr;	// ずらすことで別のイテレータにする

	// 同一であるか確認
	EXPECT_FALSE(BeginItr == Itr);
}

/**
* @brief	異なるイテレータを比較した際の挙動
* @details	ID:23
*			異なるコンストなイテレータどうしで比較した時の挙動をチェックします。
*			falseが返れば成功です。
*/
TEST_F(LinkedListTestFixture, DiffrentConstIteratorCompareEQ)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	++Itr;	// ずらすことで別のイテレータにする

	// 同一であるか確認
	EXPECT_FALSE(BeginItr == Itr);
}

#pragma endregion

#pragma region ***** 2つのイテレータが異なるのものであるか比較を行う *****

/**
* @brief	リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
* @details	ID:24
*			空のリストから取得した先頭イテレータと末尾イテレータを比較するテストです。
*			falseが返れば成功です。
*/
TEST(IteratorCompareNE, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetBegin();
	auto EndItr = List.GetEnd();

	// 異なるか確認
	EXPECT_FALSE(BeginItr != EndItr);
}

/**
* @brief	リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
* @details	ID:24
*			空のリストから取得したコンストな先頭イテレータとコンストな末尾イテレータを比較するテストです。
*			falseが返れば成功です。
*/
TEST(ConstIteratorCompareNE, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetConstBegin();
	auto EndItr = List.GetConstEnd();

	// 異なるか確認
	EXPECT_FALSE(BeginItr != EndItr);
}

/**
* @brief	同一のイテレータを比較した際の挙動
* @details	ID:25
*			同一のイテレータどうしで比較した時の挙動をチェックします。
*			falseが返れば成功です。
*/
TEST_F(LinkedListTestFixture, IteratorCompareNE)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	// 異なるか確認
	EXPECT_FALSE(BeginItr != Itr);
}

/**
* @brief	同一のイテレータを比較した際の挙動
* @details	ID:25
*			同一のコンストなイテレータどうしで比較した時の挙動をチェックします。
*			falseが返れば成功です。
*/
TEST_F(LinkedListTestFixture, ConstIteratorCompareNE)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	// 異なるか確認
	EXPECT_FALSE(BeginItr != Itr);
}

/**
* @brief	異なるイテレータを比較した際の挙動
* @details	ID:23
*			異なるイテレータどうしで比較した時の挙動をチェックします。
*			trueが返れば成功です。
*/
TEST_F(LinkedListTestFixture, DiffrentIteratorCompareNE)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	++Itr;	// ずらすことで別のイテレータにする

	// 異なるか確認
	EXPECT_TRUE(BeginItr != Itr);
}

/**
* @brief	異なるイテレータを比較した際の挙動
* @details	ID:23
*			異なるコンストなイテレータどうしで比較した時の挙動をチェックします。
*			trueが返れば成功です。
*/
TEST_F(LinkedListTestFixture, DiffrentConstIteratorCompareNE)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	++Itr;	// ずらすことで別のイテレータにする

	// 異なるか確認
	EXPECT_TRUE(BeginItr != Itr);
}

#pragma endregion


}	// ex02_Iterator