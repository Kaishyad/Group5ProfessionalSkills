#include <cstdio>
#include <cstdlib>
#include <iostream>

constexpr int M = 4;  // 6 rows for Connect 4
constexpr int N = 4;  // 7 columns for Connect 4

void initBoard(int board[M][N], int rows, int cols) {
  for (int m = 0; m < rows; m++) {
    for (int n = 0; n < cols; n++) {
      board[m][n] = 0;
    }
  }
}

void displayBoard(int board[M][N], int rows, int cols, bool winPositions[M][N] = nullptr) {
  std::cout << "\n   ";
  for (int n = 1; n <= cols; n++) {
    std::cout << n << " ";
  }
  std::cout << "\n";

  for (int m = 0; m < rows; m++) {
    std::cout << m + 1 << " ";
    for (int n = 0; n < cols; n++) {
      std::cout << "|";
      if (winPositions && winPositions[m][n]) {
        std::cout << "X";
      } else if (board[m][n] == 0) {
        std::cout << " ";
      } else {
        std::cout << board[m][n];
      }
    }
    std::cout << "|" << std::endl;
  }

  std::cout << "   ";
  for (int n = 0; n < cols; n++) {
    std::cout << "--";
  }
  std::cout << "-\n";
}

int parseBoard(int board[M][N], int rows, int cols, bool winPositions[M][N] = nullptr) {
  for (int m = 0; m < rows; m++) {
    for (int n = 0; n < cols; n++) {
      if (board[m][n] == 0) continue;

      const int player = board[m][n];

      //Check each direction
      for (int d = 0; d < 4; d++) {
        constexpr int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
        const int dm = directions[d][0];
        const int dn = directions[d][1];
        bool win = true;

        //Check if 4 in a row in this direction
        for (int i = 1; i < 4; i++) {
          const int newM = m + dm * i;
          const int newN = n + dn * i;

          if (newM < 0 || newM >= rows || newN < 0 || newN >= cols || board[newM][newN] != player) {
            win = false;
            break;
          }
        }

        if (win) {
          //Note winning positions if array provided
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

void gameLoop(int board[M][N], bool &cont, int players, int rows, int cols) {
  displayBoard(board, rows, cols);

  do {
    for (int p = 1; p <= players; ++p) {
      std::cout << "Player " << p << ", choose column (1-" << cols << "): ";
      int col;
      std::cin >> col;
      col -= 1;

      if (col < 0 || col >= cols) {
        std::cout << "Invalid column!" << std::endl;
        --p;
        continue;
      }

      //Find the lowest empty row
      int row = -1;
      for (int m = rows - 1; m >= 0; m--) {
        if (board[m][col] == 0) {
          row = m;
          break;
        }
      }

      if (row == -1) {
        std::cout << "Column is full!" << std::endl;
        --p;
        continue;
      }

      board[row][col] = p;
      displayBoard(board, rows, cols);
      std::cout << "Player " << p << " placed at row " << row + 1
                << ", column " << col + 1 << std::endl;

      //Check for winner and winning positions
      bool winPositions[M][N] = {false};
      int winner = parseBoard(board, rows, cols, winPositions);
      if (winner != 0) {
        displayBoard(board, rows, cols, winPositions);
        std::cout << "\n＼(^-^)／ Player " << winner << " has won! ＼(^-^)／\n" << std::endl;
        cont = false;
        break;
      }

      // Check for draw
      bool full = true;
      for (int n = 0; n < cols; n++) {
        if (board[0][n] == 0) {
          full = false;
          break;
        }
      }
      if (full) {
        std::cout << "\n⊙﹏⊙ It's a draw! ⊙﹏⊙\n" << std::endl;
        cont = false;
        break;
      }
    }
  } while (cont);
}

int main() {
  int P = 2;
  bool cont = true;

  std::cout << "=== Connect 4 ===" << std::endl;
  std::cout << "Playing on a " << M << "x" << N << " board" << std::endl;
  std::cout << "Players: " << P << std::endl;

  int board[M][N];
  initBoard(board, M, N);
  gameLoop(board, cont, P, M, N);

  return EXIT_SUCCESS;
}