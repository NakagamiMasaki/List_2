/**
* @file		LinkedList.cpp
* @brief	�o�������X�g��`
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include "LinkedList.h"
#include <assert.h>

//===== �֐���` =====

//====== LinkedList::ConstIterator =====

LinkedList::ConstIterator::ConstIterator(void)
	: m_pCurrentNode(nullptr)
	, m_pList(nullptr)
{
}

LinkedList::ConstIterator& LinkedList::ConstIterator::operator--(void)
{
	// ���X�g�̐擪������1�i��
	assert(m_pCurrentNode && m_pList && "�K�؂ȎQ�Ƃ�����܂���B");		// ���X�g���Q�Ƃ��Ă��邩�H
	assert(m_pCurrentNode->pPrev->Data.Name != "DummyNode");		// �擪�m�[�h�����Ɏw���Ă���̂ɁA����ɑO�ɐi�����Ƃ��Ă��Ȃ����H
	m_pCurrentNode = m_pCurrentNode->pPrev;
	return *this;
}

LinkedList::ConstIterator& LinkedList::ConstIterator::operator++(void)
{
	// ���X�g�̖���������1�i��
	assert(m_pCurrentNode && m_pList && "�K�؂ȎQ�Ƃ�����܂���B");		// ���X�g���Q�Ƃ��Ă��邩�H
	assert(m_pCurrentNode->Data.Name != "DummyNode");				// �_�~�[�m�[�h���w���Ă���̂ɁA����ɐi�����Ƃ��Ă��Ȃ����H
	m_pCurrentNode = m_pCurrentNode->pNext;
	return *this;
}

LinkedList::ConstIterator LinkedList::ConstIterator::operator--(int)
{
	// ���X�g�̐擪������1�i��
	assert(m_pCurrentNode && m_pList && "�K�؂ȎQ�Ƃ�����܂���B");		// ���X�g���Q�Ƃ��Ă��邩�H
	assert(m_pCurrentNode->pPrev->Data.Name != "DummyNode");		// �擪�m�[�h�����Ɏw���Ă���̂ɁA����ɑO�ɐi�����Ƃ��Ă��Ȃ����H
	LinkedList::ConstIterator TempItr = *this;	// �R�s�[����
	m_pCurrentNode = m_pCurrentNode->pPrev;

	return TempItr;
}

LinkedList::ConstIterator LinkedList::ConstIterator::operator++(int)
{
	// ���X�g�̖���������1�i��
	assert(m_pCurrentNode && m_pList && "�K�؂ȎQ�Ƃ�����܂���B");		// ���X�g���Q�Ƃ��Ă��邩�H
	assert(m_pCurrentNode->Data.Name != "DummyNode");				// �_�~�[�m�[�h���w���Ă���̂ɁA����ɐi�����Ƃ��Ă��Ȃ����H
	LinkedList::ConstIterator TempItr = *this;	// �R�s�[����
	m_pCurrentNode = m_pCurrentNode->pNext;

	return TempItr;
}

const ScoreData& LinkedList::ConstIterator::operator*(void) const
{
	assert(IsValid());				// �s���ȃC�e���[�^�łȂ����Ƃ��m�F����
	return m_pCurrentNode->Data;
}

const ScoreData* LinkedList::ConstIterator::operator->(void) const
{
	assert(IsValid());				// �s���ȃC�e���[�^�łȂ����Ƃ��m�F����
	return &m_pCurrentNode->Data;
}

LinkedList::ConstIterator::ConstIterator(const ConstIterator& ConstItr)
	: m_pCurrentNode(ConstItr.m_pCurrentNode)
	, m_pList(ConstItr.m_pList)
{
}

LinkedList::ConstIterator& LinkedList::ConstIterator::operator=(const ConstIterator& Itr)
{
	this->m_pCurrentNode = Itr.m_pCurrentNode;
	this->m_pList        = Itr.m_pList;
	return *this;
}

bool LinkedList::ConstIterator::operator==(const ConstIterator& Itr) const
{
	return this->m_pCurrentNode == Itr.m_pCurrentNode;
}

bool LinkedList::ConstIterator::operator!=(const ConstIterator& Itr) const
{
	return !(*this == Itr);
}

bool LinkedList::ConstIterator::IsValidReference(void) const
{
	return m_pList != nullptr && m_pCurrentNode != nullptr;
}

bool LinkedList::ConstIterator::IsDummy(void) const
{
	return m_pCurrentNode && m_pCurrentNode->Data.Name == "DummyNode";
}

bool LinkedList::ConstIterator::IsValid(void) const
{
	return IsValidReference() && !IsDummy();
}

LinkedList::ConstIterator::operator bool(void) const
{
	return IsValid();
}

//====== LinkedList::Iterator =====

ScoreData& LinkedList::Iterator::operator* (void)
{
	assert(IsValid());				// �s���ȃC�e���[�^�łȂ����Ƃ��m�F����
	return m_pCurrentNode->Data;
}

ScoreData* LinkedList::Iterator::operator->(void)
{
	assert(IsValid());				// �s���ȃC�e���[�^�łȂ����Ƃ��m�F����
	return &m_pCurrentNode->Data;
}

//===== LinkedList =====
LinkedList::LinkedList(void)
	: m_ElementCount(0)
	, m_pDummy(nullptr)
{
	m_pDummy = new Node;
	m_pDummy->pNext      = nullptr;
	m_pDummy->pPrev      = nullptr;
	m_pDummy->Data.Score = 0;
	m_pDummy->Data.Name  = "DummyNode";
}

LinkedList::~LinkedList(void)
{
	Clear();

	// �_�~�[�m�[�h���������
	delete m_pDummy;
}

size_t LinkedList::GetSize(void) const
{
	return m_ElementCount;
}

bool LinkedList::Insert(ConstIterator& Itr, const ScoreData& Data)
{
	//*** �����̃`�F�b�N
	if (Data.Name.empty() || Data.Score < 0)
		return false;

	//*** �C�e���[�^�̗L�������`�F�b�N
	if (!Itr.m_pCurrentNode || Itr.m_pList != this)
		return false;

	//*** �v�f����0�ŁA�C�e���[�^���_�~�[�m�[�h���w���Ă�����
	if (Itr.m_pCurrentNode == m_pDummy && m_ElementCount == 0)
	{
		//*** �ǉ�
		auto pNode = new Node;	// �V�����m�[�h

		// ������
		pNode->Data.Name = Data.Name;
		pNode->Data.Score = Data.Score;

		// �|�C���^���q���Ȃ���
		m_pDummy->pNext = pNode;
		m_pDummy->pPrev = pNode;
		pNode->pNext = m_pDummy;
		pNode->pPrev = m_pDummy;

		// �v�f�����X�V
		++m_ElementCount;

		return true;
	}

	//*** �_�~�[�m�[�h���w���Ă�����
	if (Itr.m_pCurrentNode == m_pDummy)
	{
		// �����ɒǉ�
		auto pNode = new Node;	// �V���������m�[�h

		// ������
		pNode->Data.Score = Data.Score;
		pNode->Data.Name = Data.Name;

		// �|�C���^���q���Ȃ���
		pNode->pNext           = m_pDummy;
		pNode->pPrev           = m_pDummy->pPrev;
		m_pDummy->pPrev->pNext = pNode;
		m_pDummy->pPrev        = pNode;

		// �v�f�����X�V
		++m_ElementCount;

		return true;
	}

	//*** �V�����v�f��n���ꂽ�C�e���[�^�̑O�ɑ}������
	// �V�����C�e���[�^�ƃm�[�h���쐬����
	ConstIterator NewItr;		// �V�����C�e���[�^
	Node* pNode = new Node;		// �V�����m�[�h

	// ������
	pNode->Data = Data;	// �f�[�^��ݒ�

	// �|�C���^���q���Ȃ���
	pNode->pPrev                       = Itr.m_pCurrentNode->pPrev;
	pNode->pNext                       = Itr.m_pCurrentNode;
	Itr.m_pCurrentNode->pPrev->pNext   = pNode;
	Itr.m_pCurrentNode->pPrev          = pNode;

	// �v�f�����X�V
	++m_ElementCount;

	return true;
}

bool LinkedList::Pushback(const ScoreData& Data)
{
	auto Itr = GetEnd();
	return Insert(Itr, Data);
}

bool LinkedList::Pushfront(const ScoreData& Data)
{
	auto Itr = GetBegin();
	return Insert(Itr, Data);
}

bool LinkedList::Delete(ConstIterator& Itr)
{
	// �v�f���̃`�F�b�N
	if (m_ElementCount == 0)
		return false;

	// �C�e���[�^���s���łȂ����Ƃ��`�F�b�N
	if (!Itr.m_pCurrentNode || Itr.m_pList != this)
		return false;

	// �_�~�[�m�[�h���w���Ă��Ȃ����`�F�b�N
	if (Itr.m_pCurrentNode == m_pDummy)
		return false;

	// �|�C���^���q���Ȃ���
	Itr.m_pCurrentNode->pPrev->pNext = Itr.m_pCurrentNode->pNext;
	Itr.m_pCurrentNode->pNext->pPrev = Itr.m_pCurrentNode->pPrev;

	// ���
	delete Itr.m_pCurrentNode;

	// �v�f�����X�V
	--m_ElementCount;

	return true;
}

void LinkedList::Clear(void)
{
	// �f�[�^��1�����Ȃ��Ƃ�
	if (m_ElementCount == 0)
		return;

	// �S�Ẵf�[�^���폜����
	while (m_ElementCount > 0)
	{
		auto Itr = GetBegin();
		Delete(Itr);
	}
}

LinkedList::ConstIterator LinkedList::GetConstBegin(void) const
{
	// �v�f����0�̎��̓_�~�[�m�[�h���w���C�e���[�^��Ԃ�
	if (m_ElementCount == 0)
	{
		ConstIterator Itr;
		Itr.m_pCurrentNode = m_pDummy;
		Itr.m_pList        = this;
		return Itr;
	}

	// ����ȊO�̎��͐擪�̃m�[�h���w���C�e���[�^��Ԃ�
	ConstIterator Itr;
	Itr.m_pCurrentNode = m_pDummy->pNext;
	Itr.m_pList        = this;

	return Itr;
}

LinkedList::Iterator LinkedList::GetBegin(void)
{
	// �v�f����0�̎��̓_�~�[�m�[�h���w���C�e���[�^��Ԃ�
	if (m_ElementCount == 0)
	{
		Iterator Itr;
		Itr.m_pCurrentNode = m_pDummy;
		Itr.m_pList        = this;
		return Itr;
	}

	// ����ȊO�̎��͐擪�̃m�[�h���w���C�e���[�^��Ԃ�
	Iterator Itr;
	Itr.m_pCurrentNode = m_pDummy->pNext;
	Itr.m_pList        = this;

	return Itr;
}

LinkedList::ConstIterator LinkedList::GetConstEnd(void) const
{
	// ��Ƀ_�~�[�m�[�h���w���C�e���[�^��Ԃ�
	ConstIterator Itr;
	Itr.m_pCurrentNode = m_pDummy;
	Itr.m_pList        = this;
	return Itr;
}

LinkedList::Iterator LinkedList::GetEnd(void)
{
	// ��Ƀ_�~�[�m�[�h���w���C�e���[�^��Ԃ�
	Iterator Itr;
	Itr.m_pCurrentNode = m_pDummy;
	Itr.m_pList        = this;
	return Itr;
}
