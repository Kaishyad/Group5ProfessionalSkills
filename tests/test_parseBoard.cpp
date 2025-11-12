#include "acutest.h"
#include <iostream>

extern int parseBoard(int board[6][7], int rows, int cols, bool winPositions[6][7]);

void test_no_win(void) {
    int board[6][7] = {0};
    bool winPositions[6][7] = {false};
    int winner = parseBoard(board, 6, 7, winPositions);
    TEST_CHECK(winner == 0); 
}

void test_horizontal_win(void) {
    int board[6][7] = {0};
    bool winPositions[6][7] = {false};
    board[0][0] = 1;
    board[0][1] = 1;
    board[0][2] = 1;
    board[0][3] = 1;
    int winner = parseBoard(board, 6, 7, winPositions);
    TEST_CHECK(winner == 1);
}

void test_vertical_win(void) {
    int board[6][7] = {0};
    bool winPositions[6][7] = {false};
    board[0][0] = 2;
    board[1][0] = 2;
    board[2][0] = 2;
    board[3][0] = 2;
    int winner = parseBoard(board, 6, 7, winPositions);
    TEST_CHECK(winner == 2);
}

void test_diagonal_win(void) {
    int board[6][7] = {0};
    bool winPositions[6][7] = {false};
    board[0][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;
    int winner = parseBoard(board, 6, 7, winPositions);
    TEST_CHECK(winner == 1);
}

void test_draw(void) {
    int board[6][7];
    bool winPositions[6][7] = {false};

    for (int m = 0; m < 6; m++) {
        for (int n = 0; n < 7; n++) {
            board[m][n] = (m + n) % 2 + 1; 
        }
    }

    int winner = parseBoard(board, 6, 7, winPositions);
    TEST_CHECK(winner == 0); 
}

TEST_LIST = {
    { "no win", test_no_win },
    { "horizontal win", test_horizontal_win },
    { "vertical win", test_vertical_win },
    { "diagonal win", test_diagonal_win },
    { "draw (full board, no winner)", test_draw },
    { NULL, NULL }
};
