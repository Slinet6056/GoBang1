#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-branch-clone"

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <iterator>
#include <stack>
#include <string>
#include <climits>
#include <utility>
#include <graphics.h>
#include <conio.h>
#include <windows.h>

#define myBLACK RGB(75, 74, 73)
#define myWHITE RGB(255, 253, 249)
#define BKCOLOR RGB(247, 238, 214)
#define hasNeighbor ((i - 1 >= 1 && board[i - 1][j]) || (i + 1 <= N && board[i + 1][j]) || (j - 1 >= 1 && board[i][j - 1]) || (j + 1 <= N && board[i][j + 1]) || (i - 1 >= 1 && j - 1 >= 1 && board[i - 1][j - 1]) || (i - 1 >= 1 && j + 1 <= N && board[i - 1][j + 1]) || (i + 1 <= N && j - 1 >= 1 && board[i + 1][j - 1]) || (i + 1 <= N && j + 1 <= N && board[i + 1][j + 1]))
#define hasNextNeighbor ((i - 2 >= 1 && board[i - 2][j]) || (i + 2 <= N && board[i + 2][j]) || (j - 2 >= 1 && board[i][j - 2]) || (j + 2 <= N && board[i][j + 2]) || (i - 2 >= 1 && j - 2 >= 1 && board[i - 2][j - 2]) || (i - 2 >= 1 && j + 2 <= N && board[i - 2][j + 2]) || (i + 2 <= N && j - 2 >= 1 && board[i + 2][j - 2]) || (i + 2 <= N && j + 2 <= N && board[i + 2][j + 2]))
using namespace std;

const int N = 15;
int board[N + 2][N + 2] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int boardValue[N + 2][N + 2] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 0},
        {0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 0},
        {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
typedef struct {
    int x;
    int y;
} Point;
const struct {
    int LIAN5;
    int HUO4;
    int CHONG4;
    int HUO3;
    int MIAN3;
    int HUO2;
    int MIAN2;
} chessType = {100000000, 1000, 300, 200, 50, 30, 5};
stack<Point> record; // NOLINT(cert-err58-cpp)
int firstPlayer, secondPlayer;

void initialize();

int play();

void undo(int x);

bool judge();

int placeChess_player(int);

void placeChess_AI(int);

int search(int, int);

vector<Point> generator();

void printPieces(Point pos, int);

int evaluate(int);

void getLine(int[], int);

int analysisLine_my(const int[], int);

int analysisLine_opponent(const int[], int);

int main() {
    initgraph(950, 750);
    int result, temp;
    initialize();
    while (true) {
        temp = 1;
        result = play();
        if (result == -1) {
            initialize();
            temp = 0;
        }
        MOUSEMSG m; // NOLINT(cppcoreguidelines-pro-type-member-init)
        while (temp) {
            m = GetMouseMsg();
            switch (m.uMsg) {
                case WM_LBUTTONDOWN:
                    if (m.x > 760 && m.x < 930 && m.y > 650 && m.y < 710) { //退出
                        exit(0);
                    } else if (m.x > 760 && m.x < 930 && m.y > 490 && m.y < 550) { //悔棋
                        if (firstPlayer == 1 && secondPlayer == 1) undo(3);
                        else if (!(firstPlayer == 2 && secondPlayer == 2)) undo(4);
                        if (!(firstPlayer == 2 && secondPlayer == 2)) temp = 0;
                    } else if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480) { //重新开始
                        initialize();
                        temp = 0;
                    }
                    break;
            }
        }
    }
}

void initialize() {
    while (!record.empty()) record.pop();
    memset(board, 0, sizeof(board));
    firstPlayer = 1;
    secondPlayer = 1;
    setbkcolor(BKCOLOR);
    cleardevice();
    LOGFONT f;
    RECT r;
    //棋盘线
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID, 1);
    for (int i = 75; i <= 675; i += 50) {
        line(i, 25, i, 725);
        line(25, i, 725, i);
    }
    setlinestyle(PS_SOLID, 3);
    line(25, 25, 25, 725);
    line(725, 25, 725, 725);
    line(25, 25, 725, 25);
    line(25, 725, 725, 725);
    //棋盘点
    setfillcolor(BLACK);
    solidcircle(375, 375, 3);
    solidcircle(175, 175, 3);
    solidcircle(175, 575, 3);
    solidcircle(575, 175, 3);
    solidcircle(575, 575, 3);
    //先手-提示文字
    gettextstyle(&f);
    f.lfHeight = 30;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(BKCOLOR);
    outtextxy(760, 20, _T("先手-黑子:"));
    //先手-选择1
    setfillcolor(myBLACK);
    solidroundrect(760, 60, 930, 120, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myWHITE);
    setbkcolor(myBLACK);
    r = {760, 60, 930, 120};
    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //先手-选择2
    setfillcolor(myWHITE);
    solidroundrect(760, 130, 930, 190, 25, 25);
    setlinecolor(myBLACK);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myWHITE);
    roundrect(761, 131, 929, 189, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(myWHITE);
    r = {760, 130, 930, 190};
    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //后手-提示文字
    gettextstyle(&f);
    f.lfHeight = 30;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(BKCOLOR);
    outtextxy(760, 210, _T("后手-白子:"));
    //后手-选择1
    setfillcolor(myBLACK);
    solidroundrect(760, 250, 930, 310, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myWHITE);
    setbkcolor(myBLACK);
    r = {760, 250, 930, 310};
    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //后手-选择2
    setfillcolor(myWHITE);
    solidroundrect(760, 320, 930, 380, 25, 25);
    setlinecolor(myBLACK);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myWHITE);
    roundrect(761, 321, 929, 379, 25, 25);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(myWHITE);
    r = {760, 320, 930, 380};
    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //开始按钮
    setfillcolor(myWHITE);
    solidroundrect(760, 420, 930, 480, 25, 25);
    setlinecolor(myBLACK);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myWHITE);
    roundrect(761, 421, 929, 479, 24, 24);
    roundrect(767, 427, 923, 473, 18, 18);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myBLACK);
    setbkcolor(myWHITE);
    r = {760, 420, 930, 480};
    drawtext(_T("开  始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //退出
    setfillcolor(myBLACK);
    solidroundrect(760, 660, 930, 720, 25, 25);
    setlinecolor(myWHITE);
    setlinestyle(PS_SOLID, 3);
    setbkcolor(myBLACK);
    roundrect(764, 664, 926, 716, 20, 20);
    gettextstyle(&f);
    f.lfHeight = 35;
    f.lfQuality = ANTIALIASED_QUALITY;
    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
    settextstyle(&f);
    settextcolor(myWHITE);
    setbkcolor(myBLACK);
    r = {760, 660, 930, 720};
    drawtext(_T("退  出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    //鼠标操作
    MOUSEMSG m; // NOLINT(cppcoreguidelines-pro-type-member-init)
    int temp = 0;
    while (true) {
        m = GetMouseMsg();
        switch (m.uMsg) {
            case WM_LBUTTONDOWN:
                if (m.x > 760 && m.x < 930 && m.y > 60 && m.y < 120) { //先手-玩家
                    firstPlayer = 1;
                    setfillcolor(myBLACK);
                    solidroundrect(760, 60, 930, 120, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 60, 930, 120};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myWHITE);
                    solidroundrect(760, 130, 930, 190, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 131, 929, 189, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 130, 930, 190};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 130 && m.y < 190) { //先手-AI
                    firstPlayer = 2;
                    setfillcolor(myWHITE);
                    solidroundrect(760, 60, 930, 120, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 61, 929, 119, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 60, 930, 120};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myBLACK);
                    solidroundrect(760, 130, 930, 190, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 130, 930, 190};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 250 && m.y < 310) { //后手-玩家
                    secondPlayer = 1;
                    setfillcolor(myBLACK);
                    solidroundrect(760, 250, 930, 310, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 250, 930, 310};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myWHITE);
                    solidroundrect(760, 320, 930, 380, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 321, 929, 379, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 320, 930, 380};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 320 && m.y < 380) { //后手-AI
                    secondPlayer = 2;
                    setfillcolor(myWHITE);
                    solidroundrect(760, 250, 930, 310, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 251, 929, 309, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 250, 930, 310};
                    drawtext(_T("玩  家"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    setfillcolor(myBLACK);
                    solidroundrect(760, 320, 930, 380, 25, 25);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 320, 930, 380};
                    drawtext(_T("A    I"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                } else if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480) { //按下开始按钮
                    setfillcolor(myBLACK);
                    solidroundrect(760, 420, 930, 480, 25, 25);
                    setlinecolor(myWHITE);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myBLACK);
                    roundrect(764, 424, 926, 476, 20, 20);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myWHITE);
                    setbkcolor(myBLACK);
                    r = {760, 420, 930, 480};
                    drawtext(_T("开  始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    temp = 1;
                } else if (m.x > 760 && m.x < 930 && m.y > 650 && m.y < 710) { //退出
                    exit(0);
                }
                break;
            case WM_LBUTTONUP:
                if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480 && temp == 1) { //开始
                    //重新开始
                    setfillcolor(myWHITE);
                    solidroundrect(760, 420, 930, 480, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 421, 929, 479, 24, 24);
                    roundrect(767, 427, 923, 473, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 420, 930, 480};
                    drawtext(_T("重新开始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    //悔棋
                    setfillcolor(myWHITE);
                    solidroundrect(760, 490, 930, 550, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 491, 929, 549, 24, 24);
                    roundrect(767, 497, 923, 543, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 490, 930, 550};
                    drawtext(_T("悔  棋"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    //提示
                    setfillcolor(myWHITE);
                    solidroundrect(760, 560, 930, 620, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 561, 929, 619, 24, 24);
                    roundrect(767, 567, 923, 613, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 560, 930, 620};
                    drawtext(_T("提  示"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    return;
                } else {
                    setfillcolor(myWHITE);
                    solidroundrect(760, 420, 930, 480, 25, 25);
                    setlinecolor(myBLACK);
                    setlinestyle(PS_SOLID, 3);
                    setbkcolor(myWHITE);
                    roundrect(761, 421, 929, 479, 24, 24);
                    roundrect(767, 427, 923, 473, 18, 18);
                    gettextstyle(&f);
                    f.lfHeight = 35;
                    f.lfQuality = ANTIALIASED_QUALITY;
                    _tcscpy_s(f.lfFaceName, _T("微软雅黑"));
                    settextstyle(&f);
                    settextcolor(myBLACK);
                    setbkcolor(myWHITE);
                    r = {760, 420, 930, 480};
                    drawtext(_T("开  始"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    temp = 0;
                }
        }
    }
}

int play() {
    int temp;
    while (true) {
        if (record.size() % 2 == 0) {
            if (firstPlayer == 1) {
                temp = placeChess_player(1);
                if (temp) return -1;
            } else placeChess_AI(1);
            if (judge()) return 1;
            if (record.size() == 225) return 0;
        } else {
            if (secondPlayer == 1) {
                temp = placeChess_player(2);
                if (temp) return -1;
            } else placeChess_AI(2);
            if (judge()) return 2;
        }
    }
}

void undo(int x) {
    if (record.empty()) return;
    Point pos = {0, 0};
    switch (x) { // NOLINT(hicpp-multiway-paths-covered)
        case 1:
            pos = record.top();
            setfillcolor(BKCOLOR);
            solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 24);
            setlinestyle(PS_SOLID, 1);
            setlinecolor(BLACK);
            line(50 * pos.y - 49, 50 * pos.x - 25, 50 * pos.y - 1, 50 * pos.x - 25);
            line(50 * pos.y - 25, 50 * pos.x - 49, 50 * pos.y - 25, 50 * pos.x - 1);
            if ((pos.x == 4 && pos.y == 4) || (pos.x == 4 && pos.y == 12) || (pos.x == 8 && pos.y == 8) || (pos.x == 12 && pos.y == 4) || (pos.x == 12 && pos.y == 12)) {
                setfillcolor(BLACK);
                solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 3);
            }
            board[pos.x][pos.y] = 0;
            record.pop();
            if (!record.empty()) {
                pos = record.top();
                setfillcolor(RED);
                solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 5);
            }
            break;
        case 2:
            undo(1);
            undo(1);
            break;
        case 3:
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (board[i][j] == 1) {
                        pos.x = i;
                        pos.y = j;
                        setfillcolor(myBLACK);
                        solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 10);
                    } else if (board[i][j] == 2) {
                        pos.x = i;
                        pos.y = j;
                        setfillcolor(myWHITE);
                        solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 10);
                    }
                }
            }
            undo(1);
            break;
        case 4:
            undo(3);
            undo(1);
            break;
    }
}

bool judge() {
    int turn = 2 - (signed int) record.size() % 2;
    Point pos = record.top();
    for (int direction = 1; direction <= 4; direction++) { // 1:- 2:| 3:\ 4:/
        int line[11], cntLeft = 0, cntRight = 0;
        getLine(line, direction);
        for (; line[4 - cntLeft] == turn; cntLeft++);
        for (; line[6 + cntRight] == turn; cntRight++);
        if (cntLeft + cntRight + 1 == 5) {
            setfillcolor(RED);
            switch (direction) { // NOLINT(hicpp-multiway-paths-covered)
                case 1:
                    for (int i = 1; i <= cntLeft; i++) solidcircle(50 * (pos.y - i) - 25, 50 * pos.x - 25, 5);
                    for (int i = 1; i <= cntRight; i++) solidcircle(50 * (pos.y + i) - 25, 50 * pos.x - 25, 5);
                    return true;
                case 2:
                    for (int i = 1; i <= cntLeft; i++) solidcircle(50 * pos.y - 25, 50 * (pos.x - i) - 25, 5);
                    for (int i = 1; i <= cntRight; i++) solidcircle(50 * pos.y - 25, 50 * (pos.x + i) - 25, 5);
                    return true;
                case 3:
                    for (int i = 1; i <= cntLeft; i++) solidcircle(50 * (pos.y - i) - 25, 50 * (pos.x - i) - 25, 5);
                    for (int i = 1; i <= cntRight; i++) solidcircle(50 * (pos.y + i) - 25, 50 * (pos.x + i) - 25, 5);
                    return true;
                case 4:
                    for (int i = 1; i <= cntLeft; i++) solidcircle(50 * (pos.y + i) - 25, 50 * (pos.x - i) - 25, 5);
                    for (int i = 1; i <= cntRight; i++) solidcircle(50 * (pos.y - i) - 25, 50 * (pos.x + i) - 25, 5);
                    return true;
            }
        }
    }
    return false;
}

int placeChess_player(int turn) {
    Point pos;
    MOUSEMSG m; // NOLINT(cppcoreguidelines-pro-type-member-init)
    while (true) {
        m = GetMouseMsg();
        switch (m.uMsg) {
            case WM_LBUTTONDOWN:
                if (m.x > 760 && m.x < 930 && m.y > 650 && m.y < 710) { //退出
                    exit(0);
                } else if (m.x > 760 && m.x < 930 && m.y > 490 && m.y < 550) { //悔棋
                    if (firstPlayer == 1 && secondPlayer == 1) undo(1);
                    else {
                        undo(2);
                    }
                } else if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480) { //重新开始
                    return 1;
                } else if (m.x > 760 && m.x < 930 && m.y > 560 && m.y < 620) {
                    placeChess_AI(turn);
                    return 0;
                }
                break;
            case WM_LBUTTONUP:
                if (m.x < 750) {
                    pos.x = m.y / 50 + 1;
                    pos.y = m.x / 50 + 1;
                    if (board[pos.x][pos.y] == 0) {
                        turn = 2 - ((signed int) record.size() + 1) % 2;
                        printPieces(pos, turn);
                        board[pos.x][pos.y] = turn;
                        record.push(pos);
                        return 0;
                    }
                }
                break;
        }
    }
}

void placeChess_AI(int turn) {
    Point bestPos;
    int maxValue = INT_MIN;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 0) {
                Point p;
                p.x = i;
                p.y = j;
                board[i][j] = turn;
                record.push(p);
                if (evaluate(turn) + boardValue[i][j] > maxValue) {
                    bestPos.x = i;
                    bestPos.y = j;
                    maxValue = evaluate(turn) + boardValue[i][j];
                }
                board[i][j] = 0;
                record.pop();
            }
        }
    }
    printPieces(bestPos, turn);
    board[bestPos.x][bestPos.y] = turn;
    record.push(bestPos);
}

void printPieces(Point pos, int turn) {
    if (turn == 1) {
        if (!record.empty()) {
            Point previousPos = record.top();
            setfillcolor(myWHITE);
            solidcircle(50 * previousPos.y - 25, 50 * previousPos.x - 25, 5);
        }
        setfillcolor(myBLACK);
        solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 23);
        setfillcolor(RED);
        solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 5);
    } else if (turn == 2) {
        if (!record.empty()) {
            Point previousPos = record.top();
            setfillcolor(myBLACK);
            solidcircle(50 * previousPos.y - 25, 50 * previousPos.x - 25, 5);
        }
        setfillcolor(myWHITE);
        solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 23);
        setlinecolor(myBLACK);
        setlinestyle(PS_SOLID, 3);
        circle(50 * pos.y - 25, 50 * pos.x - 25, 22);
        setfillcolor(RED);
        solidcircle(50 * pos.y - 25, 50 * pos.x - 25, 5);
    }
}

int evaluate(int turn) {
    int myScore = 0, opponentScore = 0;
    for (int direction = 1; direction <= 4; direction++) { // 1:- 2:| 3:\ 4:/
        int line[11];
        getLine(line, direction);
        myScore += analysisLine_my(line, turn);
        opponentScore += analysisLine_opponent(line, turn);
    }
    return myScore + opponentScore;
}

void getLine(int line[], int direction) {
    Point pos = record.top();
    switch (direction) { // NOLINT(hicpp-multiway-paths-covered)
        case 1:
            for (int i = -5; i <= 5; i++)
                if (pos.y + i >= 1 && pos.y + i <= N)
                    line[i + 5] = board[pos.x][pos.y + i];
                else
                    line[i + 5] = -1;
            break;
        case 2:
            for (int i = -5; i <= 5; i++)
                if (pos.x + i >= 1 && pos.x + i <= N)
                    line[i + 5] = board[pos.x + i][pos.y];
                else
                    line[i + 5] = -1;
            break;
        case 3:
            for (int i = -5; i <= 5; i++)
                if (pos.x + i >= 1 && pos.y + i >= 1 && pos.x + i <= N && pos.y + i <= N)
                    line[i + 5] = board[pos.x + i][pos.y + i];
                else
                    line[i + 5] = -1;
            break;
        case 4:
            for (int i = -5; i <= 5; i++)
                if (pos.x + i >= 1 && pos.y - i >= 1 && pos.x + i <= N && pos.y - i <= N)
                    line[i + 5] = board[pos.x + i][pos.y - i];
                else
                    line[i + 5] = -1;
            break;
    }
}

int analysisLine_my(const int line[], int turn) {
    int myScore = 0, leftRange = 5, rightRange = 5;
    for (; line[leftRange - 1] == turn; leftRange--);
    for (; line[rightRange + 1] == turn; rightRange++);
    switch (rightRange - leftRange + 1) {
        case 5:
            return chessType.LIAN5;
        case 4:
            if (line[leftRange - 1] == 0 && line[rightRange + 1] == 0)
                return chessType.HUO4; //011110
            else if (line[leftRange - 1] == 0)
                return chessType.CHONG4; //011112
            else if (line[rightRange + 1] == 0)
                return chessType.CHONG4; //211110
            break;
        case 3:
            if (line[leftRange - 1] == 0 && line[rightRange + 1] == 0) {
                if ((line[leftRange - 2] == 3 - turn || line[leftRange - 2] == -1) &&
                    (line[rightRange + 2] == 3 - turn || line[rightRange + 2] == -1))
                    return chessType.MIAN3; //2011102
                else if (line[leftRange - 2] == 0 && line[rightRange + 2] == 0)
                    return chessType.HUO3; //0011100
                else if (((line[leftRange - 2] == 3 - turn || line[leftRange - 2] == -1) && line[rightRange + 2] == 0) ||
                         ((line[rightRange + 2] == 3 - turn || line[rightRange + 2] == -1) && line[leftRange - 2] == 0))
                    return chessType.HUO3; //2011100|0011102
            }
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == 0 && (line[rightRange + 1] == 3 - turn || line[rightRange + 1] == -1)) {
                if (rightRange == 5)
                    return chessType.MIAN3; //001112
                else
                    return chessType.MIAN3; //001112
            }
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == 0 && (line[leftRange - 1] == 3 - turn || line[leftRange - 1] == -1)) {
                if (leftRange == 5)
                    return chessType.MIAN3; //211100
                else
                    return chessType.MIAN3; //211100
            }
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn) {
                if (line[leftRange - 3] == 0 && rightRange == 5)
                    myScore += chessType.CHONG4; //010111
                else
                    myScore += chessType.CHONG4; //10111
            }
            if (line[rightRange + 2] == turn && line[rightRange + 1] == 0) {
                if (line[rightRange + 3] == 0 && leftRange == 5)
                    myScore += chessType.CHONG4; //111010
                else
                    myScore += chessType.CHONG4; //11101
            }
            break;
        case 2:
            if ((line[leftRange - 1] == 3 - turn || line[leftRange - 1] == -1) && line[rightRange + 1] == 0 && line[rightRange + 2] == turn && line[rightRange + 3] == 0) {
                if (leftRange == 5)
                    return chessType.MIAN3; //211010
                else
                    return chessType.MIAN3; //211010
            }
            if ((line[rightRange + 1] == 3 - turn || line[rightRange + 1] == -1) && line[leftRange - 1] == 0 && line[leftRange - 2] == turn && line[leftRange - 3] == 0) {
                if (rightRange == 5)
                    return chessType.MIAN3; //010112
                else
                    return chessType.MIAN3; //010112
            }
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == 0 && line[rightRange + 1] == 0 && line[rightRange + 2] == 0)
                return chessType.HUO2; //001100
            else if (line[leftRange - 1] == 0 && line[leftRange - 2] == 0) {
                if (line[rightRange + 2] == 3 - turn || line[rightRange + 2] == -1) {
                    if (line[leftRange - 3] == 0)
                        return chessType.HUO2; //0001102
                    else if (line[leftRange - 3] == 3 - turn || line[leftRange - 3] == -1)
                        return chessType.MIAN2; //2001102
                }
            } else if (line[rightRange + 1] == 0 && line[rightRange + 2] == 0) {
                if (line[leftRange - 2] == 3 - turn || line[leftRange - 2] == -1) {
                    if (line[rightRange + 3] == 0)
                        return chessType.HUO2; //2011000
                    else if (line[rightRange + 3] == 3 - turn || line[rightRange + 3] == -1)
                        return chessType.MIAN2; //2011002
                }
            }
            if ((line[leftRange - 1] != 0 && line[rightRange + 1] == 0 && line[rightRange + 2] == 0 && line[rightRange + 3] == 0) ||
                (line[rightRange + 1] != 0 && line[leftRange - 1] == 0 && line[leftRange - 2] == 0 && line[leftRange - 3] == 0))
                return chessType.MIAN2; //211000|000112
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn && line[leftRange - 3] == turn) {
                if (line[leftRange - 4] == 0 && rightRange == 5)
                    myScore += chessType.CHONG4; //011011
                else
                    myScore += chessType.CHONG4; //11011
            }
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == turn && line[rightRange + 3] == turn) {
                if (line[rightRange + 4] == 0 && leftRange == 5)
                    myScore += chessType.CHONG4; //011011
                else
                    myScore += chessType.CHONG4; //11011
            }
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn && (line[leftRange - 3] == 3 - turn || line[leftRange - 3] == -1) && line[rightRange + 1] == 0)
                myScore += chessType.MIAN3; //210110
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == turn && (line[rightRange + 3] == 3 - turn || line[rightRange + 3] == -1) && line[leftRange - 1] == 0)
                myScore += chessType.MIAN3; //011012
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn && line[leftRange - 3] == 0 && line[rightRange + 1] == 0)
                myScore += chessType.HUO3; //010110
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == turn && line[rightRange + 3] == 0 && line[leftRange - 1] == 0)
                myScore += chessType.HUO3; //011010
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == 0 && line[leftRange - 3] == turn) {
                if (line[leftRange - 4] == 0 && rightRange == 5)
                    myScore += chessType.MIAN3; //010011
                else
                    myScore += chessType.MIAN3; //10011
            }
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == 0 && line[rightRange + 3] == turn) {
                if (line[rightRange + 4] == 0 && leftRange == 5)
                    myScore += chessType.MIAN3; //110010
                else
                    myScore += chessType.MIAN3; //11001
            }
            break;
        case 1:
            if (line[4] == 0 && line[3] == turn && line[2] == turn && line[1] == turn) {
                if (line[0] == 0)
                    myScore += chessType.CHONG4; //011101
                else
                    myScore += chessType.CHONG4; //11101
            }
            if (line[6] == 0 && line[7] == turn && line[8] == turn && line[9] == turn) {
                if (line[10] == 0)
                    myScore += chessType.CHONG4; //101110
                else
                    myScore += chessType.CHONG4; //10111
            }
            if (line[4] == 0 && line[3] == turn && line[2] == turn) {
                if ((line[1] == 3 - turn || line[1] == -1) && line[6] == 0)
                    myScore += chessType.MIAN3; //211010
                else if (line[1] == 0 && (line[6] == 3 - turn || line[6] == -1)) {
                    if (line[0] == 0)
                        return chessType.MIAN3; //0011012
                    else
                        return chessType.MIAN3; //011012
                } else if (line[1] == 0 && line[6] == 0)
                    myScore += chessType.HUO3; //011010
            }
            if (line[6] == 0 && line[7] == turn && line[8] == turn) {
                if (line[4] == 0 && (line[9] == 3 - turn || line[9] == -1))
                    myScore += chessType.MIAN3; //010112
                else if ((line[4] == 4 - turn || line[4] == -1) && line[9] == 0) {
                    if (line[10] == 0)
                        return chessType.MIAN3; //2101100
                    else
                        return chessType.MIAN3; //210110
                } else if (line[4] == 0 && line[9] == 0)
                    myScore += chessType.HUO3; //010110
            }
            if ((line[4] == 0 && line[3] == 0 && line[2] == 0 && line[1] == turn) || (line[6] == 0 && line[7] == 0 && line[8] == 0 && line[9] == turn))
                myScore += chessType.MIAN2; //10001
            if (line[4] == 0 && line[3] == 0 && line[2] == turn) {
                if (line[1] == 0 && line[6] == 0)
                    myScore += chessType.HUO2; //010010
                else if (line[1] == 0 && (line[6] == 3 - turn || line[6] == -1))
                    return chessType.MIAN2; //010012
                else if ((line[1] == 3 - turn || line[1] == -1) && line[6] == 0)
                    myScore += chessType.MIAN2; //210010
                else if (line[1] == turn) {
                    if (line[0] == 3 - turn || line[0] == -1)
                        myScore += chessType.MIAN3; //211001
                    else
                        myScore += chessType.MIAN3; //011001
                }
            }
            if (line[6] == 0 && line[7] == 0 && line[8] == turn) {
                if (line[4] == 0 && line[9] == 0)
                    myScore += chessType.HUO2; //010010
                else if ((line[4] == 3 - turn || line[4] == -1) && line[9] == 0)
                    return chessType.MIAN2; //210010
                else if (line[4] == 0 && (line[9] == 3 - turn || line[9] == -1))
                    myScore += chessType.MIAN2; //010012
                else if (line[9] == turn) {
                    if (line[10] == 3 - turn || line[10] == -1)
                        myScore += chessType.MIAN3; //100112
                    else
                        myScore += chessType.MIAN3; //10011
                }
            }
            if (line[4] == 0 && line[3] == turn && line[6] == 0 && line[7] == turn)
                return chessType.MIAN3; //10101
            if (line[4] == 0 && line[3] == turn && line[2] == 0 && line[1] == turn) {
                if (line[0] == 0)
                    myScore += chessType.MIAN3; //010101
                else
                    myScore += chessType.MIAN3; //210101
            }
            if (line[6] == 0 && line[7] == turn && line[8] == 0 && line[9] == turn) {
                if (line[10] == 0)
                    myScore += chessType.MIAN3; //101010
                else
                    myScore += chessType.MIAN3; //101012
            }
            if (line[4] == 0 && line[3] == turn) {
                if (line[2] == 0 && line[6] == 0) {
                    if ((line[1] == 3 - turn || line[1] == -1) && (line[7] == 3 - turn || line[7] == -1))
                        return chessType.MIAN2; //2010102
                    else if (line[7] == 3 - turn || line[7] == -1)
                        return chessType.HUO2; //0010102
                    else
                        myScore += chessType.HUO2; //2010100|0010100
                } else if ((line[2] == 3 - turn || line[2] == -1) && line[6] == 0 && line[7] == 0)
                    myScore += chessType.MIAN2; //210100
                else if (line[2] == 0 && line[1] == 0 && line[6] != 0)
                    return chessType.MIAN2; //001012
            }
            if (line[6] == 0 && line[7] == turn) {
                if (line[8] == 0 && line[4] == 0) {
                    if ((line[3] == 3 - turn || line[3] == -1) && (line[9] == 3 - turn || line[9] == -1))
                        return chessType.MIAN2; //2010102
                    else if (line[3] == 3 - turn || line[3] == -1)
                        return chessType.HUO2; //2010100
                    else
                        myScore += chessType.HUO2; //0010102|0010100
                } else if ((line[8] == 3 - turn || line[8] == -1) && line[4] == 0 && line[3] == 0) {
                    myScore += chessType.MIAN2; //001012
                } else if (line[8] == 0 && line[9] == 0 && (line[4] == 3 - turn || line[4] == -1))
                    return chessType.MIAN2; //210100
            }
            break;
    }
    return myScore;
}

int analysisLine_opponent(const int line[], int turn) {
    int opponentScore = 0, cntLeft = 0, cntRight = 0;
    for (; line[4 - cntLeft] == 3 - turn; cntLeft++);
    for (; line[6 + cntRight] == 3 - turn; cntRight++);
    switch (cntLeft) { // NOLINT(hicpp-multiway-paths-covered)
        case 4:
            if (line[0] == 0)
                opponentScore += chessType.LIAN5 - chessType.CHONG4; //011112
            else
                opponentScore += chessType.LIAN5; //211112
            break;
        case 3:
            if (line[1] == 0) {
                if (line[0] == 0) {
                    if (line[6] == 0)
                        opponentScore += chessType.HUO4 - chessType.MIAN3; //0011120
                    else if (line[6] == turn || line[6] == -1)
                        opponentScore += chessType.CHONG4 - chessType.MIAN3; //0011122
                } else if (line[0] == turn || line[0] == -1) {
                    if (line[6] == 0)
                        opponentScore += chessType.HUO4; //2011120
                    else if (line[6] == turn || line[6] == -1)
                        opponentScore += chessType.CHONG4; //2011122
                }
            } else if (line[1] == turn || line[1] == -1) {
                if (line[6] == 0)
                    opponentScore += chessType.CHONG4; //211120
            }
            break;
        case 2:
            if (line[2] == 0) {
                if (line[1] == 0) {
                    if (line[6] == 0) {
                        if (line[0] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //0001120
                        else if (line[0] == turn || line[0] == -1)
                            opponentScore += chessType.HUO3; //2001120
                    } else if (line[6] == turn || line[6] == -1) {
                        if (line[0] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //0001122
                        else if (line[0] == turn || line[0] == -1)
                            opponentScore += chessType.MIAN3; //2001122
                    }
                } else if (line[1] == 3 - turn) {
                    if (line[0] == turn || line[0] == -1)
                        opponentScore += chessType.CHONG4; //210112
                } else if (line[1] == turn || line[1] == -1) {
                    if (line[6] == 0) {
                        if (line[7] == 0)
                            opponentScore += chessType.HUO3; //2011200
                        else if (line[7] == turn || line[7] == -1)
                            opponentScore += chessType.MIAN3; //2011202
                    }
                }
            } else if (line[2] == turn || line[2] == -1) {
                if (line[6] == 0 && line[7] == 0)
                    opponentScore += chessType.MIAN3; //211200
            }
            break;
        case 1:
            if (line[3] == 0) {
                if (line[2] == 0) {
                    if (line[1] == 3 - turn) {
                        if (line[0] == 0)
                            opponentScore += chessType.MIAN3 - chessType.MIAN2; //010012
                        else
                            opponentScore += chessType.MIAN3; //210012
                    } else if (line[1] == turn || line[1] == -1) {
                        if (line[6] == 0) {
                            if (line[7] == 0)
                                opponentScore += chessType.HUO2; //2001200
                            else if (line[7] == turn || line[7] == -1)
                                opponentScore += chessType.MIAN2; //2001202
                        }
                    } else if (line[1] == 0) {
                        if (line[6] == 0)
                            opponentScore += chessType.HUO2; //000120
                        else if (line[6] == turn || line[6] == -1)
                            opponentScore += chessType.MIAN2; //000122
                    }
                } else if (line[2] == 3 - turn) {
                    if (line[1] == 0) {
                        if (line[6] == 0) {
                            if (line[0] == 0)
                                opponentScore += chessType.HUO3 - chessType.MIAN2; //0010120
                            else
                                opponentScore += chessType.HUO3; //2010120
                        } else if (line[6] == turn || line[6] == -1) {
                            if (line[0] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //0010122
                            else
                                opponentScore += chessType.MIAN3; //2010122
                        }
                    } else if (line[1] == 3 - turn) {
                        if (line[0] == turn || line[0] == -1)
                            opponentScore += chessType.CHONG4; //211012
                    } else if (line[1] == turn || line[1] == -1) {
                        if (line[6] == 0)
                            opponentScore += chessType.MIAN3; //210120
                    }
                } else if (line[2] == turn || line[2] == -1) {
                    if (line[6] == 0 && line[7] == 0 && line[8] == 0)
                        opponentScore += chessType.HUO2; //2012000
                    else if (line[6] == 0 && line[7] == 0 && (line[8] == turn || line[8] == -1))
                        opponentScore += chessType.MIAN2; //2012002
                }
            } else if (line[3] == turn || line[3] == -1) {
                if (line[6] == 0 && line[7] == 0 && line[8] == 0)
                    opponentScore += chessType.MIAN2; //212000
            }
            break;
        case 0:
            if (line[4] == 0) {
                if (line[3] == 0) {
                    if (line[2] == 0) {
                        if (line[1] == 3 - turn)
                            opponentScore += chessType.MIAN2; //10002
                    } else if (line[2] == 3 - turn) {
                        if (line[1] == 0) {
                            if (line[6] == 0)
                                opponentScore += chessType.HUO2; //010020
                            else if (line[6] == turn || line[6] == -1)
                                opponentScore += chessType.MIAN2; //010022
                        } else if (line[1] == 3 - turn) {
                            if (line[0] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //011002
                            else
                                opponentScore += chessType.MIAN3; //211002
                        } else if ((line[1] == turn || line[1] == -1) && line[6] == 0)
                            opponentScore += chessType.MIAN2; //210020
                    }
                } else if (line[3] == 3 - turn) {
                    if (line[2] == 0) {
                        if (line[1] == 0) {
                            if (line[6] == 0)
                                opponentScore += chessType.HUO2; //001020
                            else if (line[6] == turn || line[6] == -1)
                                opponentScore += chessType.MIAN2; //001022
                        } else if (line[1] == 3 - turn) {
                            if (line[0] == turn || line[0] == -1)
                                opponentScore += chessType.MIAN3; //210102
                            else if (line[0] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //010102
                        } else if (line[1] == turn || line[1] == -1) {
                            if (line[6] == 0) {
                                if (line[7] == 0)
                                    opponentScore += chessType.HUO2; //2010200
                                else if (line[7] == turn || line[7] == -1)
                                    opponentScore += chessType.MIAN2; //2010202
                            }
                        }
                    } else if (line[2] == 3 - turn) {
                        if (line[1] == 0) {
                            if (line[0] == 0) {
                                if (line[6] == 0)
                                    opponentScore += chessType.HUO3 - chessType.MIAN2; //0011020
                                else if (line[6] == turn || line[6] == -1) {
                                    opponentScore += chessType.MIAN3 - chessType.MIAN2; //0011022
                                }
                            } else if (line[0] == turn || line[0] == -1) {
                                if (line[6] == 0)
                                    opponentScore += chessType.HUO3; //2011020
                                else if (line[6] == turn || line[6] == -1)
                                    opponentScore += chessType.MIAN3; //2011022
                            }
                        } else if (line[1] == 3 - turn) {
                            if (line[0] == turn || line[0] == -1)
                                opponentScore += chessType.CHONG4; //211102
                        } else if (line[1] == turn || line[1] == -1) {
                            if (line[6] == 0)
                                opponentScore += chessType.MIAN3; //211020
                        }
                    } else if (line[2] == turn || line[2] == -1) {
                        if (line[6] == 0 && line[7] == 0)
                            opponentScore += chessType.MIAN2; //210200
                    }
                }
            }
            break;
    }
    switch (cntRight) { // NOLINT(hicpp-multiway-paths-covered)
        case 4:
            if (line[10] == 0)
                opponentScore += chessType.LIAN5 - chessType.CHONG4; //211110
            else
                opponentScore += chessType.LIAN5; //211112
            break;
        case 3:
            if (line[9] == 0) {
                if (line[10] == 0) {
                    if (line[4] == 0)
                        opponentScore += chessType.HUO4 - chessType.MIAN3; //0211100
                    else if (line[4] == turn || line[4] == -1)
                        opponentScore += chessType.CHONG4 - chessType.MIAN3; //2211100
                } else if (line[10] == turn || line[10] == -1) {
                    if (line[4] == 0)
                        opponentScore += chessType.HUO4; //0211102
                    else if (line[4] == turn || line[4] == -1)
                        opponentScore += chessType.CHONG4; //2211102
                }
            } else if (line[9] == turn || line[9] == -1) {
                if (line[4] == 0)
                    opponentScore += chessType.CHONG4; //211120
            }
            break;
        case 2:
            if (line[8] == 0) {
                if (line[9] == 0) {
                    if (line[4] == 0) {
                        if (line[10] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //0211000
                        else if (line[10] == turn || line[10] == -1)
                            opponentScore += chessType.HUO3; //0211002
                    } else if (line[4] == turn || line[4] == -1) {
                        if (line[10] == 0)
                            opponentScore += chessType.HUO3 - chessType.MIAN2; //2211000
                        else if (line[10] == turn || line[10] == -1)
                            opponentScore += chessType.MIAN3; //2211002
                    }
                } else if (line[9] == 3 - turn) {
                    if (line[10] == turn || line[10] == -1)
                        opponentScore += chessType.CHONG4; //211012
                } else if (line[9] == turn || line[9] == -1) {
                    if (line[4] == 0) {
                        if (line[3] == 0)
                            opponentScore += chessType.HUO3; //0021102
                        else if (line[3] == turn || line[3] == -1)
                            opponentScore += chessType.MIAN3; //2021102
                    }
                }
            } else if (line[8] == turn || line[8] == -1) {
                if (line[4] == 0 && line[3] == 0)
                    opponentScore += chessType.MIAN3; //002112
            }
            break;
        case 1:
            if (line[7] == 0) {
                if (line[8] == 0) {
                    if (line[9] == 3 - turn) {
                        if (line[10] == 0)
                            opponentScore += chessType.MIAN3 - chessType.MIAN2; //210010
                        else
                            opponentScore += chessType.MIAN3; //210012
                    } else if (line[9] == turn || line[9] == -1) {
                        if (line[4] == 0) {
                            if (line[3] == 0)
                                opponentScore += chessType.HUO2; //0021002
                            else if (line[3] == turn || line[3] == -1)
                                opponentScore += chessType.MIAN2; //2021002
                        }
                    } else if (line[9] == 0) {
                        if (line[4] == 0)
                            opponentScore += chessType.HUO2; //021000
                        else if (line[4] == turn || line[4] == -1)
                            opponentScore += chessType.MIAN2; //221000
                    }
                } else if (line[8] == 3 - turn) {
                    if (line[9] == 0) {
                        if (line[4] == 0) {
                            if (line[10] == 0)
                                opponentScore += chessType.HUO3 - chessType.MIAN2; //0210100
                            else
                                opponentScore += chessType.HUO3; //0210102
                        } else if (line[4] == turn || line[4] == -1) {
                            if (line[10] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //2210100
                            else
                                opponentScore += chessType.MIAN3; //2210102
                        }
                    } else if (line[9] == 3 - turn) {
                        if (line[10] == turn || line[10] == -1)
                            opponentScore += chessType.CHONG4; //210112
                    } else if (line[9] == turn || line[9] == -1) {
                        if (line[4] == 0)
                            opponentScore += chessType.MIAN3; //021012
                    }
                } else if (line[8] == turn || line[8] == -1) {
                    if (line[4] == 0 && line[3] == 0 && line[2] == 0)
                        opponentScore += chessType.HUO2; //0002102
                    else if (line[4] == 0 && line[3] == 0 && (line[2] == turn || line[2] == -1))
                        opponentScore += chessType.MIAN2; //2002102
                }
            } else if (line[7] == turn || line[7] == -1) {
                if (line[4] == 0 && line[3] == 0 && line[2] == 0)
                    opponentScore += chessType.MIAN2; //000212
            }
            break;
        case 0:
            if (line[6] == 0) {
                if (line[7] == 0) {
                    if (line[8] == 0) {
                        if (line[9] == 3 - turn)
                            opponentScore += chessType.MIAN2; //20001
                    } else if (line[8] == 3 - turn) {
                        if (line[9] == 0) {
                            if (line[4] == 0)
                                opponentScore += chessType.HUO2; //020010
                            else if (line[4] == turn || line[4] == -1)
                                opponentScore += chessType.MIAN2; //220010
                        } else if (line[9] == 3 - turn) {
                            if (line[10] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //200110
                            else
                                opponentScore += chessType.MIAN3; //200112
                        } else if ((line[9] == turn || line[9] == -1) && line[4] == 0)
                            opponentScore += chessType.MIAN2; //020012
                    }
                } else if (line[7] == 3 - turn) {
                    if (line[8] == 0) {
                        if (line[9] == 0) {
                            if (line[4] == 0)
                                opponentScore += chessType.HUO2; //020100
                            else if (line[4] == turn || line[4] == -1)
                                opponentScore += chessType.MIAN2; //220100
                        } else if (line[9] == 3 - turn) {
                            if (line[10] == turn || line[10] == -1)
                                opponentScore += chessType.MIAN3; //201012
                            else if (line[10] == 0)
                                opponentScore += chessType.MIAN3 - chessType.MIAN2; //201010
                        } else if (line[9] == turn || line[9] == -1) {
                            if (line[4] == 0) {
                                if (line[3] == 0)
                                    opponentScore += chessType.HUO2; //0020102
                                else if (line[3] == turn || line[3] == -1)
                                    opponentScore += chessType.MIAN2; //2020102
                            }
                        }
                    } else if (line[8] == 3 - turn) {
                        if (line[9] == 0) {
                            if (line[10] == 0) {
                                if (line[4] == 0)
                                    opponentScore += chessType.HUO3 - chessType.MIAN2; //0201100
                                else if (line[4] == turn || line[4] == -1) {
                                    opponentScore += chessType.MIAN3 - chessType.MIAN2; //2201100
                                }
                            } else if (line[10] == turn || line[10] == -1) {
                                if (line[4] == 0)
                                    opponentScore += chessType.HUO3; //0201102
                                else if (line[4] == turn || line[4] == -1)
                                    opponentScore += chessType.MIAN3; //2201102
                            }
                        } else if (line[9] == 3 - turn) {
                            if (line[10] == turn || line[10] == -1)
                                opponentScore += chessType.CHONG4; //201112
                        } else if (line[9] == turn || line[9] == -1) {
                            if (line[4] == 0)
                                opponentScore += chessType.MIAN3; //020112
                        }
                    } else if (line[8] == turn || line[8] == -1) {
                        if (line[4] == 0 && line[3] == 0)
                            opponentScore += chessType.MIAN2; //002012
                    }
                }
            }
            break;
    }
    if (cntLeft == 1 && cntRight == 3) {
        if (line[9] == 0 && line[10] == 0)
            return opponentScore + chessType.LIAN5 - chessType.MIAN3; //1211100
        else
            return opponentScore + chessType.LIAN5; //12111
    }
    if (cntLeft == 3 && cntRight == 1) {
        if (line[1] == 0 && line[0] == 0)
            return opponentScore + chessType.LIAN5 - chessType.MIAN3; //0011121
        else
            return opponentScore + chessType.LIAN5; //11121
    }
    if (cntLeft == 2 && cntRight == 2) {
        if (line[2] == 0 && line[1] == 0 && line[0] == 0 && line[8] == 0 && line[9] == 0 && line[10] == 0)
            return opponentScore + chessType.LIAN5 - 2 * chessType.MIAN2; //00011211000
        else if ((line[2] == 0 && line[1] == 0 && line[0] == 0) || (line[8] == 0 && line[9] == 0 && line[10] == 0))
            return opponentScore + chessType.LIAN5 - chessType.MIAN2; //00011211|11211000
        else
            return opponentScore + chessType.LIAN5; //11211
    }
    if (cntLeft == 1 && cntRight == 2) {
        if (line[3] == 0 && line[8] == 0) {
            if (line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.HUO4 - chessType.MIAN2; //01211000
            else
                return opponentScore + chessType.HUO4; //012110
        } else if (line[8] == 0) {
            if (line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //21211000
            else
                return opponentScore + chessType.CHONG4; //212110
        } else if (line[3] == 0)
            return opponentScore + chessType.CHONG4; //012112
    }
    if (cntLeft == 2 && cntRight == 1) {
        if (line[7] == 0 && line[2] == 0) {
            if (line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.HUO4 - chessType.MIAN2; //00011210
            else
                return opponentScore + chessType.HUO4; //011210
        } else if (line[2] == 0) {
            if (line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //00011212
            else
                return opponentScore + chessType.CHONG4; //011212
        } else if (line[7] == 0)
            return opponentScore + chessType.CHONG4; //211210
    }
    if (cntLeft == 0 && cntRight == 2 && line[4] == 0) {
        if (line[3] == 3 - turn) {
            if (line[8] == 0 && line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //10211000
            else
                return opponentScore + chessType.CHONG4; //10211
        }
    }
    if (cntLeft == 2 && cntRight == 0 && line[6] == 0) {
        if (line[7] == 3 - turn) {
            if (line[2] == 0 && line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //00011201
            else
                return opponentScore + chessType.CHONG4; //11201
        }
    }
    if (cntLeft == 1 && cntRight == 1) {
        if ((line[3] == turn || line[3] == -1) && line[7] == 0 && line[8] == 0)
            return opponentScore + chessType.MIAN3; //212100
        if ((line[7] == turn || line[7] == -1) && line[3] == 0 && line[2] == 0)
            return opponentScore + chessType.MIAN3; //001212
        if (line[3] == 0 && line[2] == 3 - turn && line[7] == 0 && line[8] == 3 - turn) {
            if (line[1] == 0 && line[0] == 0 && line[9] == 0 && line[10] == 0)
                return opponentScore + 2 * chessType.CHONG4 - 2 * chessType.MIAN2; //00101210100
            else if ((line[1] == 0 && line[0] == 0) || (line[9] == 0 && line[10] == 0))
                return opponentScore + 2 * chessType.CHONG4 - chessType.MIAN2; //001012101||101210100
            else
                return opponentScore + 2 * chessType.CHONG4; //1012101
        }
        if (line[3] == 0 && line[2] == 3 - turn) {
            if (line[1] == 0 && line[0] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //0010121
            else
                return opponentScore + chessType.CHONG4; //10121
        }
        if (line[7] == 0 && line[8] == 3 - turn) {
            if (line[9] == 0 && line[10] == 0)
                return opponentScore + chessType.CHONG4 - chessType.MIAN2; //1210100
            else
                return opponentScore + chessType.CHONG4; //12101
        }
        if (line[3] == 0 && line[7] == 0) {
            if ((line[2] == turn || line[2] == -1) && (line[8] == turn || line[8] == -1))
                return opponentScore + chessType.MIAN3; //2012102
            else if (((line[2] == turn || line[2] == -1) && line[8] == 0) || ((line[8] == turn || line[8] == -1) && line[2] == 0) || (line[2] == 0 && line[8] == 0))
                return opponentScore + chessType.HUO3; //2012100|0012102|0012100
        }
    }
    if (cntLeft == 0 && cntRight == 1 && line[4] == 0) {
        if (line[3] == 0 && line[2] == 3 - turn)
            return opponentScore + chessType.MIAN3; //10021
        if (line[3] == 3 - turn) {
            if (line[2] == 0 && line[7] == 0)
                return opponentScore + chessType.HUO3; //010210
            else if (line[2] == 3 - turn)
                return opponentScore + chessType.CHONG4; //11021
            else if (((line[2] == turn || line[2] == -1) && line[7] == 0) || (line[2] == 0 && (line[7] == turn || line[7] == -1)))
                return opponentScore + chessType.MIAN3; //210210|010212
        }
    }
    if (cntLeft == 1 && cntRight == 0 && line[6] == 0) {
        if (line[7] == 0 && line[8] == 3 - turn)
            return opponentScore + chessType.MIAN3; //12001
        if (line[7] == 3 - turn) {
            if (line[8] == 0 && line[3] == 0)
                return opponentScore + chessType.HUO3; //012010
            else if (line[8] == 3 - turn)
                return opponentScore + chessType.CHONG4; //12011
            else if (((line[8] == turn || line[8] == -1) && line[3] == 0) || (line[8] == 0 && (line[3] == turn || line[3] == -1)))
                return opponentScore + chessType.MIAN3; //012012|212010
        }
    }
    if (cntLeft == 0 && cntRight == 0 && line[4] == 0 && line[6] == 0) {
        if (line[3] == 3 - turn && line[7] == 3 - turn)
            return opponentScore + chessType.MIAN3; //10201
    }
    return opponentScore;
}

#pragma clang diagnostic pop