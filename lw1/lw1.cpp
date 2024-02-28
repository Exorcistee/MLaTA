/*
 Задача 1.8
 Уразаев К.В. ПС-22
 На шахматном поле расположены N черных шашек и одна белая дамка.
 Требуется написать программу, которая по заданному расположению шашек определяет,
 какое максимальное количество шашек может взять белая дамка за один ход.
*/

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	inputFile.open("INPUT.txt");
	outputFile.open("OUTPUT.txt");

	std::vector<std::vector<char>>  board(8, std::vector<char>(8));

	int queenX, queenY;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			inputFile >> board[i][j];
			if (board[i][j] == '2') {
				queenX = i;
				queenY = j;
			}
		}
	}

}

