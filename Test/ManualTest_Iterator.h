/**
* @file		ManualTest_Iterator.h
* @brief	双方向リスト イテレータ 手動テスト
* @data		2022/10/04
*/

#pragma once

//===== マクロ定義 =====
/**
* @define	CAN_NOT_ASSIGN_TO_CONSTITERATOR_ELEMENT
* @brief	コンストなイテレータを通してデータの代入ができないことの確認です。
*			コンパイルに失敗したら成功です。
*/
//#define CAN_NOT_ASSIGN_TO_CONSTITERATOR_ELEMENT

/**
* @define	CAN_NOT_COPY_FROM_CONST_ITERATOR
* @brief	コンストなイテレータからコピーして非コンストなイテレータをコピー作成できないことの確認です。
*			コンパイルに失敗したら成功です。
*/
//#define CAN_NOT_COPY_FROM_CONST_ITERATOR

/**
* @define	CAN_NOT_ASSIGN_CONST_ITERATOR_TO_ITERATOR
* @brief	非コンストなイテレータにコンストイテレータを代入できないことを確認です。
*			コンパイルに失敗したら成功です。
*/
//#define CAN_NOT_ASSIGN_CONST_ITERATOR_TO_ITERATOR