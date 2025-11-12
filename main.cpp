#include <cstdio>
#include <cstdlib>
#include <iostream>

constexpr int M = 6;  // 6 rows for Connect 4
constexpr int N = 7;  // 7 columns for Connect 4

void initBoard(int board[M][N], int rows, int cols) {
  for (int m = 0; m < rows; m++) {
    for (int n = 0; n < cols; n++) {
      board[m][n] = 0;
    }
  }
}

void displayBoard(int board[M][N], int rows, int cols) {
  std::cout << "\n   ";
  for (int n = 1; n <= cols; n++) {
    std::cout << n << " ";
  }
  std::cout << "\n";

  for (int m = 0; m < rows; m++) {
    std::cout << m + 1 << " ";  //row number starting at 1
    for (int n = 0; n < cols; n++) {
      std::cout << "|";
      if (board[m][n] == 0) {
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

int parseBoard(int board[M][N], int rows, int cols) {
  // Check all directions using offset arrays
  int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};  // horizontal, vertical, diagonal-right, diagonal-left

  for (int m = 0; m < rows; m++) {
    for (int n = 0; n < cols; n++) {
      if (board[m][n] == 0) continue;

      const int player = board[m][n];

      // Check each direction
      for (auto & direction : directions) {
        int dm = direction[0];
        int dn = direction[1];
        bool win = true;

        // Check if 4 in a row in this direction
        for (int i = 1; i < 4; i++) {
          int newM = m + dm * i;
          int newN = n + dn * i;

          if (newM < 0 || newM >= rows || newN < 0 || newN >= cols || board[newM][newN] != player) {
            win = false;
            break;
          }
        }

        if (win) return player;
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
        std::cout << "Invalid column, Pick another!" << std::endl;
        --p;
        continue;
      }

      // Find lowest empty row
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

      int winner = parseBoard(board, rows, cols);
      if (winner != 0) {
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