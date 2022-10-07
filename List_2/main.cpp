/**
* @file		main.cpp
* @brief	双方向リスト 再実装課題
* @data		2022/10/04
*/

//===== インクルード =====
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

/**
* @fn		main(void)
* @brief	エントリーポイント
* @return	成功時 : 0 | 失敗時 : 0以外
*/
int main(void)
{
	//*** 変数宣言
	LinkedList List;

	//*** ファイル読み込み
	std::ifstream File;
	File.open("Scores.txt");
	if (!File.is_open())
	{
		// エラーメッセージ表示 & 待機
		std::cout << "Scores.txtの読み込みに失敗しました。お手数ですが、exeファイルと同階層にファイルがあるかお確かめください。" << std::endl;
		std::cout << "終了するにはエンターキーを押してください。" << std::endl;

		rewind(stdin);
		getchar();

		return -1;
	}

	//*** 1行ずつ読み込んでいく
	std::string szLoadedText;
	while (std::getline(File, szLoadedText))
	{
		std::string Score;	// スコア
		std::string Name;	// 名前

		// タブでスコアとユーザー名を区切る
		auto TabPos = szLoadedText.find('\t');		// タブがある位置
		Score.assign(szLoadedText, 0, TabPos);		// タブの前までコピー
		Name.assign(szLoadedText, TabPos + 1, std::string::npos);	// タブの後ろから最後までコピー

		// リストに追加
		ScoreData Data;
		Data.Score = std::stoi(Score);
		Data.Name = Name;
		auto Itr = List.GetBegin();
		List.Insert(Itr, Data);
	}

	//*** 中身を全て表示
	for (auto Itr = List.GetConstBegin(); Itr != List.GetConstEnd(); ++Itr)
	{
		auto& Data = *Itr;
		std::cout << Data.Score << "\t" << Data.Name << std::endl;
	}

	// 待機
	std::cout << std::endl;
	std::cout << "終了するにはエンターキーを押してください。" << std::endl;
	rewind(stdin);
	getchar();

	return 0;
}