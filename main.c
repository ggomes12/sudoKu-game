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

int main () {

	Sudoku game;
	initializeBoard(&game);

	fillRandomNumbers(&game);

	displayBoard(&game);

	return 0;
}