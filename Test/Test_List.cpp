/**
* @file		Test_List.cpp
* @brief	�o�������X�g�e�X�g
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "TestHelper.h"

namespace ex01_LinkedList
{

#pragma region ***** �f�[�^���̎擾 *****
/**
* @brief	���X�g����ł���ꍇ�̖߂�l
* @details	ID:0
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g����̏ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenEmpty)
{
	LinkedList List;
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	���X�g�����ւ̑}�����s�����ۂ̖߂�l
* @details	ID:1
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�����ɑ}�����s�������Ƃ̏ꍇ�̖߂�l�̊m�F�ł��B
*			1�ł���ΐ����ł��B
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
* @brief	���X�g�����ւ̑}�������s�����ۂ̖߂�l
* @details	ID:2
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�����ɑ}�����s���A�}�������s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
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
* @brief	�f�[�^�̑}�����s�����ۂ̖߂�l
* @details	ID:3
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�ɑ}�����s�������Əꍇ�̖߂�l�̊m�F�ł��B
*			1�ł���ΐ����ł��B
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
* @brief	�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
* @details	ID:4
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g�ɑ}�����s���A�}�������s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
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
* @brief	�f�[�^�̍폜���s�����ۂ̖߂�l
* @details	ID:5
*			�f�[�^�����擾�̃e�X�g�ł��B
*			�f�[�^�̍폜���s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenDelete)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 5;
	Data.Name = "Test5";

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	Itr = List.GetBegin();	// �擾���Ȃ���
	ASSERT_TRUE(List.Delete(Itr));
	EXPECT_EQ(0, List.GetSize());
}

/**
* @brief	�f�[�^�̍폜���s�����ۂ̖߂�l
* @details	ID:6
*			�f�[�^�����擾�̃e�X�g�ł��B
*			�f�[�^�̍폜���s���A�폜�Ɏ��s�����ꍇ�̖߂�l�̊m�F�ł��B
*			1�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenDeleteFailed)
{
	LinkedList List;
	ScoreData Data;
	Data.Score = 6;
	Data.Name = "Test6";

	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	LinkedList::ConstIterator InvalidItr;	// �����ȃC�e���[�^
	ASSERT_FALSE(List.Delete(InvalidItr));

	EXPECT_EQ(1, List.GetSize());
}

/**
* @brief	���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
* @details	ID:7
*			�f�[�^�����擾�̃e�X�g�ł��B
*			���X�g����̏�ԂŃf�[�^�̍폜���s�����ꍇ�̖߂�l�̊m�F�ł��B
*			0�ł���ΐ����ł��B
*/
TEST(GetDataNum, WhenDeleteEmptyList)
{
	LinkedList List;

	LinkedList::ConstIterator InvalidItr;	// �����ȃC�e���[�^
	ASSERT_FALSE(List.Delete(InvalidItr));

	EXPECT_EQ(List.GetSize(), 0);
}
#pragma endregion

#pragma region ***** �f�[�^�̑}�� *****
/**
* @brief	���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
* @details	ID:9
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g����̏�ԂŐ擪�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
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
* @brief	���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
* @details	ID:9
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g����̏�ԂŖ����Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
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
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
* @details	ID:10
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�擪�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, WhenSomeDataExistToBegin)
{
	//*** �擪�̃C�e���[�^���w�肵�ăf�[�^��V�����}������
	auto Itr = pList->GetBegin();
	ScoreData Data;
	Data.Score = 10;
	Data.Name = "Test10";
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** �ȑO�̐擪�v�f��2�Ԗڂɂ��邱�Ƃ��m�F����
	Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(Itr->Score == 0);
	EXPECT_TRUE(Itr->Name == "Test0");
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�����R���X�g�C�e���[�^�̎擾��n���āA�}�������ۂ̋���
* @details	ID:11
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�����Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, WhenSomeDataExistToEnd)
{
	//*** �����̃C�e���[�^���w�肵�ăf�[�^��V�����}������
	auto Itr = pList->GetEnd();
	ScoreData Data;
	Data.Score = 11;
	Data.Name = "Test11";
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** ������1�O�ɒǉ�����Ă��邩�m�F����
	Itr = pList->GetEnd();
	--Itr;
	EXPECT_TRUE(Itr->Score == 11);
	EXPECT_TRUE(Itr->Name == "Test11");
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
* @details	ID:12
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�擪�ł������ł��Ȃ��ꏊ�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			�߂�l��True�ŁA���̃f�[�^�ɉe�����Ȃ���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, WhenSomeDataExistToCenter)
{
	//*** �擪�̎��̃C�e���[�^���w�肵�ăf�[�^��V�����}������
	auto Itr = pList->GetBegin();
	ScoreData Data;
	Data.Score = 12;
	Data.Name = "Test12";
	++Itr;
	EXPECT_TRUE(pList->Insert(Itr, Data));

	//*** �擪����2�i�񂾈ʒu�Ɍ��̃f�[�^�������OK
	Itr = pList->GetBegin();
	++Itr;
	++Itr;
	EXPECT_TRUE(Itr->Score == 1);
	EXPECT_TRUE(Itr->Name == "Test1");

	//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
	// �O���珇�Ԃ�
	// Score == 0;
	// Name == "Test0";
	// Score == 12;
	// Name == "Test12";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// �Ȃ�OK

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
* @brief	ConstIterator���w�肵�đ}�����s�����ۂ̋���
* @details	ID:13
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�R���X�g�ȃC�e���[�^�𗘗p���Đ擪�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, InsertWithConstIteratorToBegin)
{
	//*** �擪�������R���X�g�ȃC�e���[�^���g���ăf�[�^��}������B
	auto ConstItr = pList->GetConstBegin();
	ScoreData Data;
	Data.Score = 13;
	Data.Name = "Test13";
	EXPECT_TRUE(pList->Insert(ConstItr, Data));

	//*** ���Ƃ��Ɛ擪�ɂ������f�[�^��2�Ԗڂɗ��Ă��邩�`�F�b�N
	auto Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(Itr->Score == 0);
	EXPECT_TRUE(Itr->Name == "Test0");

	//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
	// �O���珇�Ԃ�
	// Score == 13;
	// Name == "Test13";
	// Score == 0;
	// Name == "Test0";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// �Ȃ�OK

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
* @brief	ConstIterator���w�肵�đ}�����s�����ۂ̋���
* @details	ID:13
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�R���X�g�ȃC�e���[�^�𗘗p���Ė����Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, InsertWithConstIteratorToEnd)
{
	//*** �����������R���X�g�ȃC�e���[�^���g���ăf�[�^��}������B
	auto ConstItr = pList->GetConstEnd();
	ScoreData Data;
	Data.Score = 13;
	Data.Name = "Test13";
	EXPECT_TRUE(pList->Insert(ConstItr, Data));

	//*** ���҂����ʒu�ɑ}������Ă��邩�`�F�b�N
	auto Itr = pList->GetEnd();
	--Itr;
	EXPECT_TRUE(Itr->Score == 13);
	EXPECT_TRUE(Itr->Name == "Test13");

	//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
	// �O���珇�Ԃ�
	// Score == 0;
	// Name == "Test0";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// Score == 13;
	// Name == "Test13";
	// �Ȃ�OK

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
* @brief	ConstIterator���w�肵�đ}�����s�����ۂ̋���
* @details	ID:13
*			�f�[�^�̑}���̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f�������ԂŁA�R���X�g�ȃC�e���[�^�𗘗p���Đ擪�ł������ł��Ȃ��ʒu�Ƀf�[�^�̑}�����s�����Ƃ��̋������m�F���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, InsertWithConstIteratorToCenter)
{
	//*** �擪�̎��������R���X�g�ȃC�e���[�^���g���ăf�[�^��}������B
	auto ConstItr = pList->GetConstBegin();
	ScoreData Data;
	Data.Score = 13;
	Data.Name = "Test13";
	++ConstItr;
	EXPECT_TRUE(pList->Insert(ConstItr, Data));

	//*** �擪��2���ɂ���Ă��邩�`�F�b�N
	auto Itr = pList->GetBegin();
	++Itr;
	++Itr;
	EXPECT_TRUE(Itr->Score == 1);
	EXPECT_TRUE(Itr->Name == "Test1");

	//*** �i�[�ς݂̃f�[�^�ɉe�����Ȃ����`�F�b�N
	// �O���珇�Ԃ�
	// Score == 0;
	// Name == "Test0";
	// Score == 13;
	// Name == "Test13";
	// Score == 1;
	// Name == "Test1";
	// Score == 2;
	// Name == "Test2";
	// �Ȃ�OK

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
* @brief	�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
* @details	ID:14
*			�f�[�^�̑}���̃e�X�g�ł��B
*			�s���ȃC�e���[�^���g�p���đ}���������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST(InsertData, WithInvalidIterator)
{
	LinkedList List1;
	LinkedList List2;

	ScoreData Data;
	Data.Score = 14;
	Data.Name = "Test14";

	// �����Q�Ƃ��Ă��Ȃ��C�e���[�^�ő}��
	LinkedList::Iterator InvalidItr;
	EXPECT_FALSE(List1.Insert(InvalidItr, Data));

	// �ʂ̃��X�g���Q�Ƃ��Ă���C�e���[�^�ő}��
	auto InvalidRefItr = List2.GetBegin();
	EXPECT_FALSE(List1.Insert(InvalidRefItr, Data));
}
#pragma endregion

#pragma region ***** �f�[�^�̍폜 *****
/**
* @brief	���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
* @details	ID:16
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			���X�g����̎��ɁA�擪�C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST(DeleteData, WithEmptyListBegin)
{
	LinkedList List;

	// �擪�C�e���[�^�擾
	auto Itr = List.GetBegin();

	// �����`�F�b�N
	EXPECT_FALSE(List.Delete(Itr));
}

/**
* @brief	���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
* @details	ID:16
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			���X�g����̎��ɁA�����C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST(DeleteData, WithEmptyListEnd)
{
	LinkedList List;

	// �����C�e���[�^�擾
	auto Itr = List.GetEnd();

	// �����`�F�b�N
	EXPECT_FALSE(List.Delete(Itr));
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
* @details	ID:17
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�����̗v�f�����鎞�ɁA�擪�C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DeleteWithBegin)
{
	// �擪�C�e���[�^���w�肵�č폜
	auto Itr = pList->GetBegin();
	EXPECT_TRUE(pList->Delete(Itr));
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
* @details	ID:18
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�����̗v�f�����鎞�ɁA�����C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			false�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DeleteWithEnd)
{
	// �����C�e���[�^���w�肵�č폜
	auto Itr = pList->GetEnd();
	EXPECT_FALSE(pList->Delete(Itr));
}

/**
* @brief	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋���
* @details	ID:19
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�����̗v�f�����鎞�ɁA�擪�ł������ł��Ȃ��C�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DeleteAnywhere)
{
	// �擪�C�e���[�^�̎��̃C�e���[�^���w�肵�č폜
	auto Itr = pList->GetBegin();
	++Itr;
	EXPECT_TRUE(pList->Delete(Itr));

	// ���҂����ʒu�ɔz�u����Ă��邩�A���̗v�f�ɉe�����Ȃ����`�F�b�N
	ScoreData TestData[2];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 2;
	TestData[1].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	ConstIterator���w�肵�č폜���s�����ۂ̋���
* @details	ID:20
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DeleteAnywhereWithConstIterator)
{
	// �擪�C�e���[�^�̎��̃C�e���[�^���w�肵�č폜
	auto Itr = pList->GetConstBegin();
	++Itr;
	EXPECT_TRUE(pList->Delete(Itr));

	// ���҂����ʒu�ɔz�u����Ă��邩�A���̗v�f�ɉe�����Ȃ����`�F�b�N
	ScoreData TestData[2];
	TestData[0].Score = 0;
	TestData[0].Name = "Test0";
	TestData[1].Score = 2;
	TestData[1].Name = "Test2";

	TestListItem(*pList, TestData, _countof(TestData));
}

/**
* @brief	�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
* @details	ID:21
*			�f�[�^�̍폜�̃e�X�g�ł��B
*			�s���ȃC�e���[�^���w�肵�č폜�������̋������`�F�b�N���܂��B
*			true�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, DeleteInvalidIterator)
{
	// �s���ȃC�e���[�^���w�肵�č폜����
	LinkedList::Iterator Itr;
	EXPECT_FALSE(pList->Delete(Itr));
}

#pragma endregion

#pragma region ***** �擪�C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:23
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginIterator, WhenEmpty)
{
	LinkedList List;

	// �擪�C�e���[�^�擾
	auto Itr = List.GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:24
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginIterator, When1ItemExist)
{
	LinkedList List;

	// �f�[�^��1���ǉ�
	ScoreData Data;
	Data.Score = 24;
	Data.Name = "Test24";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = List.GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 24);
	EXPECT_TRUE(BeginItr->Name == "Test24");
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:25
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginIterator, When2ItemExist)
{
	LinkedList List;

	// �f�[�^��2���ǉ�
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = List.GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:26
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ɑ}��������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenInsertBegin)
{
	// �擪�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = pList->GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 26);
	EXPECT_TRUE(BeginItr->Name == "Test26");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:26
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����ɑ}��������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenInsertEnd)
{
	// �����Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = pList->GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:26
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��ʒu�ɑ}��������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenInsertCenter)
{
	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �擪�C�e���[�^���擾
	auto BeginItr = pList->GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:27
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f���폜������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenDeleteBegin)
{
	// �擪�v�f���폜����
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// �擪�C�e���[�^���擾
	auto BeginItr = pList->GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 1);
	EXPECT_TRUE(BeginItr->Name == "Test1");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:27
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����v�f���폜������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenDeleteEnd)
{
	// �����v�f���폜����
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �擪�C�e���[�^���擾
	auto BeginItr = pList->GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:27
*			�擪�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��v�f���폜������ɐ擪�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginIteratorWhenDeleteCenter)
{
	// �擪�ł������ł��Ȃ��v�f���폜����
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �擪�C�e���[�^���擾
	auto BeginItr = pList->GetBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

#pragma endregion

#pragma region ***** �擪�R���X�g�C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:29
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginConstIterator, WhenEmpty)
{
	LinkedList List;

	// �擪�R���X�g�C�e���[�^�擾
	auto Itr = List.GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:30
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginConstIterator, When1ItemExist)
{
	LinkedList List;

	// �f�[�^��1���ǉ�
	ScoreData Data;
	Data.Score = 30;
	Data.Name = "Test30";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = List.GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 30);
	EXPECT_TRUE(BeginItr->Name == "Test30");
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:31
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetBeginConstIterator, When2ItemExist)
{
	LinkedList List;

	// �f�[�^��2���ǉ�
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = List.GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:32
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ɑ}��������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenInsertBegin)
{
	// �擪�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = pList->GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 32);
	EXPECT_TRUE(BeginItr->Name == "Test32");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:32
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����ɑ}��������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenInsertEnd)
{
	// �����Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = pList->GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:32
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��ʒu�ɑ}��������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenInsertCenter)
{
	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 32;
	Data.Name = "Test32";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = pList->GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:33
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f���폜������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenDeleteBegin)
{
	// �擪�v�f���폜����
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = pList->GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 1);
	EXPECT_TRUE(BeginItr->Name == "Test1");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:33
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����v�f���폜������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenDeleteEnd)
{
	// �����v�f���폜����
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = pList->GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:33
*			�擪�R���X�g�C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��v�f���폜������ɐ擪�R���X�g�C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetBeginConstIteratorWhenDeleteCenter)
{
	// �擪�ł������ł��Ȃ��v�f���폜����
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �擪�R���X�g�C�e���[�^���擾
	auto BeginItr = pList->GetConstBegin();

	// �����`�F�b�N
	EXPECT_TRUE(BeginItr->Score == 0);
	EXPECT_TRUE(BeginItr->Name == "Test0");
}

#pragma endregion

#pragma region ***** �����C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:35
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndIterator, WhenEmpty)
{
	LinkedList List;

	// �����C�e���[�^�擾
	auto Itr = List.GetEnd();

	// �����`�F�b�N
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:36
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndIterator, When1ItemExist)
{
	LinkedList List;

	// �f�[�^��1���ǉ�
	ScoreData Data;
	Data.Score = 24;
	Data.Name = "Test24";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = List.GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 24);
	EXPECT_TRUE(EndItr->Name == "Test24");
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:37
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndIterator, When2ItemExist)
{
	LinkedList List;

	// �f�[�^��2���ǉ�
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = List.GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:38
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ɑ}��������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenInsertBegin)
{
	// �擪�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 38;
	Data.Name = "Test38";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = pList->GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:38
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����ɑ}��������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenInsertEnd)
{
	// �����Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 38;
	Data.Name = "Test38";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = pList->GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 38);
	EXPECT_TRUE(EndItr->Name == "Test38");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:38
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��ʒu�ɑ}��������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenInsertCenter)
{
	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 26;
	Data.Name = "Test26";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �����C�e���[�^���擾
	auto EndItr = pList->GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:39
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f���폜������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenDeleteBegin)
{
	// �擪�v�f���폜����
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// �����C�e���[�^���擾
	auto EndItr = pList->GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:39
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����v�f���폜������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenDeleteEnd)
{
	// �����v�f���폜����
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �����C�e���[�^���擾
	auto EndItr = pList->GetEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:39
*			�����C�e���[�^�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��v�f���폜������ɖ����C�e���[�^���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndIteratorWhenDeleteCenter)
{
	// �擪�ł������ł��Ȃ��v�f���폜����
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �����C�e���[�^���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

#pragma endregion

#pragma region ***** �����R���X�g�C�e���[�^�̎擾 *****

/**
* @brief	���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:41
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g����̎��ɁA�����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�_�~�[�m�[�h���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndConstIterator, WhenEmpty)
{
	LinkedList List;

	// �����R���X�g�C�e���[�^�̎擾�擾
	auto Itr = List.GetConstEnd();

	// �����`�F�b�N
	EXPECT_TRUE(Itr.IsDummy());
}

/**
* @brief	���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:42
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g��1�̗v�f������Ƃ��A�����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndConstIterator, When1ItemExist)
{
	LinkedList List;

	// �f�[�^��1���ǉ�
	ScoreData Data;
	Data.Score = 42;
	Data.Name = "Test42";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 42);
	EXPECT_TRUE(EndItr->Name == "Test42");
}

/**
* @brief	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
* @details	ID:43
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g��2�ȏ�̗v�f������Ƃ��A�����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f�����w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST(GetEndConstIterator, When2ItemExist)
{
	LinkedList List;

	// �f�[�^��2���ǉ�
	ScoreData Data;
	Data.Score = 1;
	Data.Name = "Test1";
	auto Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));
	Data.Score = 0;
	Data.Name = "Test0";
	Itr = List.GetBegin();
	ASSERT_TRUE(List.Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = List.GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:44
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ɑ}��������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenInsertBegin)
{
	// �擪�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44";
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:44
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����ɑ}��������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenInsertEnd)
{
	// �����Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44";
	auto Itr = pList->GetEnd();
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 44);
	EXPECT_TRUE(EndItr->Name == "Test44");
}

/**
* @brief	�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
* @details	ID:44
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��ʒu�ɑ}��������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenInsertCenter)
{
	// �擪�ł������ł��Ȃ��ʒu�Ƀf�[�^��}������
	ScoreData Data;
	Data.Score = 44;
	Data.Name = "Test44";
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Insert(Itr, Data));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:45
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�v�f���폜������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenDeleteBegin)
{
	// �擪�v�f���폜����
	auto Itr = pList->GetBegin();
	ASSERT_TRUE(pList->Delete(Itr));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:45
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�����v�f���폜������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenDeleteEnd)
{
	// �����v�f���폜����
	auto Itr = pList->GetEnd();
	--Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 1);
	EXPECT_TRUE(EndItr->Name == "Test1");
}

/**
* @brief	�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
* @details	ID:45
*			�����R���X�g�C�e���[�^�̎擾�̎擾�̃e�X�g�ł��B
*			���X�g�ɕ����̗v�f������Ƃ��A�擪�ł������ł��Ȃ��v�f���폜������ɖ����R���X�g�C�e���[�^�̎擾���擾�������̋������`�F�b�N���܂��B
*			�擪�v�f���w���C�e���[�^���擾�ł���ΐ����ł��B
*/
TEST_F(LinkedListTestFixture, GetEndConstIteratorWhenDeleteCenter)
{
	// �擪�ł������ł��Ȃ��v�f���폜����
	auto Itr = pList->GetBegin();
	++Itr;
	ASSERT_TRUE(pList->Delete(Itr));

	// �����R���X�g�C�e���[�^�̎擾���擾
	auto EndItr = pList->GetConstEnd();
	--EndItr;

	// �����`�F�b�N
	EXPECT_TRUE(EndItr->Score == 2);
	EXPECT_TRUE(EndItr->Name == "Test2");
}

#pragma endregion

}	// ex01_LinkedList