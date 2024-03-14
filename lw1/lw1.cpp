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
#include <string>

void SearchMoves(std::vector<std::string>& board, int queenX,
	int queenY, std::vector<std::pair<int, int>>& currentPath,
	std::vector<std::pair<int, int>>& bestPath,
	int& maxCount, int count = 0, int directionX = 0, int directionY = 0) {

	if (count > maxCount) {
		maxCount = count;
		bestPath = currentPath;
	}

	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 || j == 0 || (i == (directionX * -1) && j == (directionY * -1)))
				continue;

			int currentX = queenX + i;
			int currentY = queenY + j;

			// Движение по диагонали, пока не встретится шашка или граница доски
			while (currentX >= 0 && currentX < 8 && currentY >= 0 && currentY < 8 && board[currentX][currentY] == '0') {
				currentX += i;
				currentY += j;
			}

			// Если не вышли за границу, тогда проверяем поле за шашкой
			if (currentX >= 0 && currentX < 8 && currentY >= 0 && currentY < 8 && board[currentX][currentY] == '1') {

				int nextX = currentX + i;
				int nextY = currentY + j;

				// Если за шашкой нет границы и клетка пустая, то убираем шашку с доски, добавляем координаты клетки
				while (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8 && board[nextX][nextY] == '0') {

					board[currentX][currentY] = '0';	
					currentPath.push_back({ nextX, nextY });

					SearchMoves(board, nextX, nextY, currentPath, bestPath, maxCount, count + 1, i, j);

					nextX = nextX + i;
					nextY = nextY + j;

					currentPath.pop_back();
					board[currentX][currentY] = '1';


				}

			}
		}
	}


}


int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;

	inputFile.open("input12.txt");
	outputFile.open("OUTPUT.txt");

	std::vector<std::string> board(8); // Доска 8х8

	std::vector<std::pair<int, int>> currentPath, bestPath;

	int queenX = -1, queenY = -1, maxCount = 0;

	for (int i = 0; i < 8; ++i) {
		std::getline(inputFile, board[i]);
		for (int j = 0; j < 8; ++j) {
			if (board[i][j] == '2') {
				queenX = i;
				queenY = j;
				board[i][j] = '0';
			}
		}
	}

	currentPath.push_back({ queenX, queenY });
	SearchMoves(board, queenX, queenY, currentPath, bestPath, maxCount, 0, 0 ,0);

	outputFile << maxCount << std::endl;

	for (std::pair<int, int>& moves : bestPath) {
		outputFile << moves.first + 1 << " " << moves.second + 1 << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}

