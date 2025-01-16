#include "sudoKu.h"

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
			printf("---------------------\n");
		}
		for (int j = 0; j < SIZE; j++)
		{
			if (j % 3 == 0 && j != 0)
			{
				printf("| ");
			}
			printf("%d ", game->board[i][j]);
		}
		printf("\n");
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

				if (game->board[row][col] == 0)
				{
					game->board[row][col] = num;
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
		printf("Erro: Posição inválida!\n");
		return false;
	}
	if (num < 1 || num > 9)
	{
		printf("Erro: Número inválido! Insira um número entre 1 e 9.\n");
		return false;
	}
	if (game->board[row][col] != 0)
	{
		printf("Erro: A posição já está preenchida.\n");
		return false;
	}
	game->board[row][col] = num;

	return true;
}


int main () {

	Sudoku game;
	initializeBoard(&game);

	fillRandomNumbers(&game);

	int row, col, num;

	displayBoard(&game);
	printf("Insira a linha, coluna e numero (1-9) separados por espaco: ");
	if (scanf("%d %d %d", &row, &col, &num) != 3)
	{
		printf("Erro: Entrada invahlida! Tente novamente.\n");
		while (getchar() != '\n')
			continue;
	}

	if (insertNumber(&game, row - 1, col - 1, num))
	{
		printf("Numero inserido com sucesso!\n");
	}
	else
	{
		printf("Falha ao inserir o numero. Tente novamente.\n");
	}

	return 0;
}
