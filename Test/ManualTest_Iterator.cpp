/**
* @file		ManualTest_Iterator.cpp
* @brief	�o�������X�g �C�e���[�^ �蓮�e�X�g
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include "gtest/gtest.h"
#include "../List_2/LinkedList.h"
#include "ManualTest_Iterator.h"

namespace ex02_Iterator
{

/**
* @brief	�C�e���[�^�̎w���v�f���擾����@�\�ɂ��āAconst�̃��\�b�h�ł��邩
* @details	ID:2
*			�C�e���[�^�̎w���v�f���擾����@�\�̃e�X�g�ł��B
*			const�Ȋ֐��ł��邩�m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C���Ɏ��s�����琬���ł��B
*/
TEST(ConstIteratorAssign, FunctionIsConst)
{
#ifdef CAN_NOT_ASSIGN_TO_CONSTITERATOR_ELEMENT
	LinkedList List;
	auto Itr = List.GetConstBegin();

	Itr->Score = 100;

	EXPECT_EQ(0, List.GetSize());
#else
	SUCCEED();
#endif
}

/**
* @brief	�R���X�g�ȃC�e���[�^�����R���X�g�ȃC�e���[�^���쐬�ł��Ȃ����Ƃ��`�F�b�N
* @details	ID:17
*			�C�e���[�^�̃R�s�[�@�\�̃e�X�g�ł��B
*			�R���X�g�ȃC�e���[�^�����R���X�g�ȃC�e���[�^���쐬�ł��Ȃ����Ƃ��m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C���Ɏ��s�����琬���ł��B
*/
TEST(MakeIterator, FromConstIterator)
{
#ifdef CAN_NOT_COPY_FROM_CONST_ITERATOR
	
	LinkedList List;
	auto ConstItr = List.GetConstBegin();

	LinkedList::Iterator Itr(ConstItr);

	EXPECT_EQ(0, List.GetSize());
#else
	SUCCEED();
#endif
}

/**
* @brief	��R���X�g�ȃC�e���[�^�ɃR���X�g�ȃC�e���[�^�����ł��Ȃ����Ƃ��`�F�b�N
* @details	ID:17
*			�C�e���[�^�̃R�s�[�@�\�̃e�X�g�ł��B
*			��R���X�g�ȃC�e���[�^�ɃR���X�g�ȃC�e���[�^�����ł��Ȃ����Ƃ��m�F���Ă��܂��B
*			�L���ɂ������A�R���p�C���Ɏ��s�����琬���ł��B
*/
TEST(AssignIterator, FromConstIterator)
{
#ifdef CAN_NOT_ASSIGN_CONST_ITERATOR_TO_ITERATOR

	LinkedList List;
	auto ConstItr = List.GetConstBegin();

	LinkedList::Iterator Itr;
	Itr = ConstItr;

	EXPECT_EQ(0, List.GetSize());
#else
	SUCCEED();
#endif
}

}	// ex02_Iterator