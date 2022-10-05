#pragma once

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"

/**
* @class	LinkedListTestFixture
* @brief	�����v�f�����ɓ����Ă��郊�X�g�̏������ȗ������邽�߂̃t�B�N�X�`��
*/
class LinkedListTestFixture : public ::testing::Test
{
	//=== �����o�ϐ�
protected:

	LinkedList* pList;	// ���X�g

	//=== �����o�֐�
protected:

	virtual void SetUp(void)
	{
		pList = new LinkedList;
		ScoreData Data;

		//*** �f�[�^��3�������ɑ}������
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

//===== �֐���` =====

/**
* @fn		TestListItem(LinkedList&, ScoreData*, size_t)
* @brief	���X�g���Ƀf�[�^�����Ԃɓ����Ă��邩�`�F�b�N����B
*/
inline void TestListItem(LinkedList& List, ScoreData* pData, size_t DataCount)
{
	ASSERT_TRUE(List.GetSize() == DataCount);
	ASSERT_TRUE(pData);
	ASSERT_GT(DataCount, 0u);

	//*** �擪���珇�ԂɊm�F���Ă���
	auto Itr = List.GetBegin();
	for (decltype(DataCount) i = 0; i < DataCount; ++i)
	{
		// ���������`�F�b�N
		EXPECT_EQ(pData[i].Score, Itr->Score);
		EXPECT_EQ(pData[i].Name, Itr->Name);

		++Itr;
	}
}
