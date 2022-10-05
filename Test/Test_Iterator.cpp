/**
* @file		Test_Iterator.cpp
* @brief	�C�e���[�^�̒P�̃e�X�g�p
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "TestHelper.h"

namespace ex02_Iterator
{

#pragma region ***** �C�e���[�^�̎w���v�f���擾���� *****

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:0
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��C�e���[�^����v�f�����o�����Ƃ������̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetIteratorData, InvalidReference)
{
	LinkedList::Iterator Itr;
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:0
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��R���X�g�ȃC�e���[�^����v�f�����o�����Ƃ������̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetConstIteratorData, InvalidReference)
{
	LinkedList::ConstIterator Itr;
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
* @details	ID:1
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			�C�e���[�^����擾�����v�f�ɑ�����ł��邩�̊m�F�����܂��B
*			�l�����������ƁA�Ăю擾�������Ƀf�[�^���ς���Ă����琬���ł��B
*/
TEST(GetIteratorData, AfterAssignment)
{
	// 1���f�[�^��ǉ����Ă���
	LinkedList List;
	ScoreData Data;
	Data.Score = 0;
	Data.Name = "Test0";
	List.Pushback(Data);

	// �l��������
	auto Itr = List.GetBegin();
	auto& Element = *Itr;
	Element.Name = "Test1";
	Element.Score = 1;

	// �C�e���[�^���擾���Ȃ����Ċm�F����
	Itr = List.GetBegin();
	EXPECT_EQ(1, Itr->Score);
	EXPECT_EQ("Test1", Itr->Name);
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:3
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g����̎��A�擪�C�e���[�^����v�f�����o�����Ƃ����Ƃ��̋����̊m�F�����܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetIteratorData, EmptyListBeginIterator)
{
	// ��̃��X�g��p�ӂ���
	LinkedList List;

	// �C�e���[�^���擾���Ċm�F����
	auto Itr = List.GetBegin();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:3
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g����̎��A�R���X�g�Ȑ擪�C�e���[�^����v�f�����o�����Ƃ����Ƃ��̋����̊m�F�����܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetConstIteratorData, EmptyListBeginIterator)
{
	// ��̃��X�g��p�ӂ���
	LinkedList List;

	// �C�e���[�^���擾���Ċm�F����
	auto Itr = List.GetConstBegin();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:4
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g����̎��A�����C�e���[�^����v�f�����o�����Ƃ����Ƃ��̋����̊m�F�����܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetIteratorData, EndIterator)
{
	// ��̃��X�g��p�ӂ���
	LinkedList List;

	// �C�e���[�^���擾���Ċm�F����
	auto Itr = List.GetEnd();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:4
*			�C�e���[�^�̎w���v�f���擾����e�X�g�ł��B
*			���X�g����̎��A�R���X�g�Ȗ����C�e���[�^����v�f�����o�����Ƃ����Ƃ��̋����̊m�F�����܂��B
*			Assert�����������琬���ł��B
*/
TEST(GetConstIteratorData, EndIterator)
{
	// ��̃��X�g��p�ӂ���
	LinkedList List;

	// �C�e���[�^���擾���Ċm�F����
	auto Itr = List.GetConstEnd();
	EXPECT_DEATH(Itr->Name == "Dummy", "");
}

#pragma endregion

#pragma region ***** �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� *****

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:5
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��Ƃ��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorIncrement, InvalidReference)
{
	LinkedList::Iterator Itr;
	EXPECT_DEATH(++Itr , "");
}

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:5
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��Ƃ��A�R���X�g�ȃC�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(ConstIteratorIncrement, InvalidReference)
{
	LinkedList::ConstIterator Itr;
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:6
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g����̎��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorIncrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetBegin();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:6
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g����̎��A�R���X�g�ȃC�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(ConstIteratorIncrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetConstBegin();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:7
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�����C�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorIncrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetEnd();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:7
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�Ȗ����C�e���[�^���R���X�g�ȃC�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(ConstIteratorIncrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetConstEnd();
	EXPECT_DEATH(++Itr, "");
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
* @details	ID:8
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�擪���疖���܂ŌĂяo�����s���A���҂����v�f�������Ă��邩�m�F���܂��B
*			���҂����v�f�������Ă���ΐ����ł��B
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
		// ���������`�F�b�N
		EXPECT_EQ(TestData[i].Score, Itr->Score);
		EXPECT_EQ(TestData[i].Name, Itr->Name);

		++Itr;
	}
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
* @details	ID:8
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�Ő擪���疖���܂ŌĂяo�����s���A���҂����v�f�������Ă��邩�m�F���܂��B
*			���҂����v�f�������Ă���ΐ����ł��B
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
		// ���������`�F�b�N
		EXPECT_EQ(TestData[i].Score, Itr->Score);
		EXPECT_EQ(TestData[i].Name, Itr->Name);

		++Itr;
	}
}

/**
* @brief	�O�u�C���N�������g���s�����ۂ̋���
* @details	ID:9
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�C���N�������g���̒l�ƃC���N�������g��̒l���m�F���܂��B
*			���̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, IteratorPrefixIncrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetBegin();

	EXPECT_EQ(1, (++Itr)->Score);	// �O�u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
	EXPECT_EQ(1, Itr->Score);		// �����w���Ă��邩�`�F�b�N
}

/**
* @brief	�O�u�C���N�������g���s�����ۂ̋���
* @details	ID:9
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�́A�C���N�������g���̒l�ƃC���N�������g��̒l���m�F���܂��B
*			���̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorPrefixIncrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetConstBegin();

	EXPECT_EQ(1, (++Itr)->Score);	// �O�u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
	EXPECT_EQ(1, Itr->Score);		// �����w���Ă��邩�`�F�b�N
}

/**
* @brief	��u�C���N�������g���s�����ۂ̋���
* @details	ID:10
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�C���N�������g���̒l�ƃC���N�������g��̒l���m�F���܂��B
*			���̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, IteratorPostfixIncrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetBegin();

	EXPECT_EQ(0, (Itr++)->Score);	// ��u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
	EXPECT_EQ(1, Itr->Score);		// �����w���Ă��邩�`�F�b�N
}

/**
* @brief	��u�C���N�������g���s�����ۂ̋���
* @details	ID:10
*			�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�́A�C���N�������g���̒l�ƃC���N�������g��̒l���m�F���܂��B
*			���̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorPostfixIncrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetConstBegin();

	EXPECT_EQ(0, (Itr++)->Score);	// �O�u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
	EXPECT_EQ(1, Itr->Score);		// �����w���Ă��邩�`�F�b�N
}

#pragma endregion

#pragma region ***** �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� *****

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:11
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��Ƃ��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorDecrement, InvalidReference)
{
	LinkedList::Iterator Itr;
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
* @details	ID:11
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g�̎Q�Ƃ��Ȃ��Ƃ��A�R���X�g�ȃC�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(ConstIteratorDecrement, InvalidReference)
{
	LinkedList::ConstIterator Itr;
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:12
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g����̎��A�����Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorDecrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetBegin();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:12
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			���X�g����̎��A�R���X�g�ȃC�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(ConstIteratorDecrement, EmptyListBeginIterator)
{
	LinkedList List;
	auto Itr = List.GetConstBegin();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:13
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�����C�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(IteratorDecrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetEnd();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
* @details	ID:13
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�Ȗ����C�e���[�^���R���X�g�ȃC�e���[�^�𖖔��Ɍ������Đi�߂��Ƃ��̋������`�F�b�N���܂��B
*			Assert�����������琬���ł��B
*/
TEST(ConstIteratorDecrement, EndIterator)
{
	LinkedList List;
	auto Itr = List.GetConstEnd();
	EXPECT_DEATH(--Itr, "");
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
* @details	ID:14
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�擪���疖���܂ŌĂяo�����s���A���҂����v�f�������Ă��邩�m�F���܂��B
*			���҂����v�f�������Ă���ΐ����ł��B
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
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
* @details	ID:14
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�Ő擪���疖���܂ŌĂяo�����s���A���҂����v�f�������Ă��邩�m�F���܂��B
*			���҂����v�f�������Ă���ΐ����ł��B
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
* @brief	�O�u�f�N�������g�s�����ۂ̋���
* @details	ID:15
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�f�N�������g���̒l�ƃf�N�������g��̒l���m�F���܂��B
*			�O�̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, IteratorPrefixDecrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetEnd();

	EXPECT_EQ(2, (--Itr)->Score);	// �O�u�f�N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
	EXPECT_EQ(2, Itr->Score);		// �O���w���Ă��邩�`�F�b�N
}

/**
* @brief	�O�u�f�N�������g�s�����ۂ̋���
* @details	ID:15
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�́A�f�N�������g���̒l�ƃf�N�������g��̒l���m�F���܂��B
*			�O�̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorPrefixDecrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetConstEnd();

	EXPECT_EQ(2, (--Itr)->Score);	// �O�u�f�N�������g�Ȃ̂Ŗ߂�l�͕ύX��̂͂�
	EXPECT_EQ(2, Itr->Score);		// �O���w���Ă��邩�`�F�b�N
}

/**
* @brief	��u�f�N�������g���s�����ۂ̋���
* @details	ID:16
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�f�N�������g���̒l�ƃf�N�������g��̒l���m�F���܂��B
*			�O�̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, IteratorPostfixDecrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetEnd();

	--Itr;	// �����Ńf�N�������g���Ă����Ȃ��ƃ_�~�[�m�[�h�ɃA�N�Z�X���Ă��܂�

	EXPECT_EQ(2, (Itr--)->Score);	// ��u�f�N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
	EXPECT_EQ(1, Itr->Score);		// �O���w���Ă��邩�`�F�b�N
}

/**
* @brief	��u�f�N�������g���s�����ۂ̋���
* @details	ID:16
*			�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�́A�f�N�������g���̒l�ƃf�N�������g��̒l���m�F���܂��B
*			�O�̗v�f���w���Ă����琬���ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorPostfixDecrement)
{
	// �擪�C�e���[�^
	auto Itr = pList->GetConstEnd();

	--Itr;	// �����Ńf�N�������g���Ă����Ȃ��ƃ_�~�[�m�[�h�ɃA�N�Z�X���Ă��܂�

	EXPECT_EQ(2, (Itr--)->Score);	// �O�u�C���N�������g�Ȃ̂Ŗ߂�l�͕ύX�O�̂͂�
	EXPECT_EQ(1, Itr->Score);		// �O���w���Ă��邩�`�F�b�N
}

#pragma endregion

#pragma region ***** �C�e���[�^�̃R�s�[���s�� *****

/**
* @brief	�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
* @details	ID:18
*			�R�s�[�R���X�g���N�^�ŃR�s�[�����C�e���[�^���R�s�[���Ɠ���ł��邱�Ƃ��m�F����e�X�g�ł��B
*			�R�s�[���č쐬�����C�e���[�^�ƃR�s�[��������ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, IteratorCopyConstractor)
{
	auto Itr = pList->GetBegin();

	// �R�s�[
	LinkedList::Iterator CopyItr(Itr);

	// �`�F�b�N
	EXPECT_TRUE(CopyItr == Itr);
}

/**
* @brief	�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
* @details	ID:18
*			�R�s�[�R���X�g���N�^�ŃR�s�[�����R���X�g�ȃC�e���[�^���R�s�[���Ɠ���ł��邱�Ƃ��m�F����e�X�g�ł��B
*			�R�s�[���č쐬�����C�e���[�^�ƃR�s�[��������ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorCopyConstractor)
{
	auto Itr = pList->GetConstBegin();

	// �R�s�[
	LinkedList::ConstIterator CopyItr(Itr);

	// �`�F�b�N
	EXPECT_TRUE(CopyItr == Itr);
}

#pragma endregion

#pragma region ***** �C�e���[�^�̑�����s�� *****

/**
* @brief	�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
* @details	ID:20
*			�R�s�[����łŃR�s�[�����C�e���[�^���R�s�[���Ɠ���ł��邱�Ƃ��m�F����e�X�g�ł��B
*			�R�s�[���č쐬�����C�e���[�^�ƃR�s�[��������ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, IteratorCopyAssignmentConstractor)
{
	auto Itr = pList->GetBegin();

	// �R�s�[
	LinkedList::Iterator CopyItr;
	CopyItr = Itr;

	// �`�F�b�N
	EXPECT_TRUE(CopyItr == Itr);
}

/**
* @brief	�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
* @details	ID:20
*			�R�s�[����ŃR�s�[�����R���X�g�ȃC�e���[�^���R�s�[���Ɠ���ł��邱�Ƃ��m�F����e�X�g�ł��B
*			�R�s�[���č쐬�����C�e���[�^�ƃR�s�[��������ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorCopyAssignmentConstractor)
{
	auto Itr = pList->GetConstBegin();

	// �R�s�[
	LinkedList::ConstIterator CopyItr;
	CopyItr = Itr;

	// �`�F�b�N
	EXPECT_TRUE(CopyItr == Itr);
}

#pragma endregion

#pragma region ***** 2�̃C�e���[�^������̂��̂ł��邩��r���s�� *****

/**
* @brief	���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
* @details	ID:21
*			��̃��X�g����擾�����擪�C�e���[�^�Ɩ����C�e���[�^���r����e�X�g�ł��B
*			true���Ԃ�ΐ����ł��B
*/
TEST(IteratorCompareEQ, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetBegin();
	auto EndItr = List.GetEnd();

	// ����ł��邩�m�F
	EXPECT_TRUE(BeginItr == EndItr);
}

/**
* @brief	���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
* @details	ID:21
*			��̃��X�g����擾�����R���X�g�Ȑ擪�C�e���[�^�ƃR���X�g�Ȗ����C�e���[�^���r����e�X�g�ł��B
*			true���Ԃ�ΐ����ł��B
*/
TEST(ConstIteratorCompareEQ, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetConstBegin();
	auto EndItr = List.GetConstEnd();

	// ����ł��邩�m�F
	EXPECT_TRUE(BeginItr == EndItr);
}

/**
* @brief	����̃C�e���[�^���r�����ۂ̋���
* @details	ID:22
*			����̃C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			true���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, IteratorCompareEQ)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	// ����ł��邩�m�F
	EXPECT_TRUE(BeginItr == Itr);
}

/**
* @brief	����̃C�e���[�^���r�����ۂ̋���
* @details	ID:22
*			����̃R���X�g�ȃC�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			true���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorCompareEQ)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	// ����ł��邩�m�F
	EXPECT_TRUE(BeginItr == Itr);
}

/**
* @brief	�قȂ�C�e���[�^���r�����ۂ̋���
* @details	ID:23
*			�قȂ�C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			false���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DiffrentIteratorCompareEQ)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

	// ����ł��邩�m�F
	EXPECT_FALSE(BeginItr == Itr);
}

/**
* @brief	�قȂ�C�e���[�^���r�����ۂ̋���
* @details	ID:23
*			�قȂ�R���X�g�ȃC�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			false���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DiffrentConstIteratorCompareEQ)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

	// ����ł��邩�m�F
	EXPECT_FALSE(BeginItr == Itr);
}

#pragma endregion

#pragma region ***** 2�̃C�e���[�^���قȂ�̂��̂ł��邩��r���s�� *****

/**
* @brief	���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
* @details	ID:24
*			��̃��X�g����擾�����擪�C�e���[�^�Ɩ����C�e���[�^���r����e�X�g�ł��B
*			false���Ԃ�ΐ����ł��B
*/
TEST(IteratorCompareNE, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetBegin();
	auto EndItr = List.GetEnd();

	// �قȂ邩�m�F
	EXPECT_FALSE(BeginItr != EndItr);
}

/**
* @brief	���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
* @details	ID:24
*			��̃��X�g����擾�����R���X�g�Ȑ擪�C�e���[�^�ƃR���X�g�Ȗ����C�e���[�^���r����e�X�g�ł��B
*			false���Ԃ�ΐ����ł��B
*/
TEST(ConstIteratorCompareNE, EmptyListBeginAndEnd)
{
	LinkedList List;

	auto BeginItr = List.GetConstBegin();
	auto EndItr = List.GetConstEnd();

	// �قȂ邩�m�F
	EXPECT_FALSE(BeginItr != EndItr);
}

/**
* @brief	����̃C�e���[�^���r�����ۂ̋���
* @details	ID:25
*			����̃C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			false���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, IteratorCompareNE)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	// �قȂ邩�m�F
	EXPECT_FALSE(BeginItr != Itr);
}

/**
* @brief	����̃C�e���[�^���r�����ۂ̋���
* @details	ID:25
*			����̃R���X�g�ȃC�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			false���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, ConstIteratorCompareNE)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	// �قȂ邩�m�F
	EXPECT_FALSE(BeginItr != Itr);
}

/**
* @brief	�قȂ�C�e���[�^���r�����ۂ̋���
* @details	ID:23
*			�قȂ�C�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			true���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DiffrentIteratorCompareNE)
{
	auto BeginItr = pList->GetBegin();
	auto Itr = pList->GetBegin();

	++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

	// �قȂ邩�m�F
	EXPECT_TRUE(BeginItr != Itr);
}

/**
* @brief	�قȂ�C�e���[�^���r�����ۂ̋���
* @details	ID:23
*			�قȂ�R���X�g�ȃC�e���[�^�ǂ����Ŕ�r�������̋������`�F�b�N���܂��B
*			true���Ԃ�ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DiffrentConstIteratorCompareNE)
{
	auto BeginItr = pList->GetConstBegin();
	auto Itr = pList->GetConstBegin();

	++Itr;	// ���炷���Ƃŕʂ̃C�e���[�^�ɂ���

	// �قȂ邩�m�F
	EXPECT_TRUE(BeginItr != Itr);
}

#pragma endregion


}	// ex02_Iterator