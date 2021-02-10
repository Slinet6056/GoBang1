#ifndef INITIALIZE
#define INITIALIZE

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include <stack>
#include <string>
#include <climits>
#include <graphics.h>
#include <windows.h>

#define myBLACK RGB(75, 74, 73)
#define myWHITE RGB(255, 253, 249)
#define BKCOLOR RGB(247, 238, 214)
struct Point {
    int x = 0;
    int y = 0;
};
const struct {
    int LIAN5;
    int HUO4;
    int CHONG4;
    int HUO3;
    int MIAN3;
    int HUO2;
    int MIAN2;
} chessType = {100000000, 1000, 300, 200, 50, 30, 5};
const int N = 15;
extern int firstPlayer, secondPlayer;
extern int board[N + 2][N + 2];
extern std::stack<Point> record;

void initialize();

#endif //INITIALIZE