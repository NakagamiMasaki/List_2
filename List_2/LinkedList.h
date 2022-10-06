/**
* @file		LinkedList.h
* @brief	�o�������X�g��`
* @data		2022/10/04
*/

#pragma once

//===== �C���N���[�h =====
#include "Score.h"

//===== �N���X��` =====
/**
* @class	LinkedList
* @brief	�o�������X�g
*/
class LinkedList
{
	//=== �\���̒�`
private:

	/**
	* @struct	LinkedList::Node
	* @brief	�o�������X�g�̃m�[�h
	*/
	struct Node
	{
		Node* pPrev;		// �O�m�[�h�ւ̃|�C���^
		Node* pNext;		// ���m�[�h�ւ̃|�C���^

		ScoreData	Data;	// ���уf�[�^
	};

	//=== �N���X��`
public:

	/**
	* @class	LinkedList::ConstIterator
	* @brief	�o�������X�g�̃R���X�g�C�e���[�^
	*/
	class ConstIterator
	{
		//=== �����o�ϐ�
	protected:

		LinkedList::Node*	m_pCurrentNode;		// ���̃C�e���[�^�����ݎQ�Ƃ��Ă���m�[�h
		const LinkedList*	m_pList;			// �ǂ̃��X�g�̃C�e���[�^�����ʂł���悤��

		//=== �����o�֐�
	public:

		/**
		* @fn		ConstIterator::ConstIterator(void)
		* @brief	�f�t�H���g�R���X�g���N�^
		*/
		ConstIterator(void);

		/**
		* @fn		ConstIterator::operator--(void)
		* @brief	���X�g�̐擪�Ɍ�������1�i��(�O�u�f�N�������g)
		*/
		ConstIterator& operator--(void);

		/**
		* @fn		ConstIterator::operator++(void)
		* @brief	���X�g�̖����Ɍ�������1�i��(�O�u�C���N�������g)
		*/
		ConstIterator& operator++(void);

		/**
		* @fn		ConstIterator::operator--(void)
		* @brief	���X�g�̐擪�Ɍ�������1�i��(��u�f�N�������g)
		*/
		ConstIterator operator--(int);

		/**
		* @fn		ConstIterator::operator++(void)
		* @brief	���X�g�̖����Ɍ�������1�i��(��u�C���N�������g)
		*/
		ConstIterator operator++(int);

		/**
		* @fn		ConstIterator::operator*(void) const
		* @brief	�C�e���[�^���w���v�f���擾����(�R���X�g��)
		*/
		const ScoreData& operator*(void) const;

		/**
		* @fn		ConstIterator::operator*(void) const
		* @brief	�C�e���[�^���w���v�f���擾����(�R���X�g��)
		*/
		const ScoreData* operator->(void) const;

		/**
		* @fn		ConstIterator::ConstIterator(const ConstIterator& ConstItr)
		* @brief	�C�e���[�^�̃R�s�[���s��(�R�s�[�R���X�g���N�^)
		*/
		ConstIterator(const ConstIterator& ConstItr);

		/**
		* @fn		ConstIterator::operator=(const ConstIterator& ConstItr)
		* @brief	�C�e���[�^�̃R�s�[������s��
		* @return	���̃C�e���[�^�ւ̍��Ӓl�Q��
		*/
		ConstIterator& operator=(const ConstIterator& Itr);

		/**
		* @fn		ConstIterator::operator=(const ConstIterator& ConstItr) const
		* @brief	���̃C�e���[�^�Ɠ��ꂩ��r����
		* @return	����Ȃ� true , �قȂ�Ȃ� false
		*/
		bool operator==(const ConstIterator& Itr) const;

		/**
		* @fn		ConstIterator::operator=(const ConstIterator& ConstItr) const
		* @brief	���̃C�e���[�^�ƈقȂ邩��r����
		* @return	�قȂ�Ȃ� true , ����Ȃ� false
		*/
		bool operator!=(const ConstIterator& Itr) const;

		/**
		* @fn		ConstIterator::IsInvalidReference(void) const
		* @brief	���̃C�e���[�^���K�؂ȎQ�Ƃ������Ă��邩�`�F�b�N����
		* @return	�K�؂ɐݒ肳��Ă���� true | �s���ȎQ�ƂȂ� false
		*/
		bool IsValidReference(void) const;

		/**
		* @fn		ConstIterator::IsInvalidReference(void) const
		* @brief	���̃C�e���[�^���_�~�[�m�[�h���w���Ă��邩�`�F�b�N����B
		* @details	�{���͕K�v�Ȃ��Ǝv���܂����A�����̎�����O������_�~�[�m�[�h���w���Ă��邩�m�F������@���Ȃ����ߎ������Ă��܂��B
		* @return	�_�~�[�m�[�h���w���Ă���� true | �w���Ă��Ȃ���� false
		*/
		bool IsDummy(void) const;

		/**
		* @fn		ConstIterator::IsInvalidReference(void) const
		* @brief	�s���ȃC�e���[�^�łȂ����Ƃ��`�F�b�N����B
		* @return	�s���łȂ��Ȃ� true | �s���ȃC�e���[�^�Ȃ� false
		*/
		bool IsValid(void) const;

		/**
		* @fn		ConstIterator::operator bool(void) const
		* @brief	�s���ȃC�e���[�^�łȂ����Ƃ��`�F�b�N����B
		* @return	�s���łȂ��Ȃ� true | �s���ȃC�e���[�^�Ȃ� false
		*/
		operator bool(void) const;

		friend LinkedList;
	};

	/**
	* @class	LinkedList::Iterator
	* @brief	�o�������X�g�̔�R���X�g�C�e���[�^
	*/
	class Iterator : public ConstIterator
	{
		//=== �����o�֐�
	public:

		/**
		* @fn		Iterator::operator*(void)
		* @brief	�C�e���[�^���w���v�f���擾����(��R���X�g��)
		*/
		ScoreData& operator*(void);

		/**
		* @fn		Iterator::operator->(void)
		* @brief	�C�e���[�^���w���v�f���擾����(��R���X�g��)
		*/
		ScoreData* operator->(void);
	};

	//=== �����o�ϐ�
private:

	size_t	m_ElementCount;	// �v�f��
	Node*	m_pDummy;		// �_�~�[�m�[�h(Prev�ɖ����m�[�h�ANext�ɐ擪�m�[�h)

	//=== �����o�֐�
public:

	/**
	* @fn		LinkedList::LinkedList(void)
	* @brief	�f�t�H���g�R���X�g���N�^
	*/
	LinkedList(void);

	/**
	* @fn		LinkedList::~LinkedList(void)
	* @brief	�f�X�g���N�^
	*/
	~LinkedList(void);

	/**
	* @fn		LinkedList::GetSize(void)
	* @brief	�f�[�^���̎擾
	*/
	size_t GetSize(void) const;

	/**
	* @fn			LinkedList::Insert(ConstIterator&, const ScoreData&)
	* @brief		�f�[�^�̑}��
	* @param[in]	Itr		�}���������ʒu
	* @param[in]	Data	�V�����}���������f�[�^
	* @return		������ : true | ���s�� : false
	*/
	bool Insert(ConstIterator& Itr, const ScoreData& Data);

	/**
	* @fn			LinkedList::Pushback(const ScoreData&)
	* @brief		�f�[�^�𖖔��ɒǉ�
	* @param[in]	Data	�V�����ǉ��������f�[�^
	* @return		������ : true | ���s�� : false
	*/
	bool Pushback(const ScoreData& Data);

	/**
	* @fn			LinkedList::Pushfront(const ScoreData&)
	* @brief		�f�[�^��擪�ɒǉ�
	* @param[in]	Data	�V�����ǉ��������f�[�^
	* @return		������ : true | ���s�� : false
	*/
	bool Pushfront(const ScoreData& Data);

	/**
	* @fn			LinkedList::Delete(ConstIterator&)
	* @brief		�f�[�^�̍폜
	* @param[in]	Itr		�폜�������f�[�^
	* @return		������ : true | ���s�� : false
	*/
	bool Delete(ConstIterator& Itr);

	/**
	* @fn			LinkedList::Clear(void)
	* @brief		�S�Ẵf�[�^�̍폜
	*/
	void Clear(void);

	/**
	* @fn		LinkedList::GetConstBegin(void) const
	* @brief	�擪�̃R���X�g�ȃC�e���[�^���擾
	* @return	�擪�̃R���X�g�ȃC�e���[�^
	*/
	ConstIterator GetConstBegin(void) const;

	/**
	* @fn		LinkedList::GetFront(void)
	* @brief	�擪�̃C�e���[�^���擾
	* @return	�擪�̃C�e���[�^
	*/
	Iterator GetBegin(void);

	/**
	* @fn		LinkedList::GetConstEnd(void) const
	* @brief	�����̃R���X�g�ȃC�e���[�^���擾
	* @return	�����̃R���X�g�ȃC�e���[�^
	*/
	ConstIterator GetConstEnd(void) const;

	/**
	* @fn		LinkedList::GetEnd(void)
	* @brief	�����̃C�e���[�^���擾
	* @return	�����̃C�e���[�^
	*/
	Iterator GetEnd(void);

	friend ConstIterator;
	friend Iterator;
};

