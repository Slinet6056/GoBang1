#ifndef PLAY
#define PLAY

#include "initialize.h"

extern int boardValue[N + 2][N + 2];

int play();

void undo(int x);

bool judge();

int placeChess_player(int);

void placeChess_AI(int);

void printPieces(Point pos, int);

int evaluate(int);

void getLine(int[], int);

#endif //PLAY