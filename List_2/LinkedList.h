/**
* @file		LinkedList.h
* @brief	双方向リスト定義
* @data		2022/10/04
*/

#pragma once

//===== インクルード =====
#include "Score.h"

//===== クラス定義 =====
/**
* @class	LinkedList
* @brief	双方向リスト
*/
class LinkedList
{
	//=== 構造体定義
private:

	/**
	* @struct	LinkedList::Node
	* @brief	双方向リストのノード
	*/
	struct Node
	{
		Node* pPrev;		// 前ノードへのポインタ
		Node* pNext;		// 次ノードへのポインタ

		ScoreData	Data;	// 成績データ
	};

	//=== クラス定義
public:

	/**
	* @class	LinkedList::ConstIterator
	* @brief	双方向リストのコンストイテレータ
	*/
	class ConstIterator
	{
		//=== メンバ変数
	protected:

		LinkedList::Node*	m_pCurrentNode;		// このイテレータが現在参照しているノード
		const LinkedList*	m_pList;			// どのリストのイテレータか判別できるように

		//=== メンバ関数
	public:

		/**
		* @fn		ConstIterator::ConstIterator(void)
		* @brief	デフォルトコンストラクタ
		*/
		ConstIterator(void);

		/**
		* @fn		ConstIterator::operator--(void)
		* @brief	リストの先頭に向かって1つ進む(前置デクリメント)
		*/
		ConstIterator& operator--(void);

		/**
		* @fn		ConstIterator::operator++(void)
		* @brief	リストの末尾に向かって1つ進む(前置インクリメント)
		*/
		ConstIterator& operator++(void);

		/**
		* @fn		ConstIterator::operator--(void)
		* @brief	リストの先頭に向かって1つ進む(後置デクリメント)
		*/
		ConstIterator operator--(int);

		/**
		* @fn		ConstIterator::operator++(void)
		* @brief	リストの末尾に向かって1つ進む(後置インクリメント)
		*/
		ConstIterator operator++(int);

		/**
		* @fn		ConstIterator::operator*(void) const
		* @brief	イテレータが指す要素を取得する(コンスト版)
		*/
		const ScoreData& operator*(void) const;

		/**
		* @fn		ConstIterator::operator*(void) const
		* @brief	イテレータが指す要素を取得する(コンスト版)
		*/
		const ScoreData* operator->(void) const;

		/**
		* @fn		ConstIterator::ConstIterator(const ConstIterator& ConstItr)
		* @brief	イテレータのコピーを行う(コピーコンストラクタ)
		*/
		ConstIterator(const ConstIterator& ConstItr);

		/**
		* @fn		ConstIterator::operator=(const ConstIterator& ConstItr)
		* @brief	イテレータのコピー代入を行う
		* @return	このイテレータへの左辺値参照
		*/
		ConstIterator& operator=(const ConstIterator& Itr);

		/**
		* @fn		ConstIterator::operator=(const ConstIterator& ConstItr) const
		* @brief	このイテレータと同一か比較する
		* @return	同一なら true , 異なるなら false
		*/
		bool operator==(const ConstIterator& Itr) const;

		/**
		* @fn		ConstIterator::operator=(const ConstIterator& ConstItr) const
		* @brief	このイテレータと異なるか比較する
		* @return	異なるなら true , 同一なら false
		*/
		bool operator!=(const ConstIterator& Itr) const;

		/**
		* @fn		ConstIterator::IsInvalidReference(void) const
		* @brief	このイテレータが適切な参照を持っているかチェックする
		* @return	適切に設定されていれば true | 不正な参照なら false
		*/
		bool IsValidReference(void) const;

		/**
		* @fn		ConstIterator::IsInvalidReference(void) const
		* @brief	このイテレータがダミーノードを指しているかチェックする。
		* @details	本来は必要ないと思いますが、内部の実装上外部からダミーノードを指しているか確認する方法がないため実装しています。
		* @return	ダミーノードを指していれば true | 指していなければ false
		*/
		bool IsDummy(void) const;

		/**
		* @fn		ConstIterator::IsInvalidReference(void) const
		* @brief	不正なイテレータでないことをチェックする。
		* @return	不正でないなら true | 不正なイテレータなら false
		*/
		bool IsValid(void) const;

		/**
		* @fn		ConstIterator::operator bool(void) const
		* @brief	不正なイテレータでないことをチェックする。
		* @return	不正でないなら true | 不正なイテレータなら false
		*/
		operator bool(void) const;

		friend LinkedList;
	};

	/**
	* @class	LinkedList::Iterator
	* @brief	双方向リストの非コンストイテレータ
	*/
	class Iterator : public ConstIterator
	{
		//=== メンバ関数
	public:

		/**
		* @fn		Iterator::operator*(void)
		* @brief	イテレータが指す要素を取得する(非コンスト版)
		*/
		ScoreData& operator*(void);

		/**
		* @fn		Iterator::operator->(void)
		* @brief	イテレータが指す要素を取得する(非コンスト版)
		*/
		ScoreData* operator->(void);
	};

	//=== メンバ変数
private:

	size_t	m_ElementCount;	// 要素数
	Node*	m_pDummy;		// ダミーノード(Prevに末尾ノード、Nextに先頭ノード)

	//=== メンバ関数
public:

	/**
	* @fn		LinkedList::LinkedList(void)
	* @brief	デフォルトコンストラクタ
	*/
	LinkedList(void);

	/**
	* @fn		LinkedList::~LinkedList(void)
	* @brief	デストラクタ
	*/
	~LinkedList(void);

	/**
	* @fn		LinkedList::GetSize(void)
	* @brief	データ数の取得
	*/
	size_t GetSize(void) const;

	/**
	* @fn			LinkedList::Insert(ConstIterator&, const ScoreData&)
	* @brief		データの挿入
	* @param[in]	Itr		挿入したい位置
	* @param[in]	Data	新しく挿入したいデータ
	* @return		成功時 : true | 失敗時 : false
	*/
	bool Insert(ConstIterator& Itr, const ScoreData& Data);

	/**
	* @fn			LinkedList::Pushback(const ScoreData&)
	* @brief		データを末尾に追加
	* @param[in]	Data	新しく追加したいデータ
	* @return		成功時 : true | 失敗時 : false
	*/
	bool Pushback(const ScoreData& Data);

	/**
	* @fn			LinkedList::Pushfront(const ScoreData&)
	* @brief		データを先頭に追加
	* @param[in]	Data	新しく追加したいデータ
	* @return		成功時 : true | 失敗時 : false
	*/
	bool Pushfront(const ScoreData& Data);

	/**
	* @fn			LinkedList::Delete(ConstIterator&)
	* @brief		データの削除
	* @param[in]	Itr		削除したいデータ
	* @return		成功時 : true | 失敗時 : false
	*/
	bool Delete(ConstIterator& Itr);

	/**
	* @fn			LinkedList::Clear(void)
	* @brief		全てのデータの削除
	*/
	void Clear(void);

	/**
	* @fn		LinkedList::GetConstBegin(void) const
	* @brief	先頭のコンストなイテレータを取得
	* @return	先頭のコンストなイテレータ
	*/
	ConstIterator GetConstBegin(void) const;

	/**
	* @fn		LinkedList::GetFront(void)
	* @brief	先頭のイテレータを取得
	* @return	先頭のイテレータ
	*/
	Iterator GetBegin(void);

	/**
	* @fn		LinkedList::GetConstEnd(void) const
	* @brief	末尾のコンストなイテレータを取得
	* @return	末尾のコンストなイテレータ
	*/
	ConstIterator GetConstEnd(void) const;

	/**
	* @fn		LinkedList::GetEnd(void)
	* @brief	末尾のイテレータを取得
	* @return	末尾のイテレータ
	*/
	Iterator GetEnd(void);

	friend ConstIterator;
	friend Iterator;
};

