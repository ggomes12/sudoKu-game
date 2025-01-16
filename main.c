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

int main () {

	Sudoku game;
	initializeBoard(&game);

	displayBoard(&game);

	return 0;
}