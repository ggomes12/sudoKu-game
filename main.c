#include "sudoKu.h"
#include <locale.h>
#include <string.h>

void initializeBoard(Sudoku *game)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			game->board[i][j] = 0;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			game->rows[i][j] = false;
			game->cols[i][j] = false;
			game->boxes[i][j] = false;
		}
	}
}

void displayBoard(const Sudoku *game)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 3 == 0 && i != 0)
		{
			wprintf(L"---------------------\n");
		}
		for (int j = 0; j < SIZE; j++)
		{
			if (j % 3 == 0 && j != 0)
			{
				wprintf(L"| ");
			}
			wprintf(L"%d ", game->board[i][j]);
		}
		wprintf(L"\n");
	}
}

void fillRandomNumbers(Sudoku *game)
{
	srand(time(NULL));

	for (int boxRow = 0; boxRow < SIZE; boxRow += 3)
	{
		for (int boxCol = 0; boxCol < SIZE; boxCol += 3)
		{
			int numbersPlaced = 0;
			while (numbersPlaced < 3)
			{
				int row = boxRow + rand() % 3;
				int col = boxCol + rand() % 3;
				int num = 1 + rand() % 9;

				if (game->board[row][col] == 0 && isValidMove(game, row, col, num))
				{
					game->board[row][col] = num;
					updateTracking(game, row, col, num, true);
					numbersPlaced++;
				}
			}
		}
	}
}

bool insertNumber(Sudoku *game, int row, int col, int num)
{
	if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
	{
		wprintf(L"Erro: Posição inválida!\n");
		return false;
	}
	if (num < 1 || num > 9)
	{
		wprintf(L"Erro: Número inválido! Insira um número entre 1 e 9.\n");
		return false;
	}
	if (game->board[row][col] != 0)
	{
		wprintf(L"Erro: A posição já está preenchida.\n");
		return false;
	}
	if (!isValidMove(game, row, col, num))
	{
		wprintf(L"Erro: Movimento inválido. Viola as regras do Sudoku.\n");
		return false;
	}
	game->board[row][col] = num;
	updateTracking(game, row, col, num, true);

	return true;
}

bool isValidMove(const Sudoku *game, int row, int col, int num)
{
	int boxIndex = getBoxIndex(row, col);
	return !game->rows[row][num - 1] && !game->cols[col][num - 1] && !game->boxes[boxIndex][num - 1];
}

int getBoxIndex(int row, int col)
{
	return (row / 3) * 3 + (col / 3);
}

void updateTracking(Sudoku *game, int row, int col, int num, bool add)
{
	int boxIndex = getBoxIndex(row, col);
	game->rows[row][num - 1] = add;
	game->cols[col][num - 1] = add;
	game->boxes[boxIndex][num - 1] = add;
}

bool isSolved(const Sudoku *game)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (game->board[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "");
	Sudoku game;
	initializeBoard(&game);

	fillRandomNumbers(&game);

	int row, col, num;

	while (!isSolved(&game))
	{
		displayBoard(&game);
		wprintf(L"Insira a linha, coluna e número (1-9) separados por espaço:\n");
		if (scanf("%d %d %d", &row, &col, &num) != 3)
		{
			wprintf(L"Erro: Entrada inválida! Tente novamente.\n");
			while (getchar() != '\n')
				continue;
		}

		if (insertNumber(&game, row - 1, col - 1, num))
		{
			wprintf(L"Número inserido com sucesso!\n");
		}
		else
		{
			wprintf(L"Falha ao inserir o número. Tente novamente.\n");
		}
	}

	wprintf(L"Isso aí!!! Você resolveu o Sudoku!\n");
	return 0;
}
