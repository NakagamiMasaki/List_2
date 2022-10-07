/**
* @file		main.cpp
* @brief	�o�������X�g �Ď����ۑ�
* @data		2022/10/04
*/

//===== �C���N���[�h =====
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

/**
* @fn		main(void)
* @brief	�G���g���[�|�C���g
* @return	������ : 0 | ���s�� : 0�ȊO
*/
int main(void)
{
	//*** �ϐ��錾
	LinkedList List;

	//*** �t�@�C���ǂݍ���
	std::ifstream File;
	File.open("Scores.txt");
	if (!File.is_open())
	{
		// �G���[���b�Z�[�W�\�� & �ҋ@
		std::cout << "Scores.txt�̓ǂݍ��݂Ɏ��s���܂����B���萔�ł����Aexe�t�@�C���Ɠ��K�w�Ƀt�@�C�������邩���m���߂��������B" << std::endl;
		std::cout << "�I������ɂ̓G���^�[�L�[�������Ă��������B" << std::endl;

		rewind(stdin);
		getchar();

		return -1;
	}

	//*** 1�s���ǂݍ���ł���
	std::string szLoadedText;
	while (std::getline(File, szLoadedText))
	{
		std::string Score;	// �X�R�A
		std::string Name;	// ���O

		// �^�u�ŃX�R�A�ƃ��[�U�[������؂�
		auto TabPos = szLoadedText.find('\t');		// �^�u������ʒu
		Score.assign(szLoadedText, 0, TabPos);		// �^�u�̑O�܂ŃR�s�[
		Name.assign(szLoadedText, TabPos + 1, std::string::npos);	// �^�u�̌�납��Ō�܂ŃR�s�[

		// ���X�g�ɒǉ�
		ScoreData Data;
		Data.Score = std::stoi(Score);
		Data.Name = Name;
		auto Itr = List.GetBegin();
		List.Insert(Itr, Data);
	}

	//*** ���g��S�ĕ\��
	for (auto Itr = List.GetConstBegin(); Itr != List.GetConstEnd(); ++Itr)
	{
		auto& Data = *Itr;
		std::cout << Data.Score << "\t" << Data.Name << std::endl;
	}

	// �ҋ@
	std::cout << std::endl;
	std::cout << "�I������ɂ̓G���^�[�L�[�������Ă��������B" << std::endl;
	rewind(stdin);
	getchar();

	return 0;
}