#include "acutest.h"
#include <iostream>

#define M 6
#define N 7

int parseBoard(int board[M][N], int rows, int cols, bool winPositions[M][N] = nullptr) {
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
                    const int newM = m + dm * i;
                    const int newN = n + dn * i;
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

void test_no_win(void) {
    int board[M][N] = {0};
    bool winPositions[M][N] = {false};
    int winner = parseBoard(board, M, N, winPositions);
    TEST_CHECK(winner == 0); 
}

void test_horizontal_win(void) {
    int board[M][N] = {0};
    bool winPositions[M][N] = {false};
    board[0][0] = 1;
    board[0][1] = 1;
    board[0][2] = 1;
    board[0][3] = 1;
    int winner = parseBoard(board, M, N, winPositions);
    TEST_CHECK(winner == 1);
}

void test_vertical_win(void) {
    int board[M][N] = {0};
    bool winPositions[M][N] = {false};
    board[0][0] = 2;
    board[1][0] = 2;
    board[2][0] = 2;
    board[3][0] = 2;
    int winner = parseBoard(board, M, N, winPositions);
    TEST_CHECK(winner == 2);
}

void test_diagonal_win(void) {
    int board[M][N] = {0};
    bool winPositions[M][N] = {false};
    board[0][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;
    int winner = parseBoard(board, M, N, winPositions);
    TEST_CHECK(winner == 1);
}

void test_draw(void) {
    int board[M][N];
    bool winPositions[M][N] = {false};

    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            board[m][n] = (m + n) % 2 + 1; 
        }
    }

    int winner = parseBoard(board, M, N, winPositions);
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
