#include "acutest.h"
#include <iostream>

extern void initBoard(int board[6][7], int rows, int cols);
extern void displayBoard(int board[6][7], int rows, int cols, bool winPositions[6][7]);

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
