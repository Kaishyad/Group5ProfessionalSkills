#include <cstdio>
#include <cstdlib>
#include <iostream>

const int M = 6;  // 6 rows for Connect 4
const int N = 7;  // 7 columns for Connect 4

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
  //Check horizontal wins
  for (int m = 0; m < rows; m++) {
    for (int n = 0; n <= cols - 4; n++) {
      if (board[m][n] != 0 &&
          board[m][n] == board[m][n+1] &&
          board[m][n] == board[m][n+2] &&
          board[m][n] == board[m][n+3]) {
        return board[m][n];
      }
    }
  }

  //Check vertical wins
  for (int m = 0; m <= rows - 4; m++) {
    for (int n = 0; n < cols; n++) {
      if (board[m][n] != 0 &&
          board[m][n] == board[m+1][n] &&
          board[m][n] == board[m+2][n] &&
          board[m][n] == board[m+3][n]) {
        return board[m][n];
      }
    }
  }

  //Check diagonal wins (down-right)
  for (int m = 0; m <= rows - 4; m++) {
    for (int n = 0; n <= cols - 4; n++) {
      if (board[m][n] != 0 &&
          board[m][n] == board[m+1][n+1] &&
          board[m][n] == board[m+2][n+2] &&
          board[m][n] == board[m+3][n+3]) {
        return board[m][n];
      }
    }
  }

  //Check diagonal wins (down-left)
  for (int m = 0; m <= rows - 4; m++) {
    for (int n = 3; n < cols; n++) {
      if (board[m][n] != 0 &&
          board[m][n] == board[m+1][n-1] &&
          board[m][n] == board[m+2][n-2] &&
          board[m][n] == board[m+3][n-3]) {
        return board[m][n];
      }
    }
  }

  return 0;
}

void gameLoop(int board[M][N], bool &cont, int players, int rows, int cols) {
  int winner;
  int col;

  do {
    displayBoard(board, rows, cols);

    for (int p = 1; p <= players; ++p) {
      std::cout << "Player " << p << ", choose column (1-" << cols << "): ";
      std::cin >> col;
      //Adjust indexing
      col -= 1;

      //Check column bounds
      if (col < 0 || col >= cols) {
        std::cout << "Invalid column!" << std::endl;
        --p;
        continue;
      }

      //Find the lowest empty row in this column (gravity)
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

      winner = parseBoard(board, rows, cols);
      if (winner != 0) {
        displayBoard(board, rows, cols);
        std::cout << "\n＼(^-^)／ Player " << winner << " has won! ＼(^-^)／\n" << std::endl;

        cont = false;
        break;
      }

      //board full draw
      bool full = true;
      for (int n = 0; n < cols; n++) {
        if (board[0][n] == 0) {
          full = false;
          break;
        }
      }
      if (full) {
        displayBoard(board, rows, cols);
        std::cout << "\n⊙﹏⊙ It's a draw! ⊙﹏⊙\n" << std::endl;
        cont = false;
        break;
      }
    }
  } while (cont);
}

int main() {
  int P = 2;  //Connect 4 is always 2 players
  bool cont = true;

  std::cout << "=== Connect 4 ===" << std::endl;
  std::cout << "Playing on a " << M << "x" << N << " board" << std::endl;
  std::cout << "Players: " << P << std::endl;

  int board[M][N];
  initBoard(board, M, N);
  gameLoop(board, cont, P, M, N);

  return EXIT_SUCCESS;
}