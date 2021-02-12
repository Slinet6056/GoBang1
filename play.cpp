#include "play.h"
#include "analysisLine_my.h"
#include "analysisLine_opponent.h"

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
            setlinecolor(BLACK);
            if (pos.x > 1 && pos.x < N && pos.y > 1 && pos.y < N) {
                setlinestyle(PS_SOLID, 1);
                line(50 * pos.y - 50, 50 * pos.x - 25, 50 * pos.y, 50 * pos.x - 25);
                line(50 * pos.y - 25, 50 * pos.x - 50, 50 * pos.y - 25, 50 * pos.x);
            } else if (pos.x == 1 && pos.y == 1) {
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 25, 50 * pos.x - 25, 50 * pos.y, 50 * pos.x - 25);
                line(50 * pos.y - 25, 50 * pos.x - 25, 50 * pos.y - 25, 50 * pos.x);
            } else if (pos.x == 1 && pos.y == N) {
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 50, 50 * pos.x - 25, 50 * pos.y - 25, 50 * pos.x - 25);
                line(50 * pos.y - 25, 50 * pos.x - 25, 50 * pos.y - 25, 50 * pos.x);
            } else if (pos.x == N && pos.y == 1) {
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 25, 50 * pos.x - 25, 50 * pos.y, 50 * pos.x - 25);
                line(50 * pos.y - 25, 50 * pos.x - 50, 50 * pos.y - 25, 50 * pos.x - 25);
            } else if (pos.x == N && pos.y == N) {
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 50, 50 * pos.x - 25, 50 * pos.y - 25, 50 * pos.x - 25);
                line(50 * pos.y - 25, 50 * pos.x - 50, 50 * pos.y - 25, 50 * pos.x - 25);
            } else if (pos.x == 1) {
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 50, 50 * pos.x - 25, 50 * pos.y, 50 * pos.x - 25);
                setlinestyle(PS_SOLID, 1);
                line(50 * pos.y - 25, 50 * pos.x - 25, 50 * pos.y - 25, 50 * pos.x);
            } else if (pos.x == N) {
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 50, 50 * pos.x - 25, 50 * pos.y, 50 * pos.x - 25);
                setlinestyle(PS_SOLID, 1);
                line(50 * pos.y - 25, 50 * pos.x - 50, 50 * pos.y - 25, 50 * pos.x - 25);
            } else if (pos.y == 1) {
                setlinestyle(PS_SOLID, 1);
                line(50 * pos.y - 25, 50 * pos.x - 25, 50 * pos.y, 50 * pos.x - 25);
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 25, 50 * pos.x - 50, 50 * pos.y - 25, 50 * pos.x);
            } else if (pos.y == N) {
                setlinestyle(PS_SOLID, 1);
                line(50 * pos.y - 50, 50 * pos.x - 25, 50 * pos.y - 25, 50 * pos.x - 25);
                setlinestyle(PS_SOLID, 3);
                line(50 * pos.y - 25, 50 * pos.x - 50, 50 * pos.y - 25, 50 * pos.x);
            }
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
                    if (firstPlayer == 1 && secondPlayer == 1) {
                        undo(1);
                        turn = 3 - turn;
                    } else
                        undo(2);
                } else if (m.x > 760 && m.x < 930 && m.y > 420 && m.y < 480) { //重新开始
                    return 1;
                } else if (m.x > 760 && m.x < 930 && m.y > 560 && m.y < 620) { //提示
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