#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int M = 6;
const int N = 7;

void initBoard(int board[M][N]) {
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      board[m][n] = 0;
    }
  }
}

void displayBoard(int board[M][N]) {
  cout << "\nBoard:\n";
  for (int m = 0; m < M; m++) {
    for (int n = 0; n < N; n++) {
      cout << "|";
      if (board[m][n] == 0)
        cout << " ";
      else
        cout << board[m][n];
    }
    cout << "|" << endl;
  }
  for (int n = 0; n < N; n++) cout << "--";
  cout << "-\n";
}

int parseBoard(int board[M][N]) {
  /*
     * This function is where you should define your win conditions.
     * If player p in [1,...,P] has won, then you should return p; otherwise 0.
     * If you find yourself with a great deal of spare time you might try
     * rendering the board to the terminal here, too.
     */
  return 0;
}

void gameLoop(int board[M][N], bool cont, int players) {
  int winner = 0;
  int row, col;

  while (cont) {
    displayBoard(board);
    for (int p = 1; p <= players; p++) {
      cout << "Player " << p << " enter row and column (1-"
           << M << " " << N << "): ";
      cin >> row >> col;
      row -= 1;
      col -= 1;

      if (row < 0 || row >= M || col < 0 || col >= N) {
        cout << "Out of bounds, try again!\n";
        p--;
        continue;
      }

      if (board[row][col] != 0) {
        cout << "That spot is already taken!\n";
        p--;
        continue;
      }

      board[row][col] = p;

      winner = parseBoard(board);
      if (winner != 0) {
        displayBoard(board);
        cout << "Player " << winner << " wins!\n";
        cont = false;
        break;
      }
    }
  }
}

int main(void) {
  int P = 2;
  bool cont = true;

  cout << "Connect 4\n";

  int board[M][N];
  initBoard(board);
  gameLoop(board, cont, P);

  cout << "Game over.\n";
  return 0;
}