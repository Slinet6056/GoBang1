#include "analysisLine_my.h"
#include "initialize.h"

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
            else if ((line[leftRange - 1] == 0) || (line[rightRange + 1] == 0))
                return chessType.CHONG4; //011112|211110
            break;
        case 3:
            if (line[leftRange - 1] == 0 && line[rightRange + 1] == 0) {
                if ((line[leftRange - 2] == 3 - turn || line[leftRange - 2] == -1) &&
                    (line[rightRange + 2] == 3 - turn || line[rightRange + 2] == -1))
                    return chessType.MIAN3; //2011102
                else if ((line[leftRange - 2] == 0 && line[rightRange + 2] == 0) ||
                         ((line[leftRange - 2] == 3 - turn || line[leftRange - 2] == -1) && line[rightRange + 2] == 0) ||
                         ((line[rightRange + 2] == 3 - turn || line[rightRange + 2] == -1) && line[leftRange - 2] == 0))
                    return chessType.HUO3; //0011100|2011100|0011102
            }
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == 0 && (line[rightRange + 1] == 3 - turn || line[rightRange + 1] == -1))
                return chessType.MIAN3; //001112
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == 0 && (line[leftRange - 1] == 3 - turn || line[leftRange - 1] == -1))
                return chessType.MIAN3; //211100
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn)
                myScore += chessType.CHONG4; //10111
            if (line[rightRange + 2] == turn && line[rightRange + 1] == 0)
                myScore += chessType.CHONG4; //11101
            break;
        case 2:
            if ((line[leftRange - 1] == 3 - turn || line[leftRange - 1] == -1) && line[rightRange + 1] == 0 && line[rightRange + 2] == turn && line[rightRange + 3] == 0)
                return chessType.MIAN3; //211010
            if ((line[rightRange + 1] == 3 - turn || line[rightRange + 1] == -1) && line[leftRange - 1] == 0 && line[leftRange - 2] == turn && line[leftRange - 3] == 0)
                return chessType.MIAN3; //010112
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
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn && line[leftRange - 3] == turn)
                myScore += chessType.CHONG4; //11011
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == turn && line[rightRange + 3] == turn)
                myScore += chessType.CHONG4; //11011
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn && (line[leftRange - 3] == 3 - turn || line[leftRange - 3] == -1) && line[rightRange + 1] == 0)
                myScore += chessType.MIAN3; //210110
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == turn && (line[rightRange + 3] == 3 - turn || line[rightRange + 3] == -1) && line[leftRange - 1] == 0)
                myScore += chessType.MIAN3; //011012
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == turn && line[leftRange - 3] == 0 && line[rightRange + 1] == 0)
                myScore += chessType.HUO3; //010110
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == turn && line[rightRange + 3] == 0 && line[leftRange - 1] == 0)
                myScore += chessType.HUO3; //011010
            if (line[leftRange - 1] == 0 && line[leftRange - 2] == 0 && line[leftRange - 3] == turn)
                myScore += chessType.MIAN3; //10011
            if (line[rightRange + 1] == 0 && line[rightRange + 2] == 0 && line[rightRange + 3] == turn)
                myScore += chessType.MIAN3; //11001
            break;
        case 1:
            if (line[4] == 0 && line[3] == turn && line[2] == turn && line[1] == turn)
                myScore += chessType.CHONG4; //11101
            if (line[6] == 0 && line[7] == turn && line[8] == turn && line[9] == turn)
                myScore += chessType.CHONG4; //10111
            if (line[4] == 0 && line[3] == turn && line[2] == turn) {
                if ((line[1] == 3 - turn || line[1] == -1) && line[6] == 0)
                    myScore += chessType.MIAN3; //211010
                else if (line[1] == 0 && (line[6] == 3 - turn || line[6] == -1))
                    return chessType.MIAN3; //011012
                else if (line[1] == 0 && line[6] == 0)
                    myScore += chessType.HUO3; //011010
            }
            if (line[6] == 0 && line[7] == turn && line[8] == turn) {
                if (line[4] == 0 && (line[9] == 3 - turn || line[9] == -1))
                    myScore += chessType.MIAN3; //010112
                else if ((line[4] == 4 - turn || line[4] == -1) && line[9] == 0)
                    return chessType.MIAN3; //210110
                else if (line[4] == 0 && line[9] == 0)
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
                else if (line[1] == turn)
                    myScore += chessType.MIAN3; //11001
            }
            if (line[6] == 0 && line[7] == 0 && line[8] == turn) {
                if (line[4] == 0 && line[9] == 0)
                    myScore += chessType.HUO2; //010010
                else if ((line[4] == 3 - turn || line[4] == -1) && line[9] == 0)
                    return chessType.MIAN2; //210010
                else if (line[4] == 0 && (line[9] == 3 - turn || line[9] == -1))
                    myScore += chessType.MIAN2; //010012
                else if (line[9] == turn)
                    myScore += chessType.MIAN3; //10011
            }
            if (line[4] == 0 && line[3] == turn && line[6] == 0 && line[7] == turn)
                return chessType.MIAN3; //10101
            if (line[4] == 0 && line[3] == turn && line[2] == 0 && line[1] == turn)
                myScore += chessType.MIAN3; //10101
            if (line[6] == 0 && line[7] == turn && line[8] == 0 && line[9] == turn)
                myScore += chessType.MIAN3; //10101
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