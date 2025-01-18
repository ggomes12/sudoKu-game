#ifndef SUDOKU_H
#define SUDOKU_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 9

// Estrutura para o tabuleiro e auxiliares
typedef struct
{
    int board[SIZE][SIZE];
    bool rows[SIZE][SIZE];  // Rastreia números presentes em cada linha
    bool cols[SIZE][SIZE];  // Rastreia números presentes em cada coluna
    bool boxes[SIZE][SIZE]; // Rastreia números presentes em cada submatriz
} Sudoku;

// Declaração de funções
void displayBoard(const Sudoku *game);
void initializeBoard(Sudoku *game);
void fillRandomNumbers(Sudoku *game);

bool insertNumber(Sudoku *game, int row, int col, int num);
bool isValidMove(const Sudoku *game, int row, int col, int num);
int getBoxIndex(int row, int col);
void updateTracking(Sudoku *game, int row, int col, int num, bool add);

#endif
