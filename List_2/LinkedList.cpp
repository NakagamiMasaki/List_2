/**
* @file		LinkedList.cpp
* @brief	双方向リスト定義
* @data		2022/10/04
*/

//===== インクルード =====
#include "LinkedList.h"
#include <assert.h>

//===== 関数定義 =====

//====== LinkedList::ConstIterator =====

LinkedList::ConstIterator::ConstIterator(void)
	: m_pCurrentNode(nullptr)
	, m_pList(nullptr)
{
}

LinkedList::ConstIterator& LinkedList::ConstIterator::operator--(void)
{
	// リストの先頭方向に1つ進む
	assert(m_pCurrentNode && m_pList && "InvalidReference");								// リストを参照しているか？
	assert(m_pCurrentNode->pPrev->Data.Name != "DummyNode" && "This Iterator Is Begin");	// 先頭ノードを既に指しているのに、さらに前に進もうとしていないか？
	m_pCurrentNode = m_pCurrentNode->pPrev;
	return *this;
}

LinkedList::ConstIterator& LinkedList::ConstIterator::operator++(void)
{
	// リストの末尾方向に1つ進む
	assert(m_pCurrentNode && m_pList && "InvalidReference");						// リストを参照しているか？
	assert(m_pCurrentNode->Data.Name != "DummyNode" && "This Iterator Is End");		// ダミーノードを指しているのに、さらに進もうとしていないか？
	m_pCurrentNode = m_pCurrentNode->pNext;
	return *this;
}

LinkedList::ConstIterator LinkedList::ConstIterator::operator--(int)
{
	// リストの先頭方向に1つ進む
	assert(m_pCurrentNode && m_pList && "InvalidReference");								// リストを参照しているか？
	assert(m_pCurrentNode->pPrev->Data.Name != "DummyNode" && "This Iterator Is Begin");	// 先頭ノードを既に指しているのに、さらに前に進もうとしていないか？
	LinkedList::ConstIterator TempItr = *this;	// コピーする
	m_pCurrentNode = m_pCurrentNode->pPrev;

	return TempItr;
}

LinkedList::ConstIterator LinkedList::ConstIterator::operator++(int)
{
	// リストの末尾方向に1つ進む
	assert(m_pCurrentNode && m_pList && "InvalidReference");						// リストを参照しているか？
	assert(m_pCurrentNode->Data.Name != "DummyNode" && "This Iterator Is End");		// ダミーノードを指しているのに、さらに進もうとしていないか？
	LinkedList::ConstIterator TempItr = *this;	// コピーする
	m_pCurrentNode = m_pCurrentNode->pNext;

	return TempItr;
}

const ScoreData& LinkedList::ConstIterator::operator*(void) const
{
	// 不正なイテレータでないことを確認する
	assert(m_pList && m_pCurrentNode && "Invalid Reference");						// 適切な参照を持つか？
	assert(m_pCurrentNode->Data.Name != "DummyNode" && "This Iterator Is End");		// ダミーノードを指していないか？
	return m_pCurrentNode->Data;
}

const ScoreData* LinkedList::ConstIterator::operator->(void) const
{
	// 不正なイテレータでないことを確認する
	assert(m_pList && m_pCurrentNode && "Invalid Reference");						// 適切な参照を持つか？
	assert(m_pCurrentNode->Data.Name != "DummyNode" && "This Iterator Is End");		// ダミーノードを指していないか？
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
	// 不正なイテレータでないことを確認する
	assert(m_pList && m_pCurrentNode && "Invalid Reference");						// 適切な参照を持つか？
	assert(m_pCurrentNode->Data.Name != "DummyNode" && "This Iterator Is End");		// ダミーノードを指していないか？
	return m_pCurrentNode->Data;
}

ScoreData* LinkedList::Iterator::operator->(void)
{
	// 不正なイテレータでないことを確認する
	assert(m_pList && m_pCurrentNode && "Invalid Reference");						// 適切な参照を持つか？
	assert(m_pCurrentNode->Data.Name != "DummyNode" && "This Iterator Is End");		// ダミーノードを指していないか？
	return &m_pCurrentNode->Data;
}

//===== LinkedList =====
LinkedList::LinkedList(void)
	: m_ElementCount(0)
	, m_pDummy(nullptr)
{
	m_pDummy = new Node;
	m_pDummy->pNext      = m_pDummy;
	m_pDummy->pPrev      = m_pDummy;
	m_pDummy->Data.Score = 0;
	m_pDummy->Data.Name  = "DummyNode";
}

LinkedList::~LinkedList(void)
{
	Clear();

	// ダミーノードを解放する
	delete m_pDummy;
}

size_t LinkedList::GetSize(void) const
{
	return m_ElementCount;
}

bool LinkedList::Insert(ConstIterator& Itr, const ScoreData& Data)
{
	//*** 引数のチェック
	if (Data.Name.empty() || Data.Score < 0)
		return false;

	//*** イテレータの有効性をチェック
	// ダミーノードを指している == 末尾イテレータなので、それは許容する
	if (!Itr.m_pCurrentNode || Itr.m_pList != this)
		return false;

	//*** 新しい要素を渡されたイテレータの前に挿入する
	// 新しいイテレータとノードを作成する
	ConstIterator NewItr;		// 新しいイテレータ
	Node* pNode = new Node;		// 新しいノード

	// 初期化
	pNode->Data = Data;	// データを設定

	// ポインタを繋ぎなおす
	pNode->pPrev                       = Itr.m_pCurrentNode->pPrev;
	pNode->pNext                       = Itr.m_pCurrentNode;
	Itr.m_pCurrentNode->pPrev->pNext   = pNode;
	Itr.m_pCurrentNode->pPrev          = pNode;

	// 要素数を更新
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
	// 要素数のチェック
	if (m_ElementCount == 0)
		return false;

	// イテレータが不正でないことをチェック
	if (!Itr.m_pCurrentNode || Itr.m_pList != this)
		return false;

	// ダミーノードを指していないかチェック
	if (Itr.m_pCurrentNode == m_pDummy)
		return false;

	// ポインタを繋ぎなおす
	Itr.m_pCurrentNode->pPrev->pNext = Itr.m_pCurrentNode->pNext;
	Itr.m_pCurrentNode->pNext->pPrev = Itr.m_pCurrentNode->pPrev;

	// 解放
	delete Itr.m_pCurrentNode;
	Itr.m_pCurrentNode = nullptr;

	// 要素数を更新
	--m_ElementCount;

	return true;
}

void LinkedList::Clear(void)
{
	// 全てのデータを削除する
	while (m_ElementCount > 0)
	{
		auto Itr = GetBegin();
		Delete(Itr);
	}
}

LinkedList::ConstIterator LinkedList::GetConstBegin(void) const
{
	// 先頭のノードを指すイテレータを返す
	ConstIterator Itr;
	Itr.m_pCurrentNode = m_pDummy->pNext;
	Itr.m_pList        = this;

	return Itr;
}

LinkedList::Iterator LinkedList::GetBegin(void)
{
	// 先頭のノードを指すイテレータを返す
	Iterator Itr;
	Itr.m_pCurrentNode = m_pDummy->pNext;
	Itr.m_pList        = this;

	return Itr;
}

LinkedList::ConstIterator LinkedList::GetConstEnd(void) const
{
	// 常にダミーノードを指すイテレータを返す
	ConstIterator Itr;
	Itr.m_pCurrentNode = m_pDummy;
	Itr.m_pList        = this;
	return Itr;
}

LinkedList::Iterator LinkedList::GetEnd(void)
{
	// 常にダミーノードを指すイテレータを返す
	Iterator Itr;
	Itr.m_pCurrentNode = m_pDummy;
	Itr.m_pList        = this;
	return Itr;
}
