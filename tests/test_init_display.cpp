#include "acutest.h"
#include <iostream>

extern void initBoard(int board[6][7], int rows, int cols);
int parseBoard(int board[6][7], int rows, int cols, bool winPositions[6][7] = nullptr) {
    for (int m = 0; m < rows; m++) {
        for (int n = 0; n < cols; n++) {
            if (board[m][n] == 0) continue;
            const int player = board[m][n];
            constexpr int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
            for (int d = 0; d < 4; d++) {
                const int dm = directions[d][0];
                const int dn = directions[d][1];
                bool win = true;
                for (int i = 1; i < 4; i++) {
                    int newM = m + dm * i;
                    int newN = n + dn * i;
                    if (newM < 0 || newM >= rows || newN < 0 || newN >= cols || board[newM][newN] != player) {
                        win = false;
                        break;
                    }
                }
                if (win) {
                    if (winPositions) {
                        for (int i = 0; i < 4; i++) {
                            winPositions[m + dm * i][n + dn * i] = true;
                        }
                    }
                    return player;
                }
            }
        }
    }
    return 0;
}


void test_initBoard(void) {
    int board[6][7];
    initBoard(board, 6, 7);

    bool allZero = true;
    for (int m = 0; m < 6; m++) {
        for (int n = 0; n < 7; n++) {
            if (board[m][n] != 0) {
                allZero = false;
                break;
            }
        }
    }
    TEST_CHECK(allZero == true);
}

void test_displayBoard(void) {
    int board[6][7];
    initBoard(board, 6, 7);

    bool winPositions[6][7] = {false};
    displayBoard(board, 6, 7, winPositions);

    TEST_CHECK(true); 
}

TEST_LIST = {
    { "initBoard initializes all cells to zero", test_initBoard },
    { "displayBoard runs without crashing", test_displayBoard },
    { NULL, NULL }
};
