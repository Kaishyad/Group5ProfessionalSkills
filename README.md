
# Connect 4

A classic two-player strategy game implemented in C++


## Collaborators
- [Kaishya Desai](https://github.com/Kaishyad)
- [Reeshel Dsouza](https://github.com/rnvd02)
- [Marisa Allen](https://github.com/Marisa-Allen)
- [Feiyang Mu](https://github.com/mufeiy)


## Game Description
Connect 4 is a two-player connection strategy game where players take turns dropping colored discs into a vertical grid. The game features:

- 6 rows × 7 columns playing grid
- 2 players competing in turns
- Gravity-based piece placement (pieces fall to the bottom)
- Win detection across horizontal, vertical, and diagonal lines
- Draw detection when the board is completely filled

The game runs in the terminal/console with a simple text-based interface that displays the board after each move.

## Win Conditions
A player wins the game by connecting four of their pieces in a row. Winning combinations include:

-  **Horizontal**
    - Four consecutive pieces in the same row

-  **Vertical**
    - Four consecutive pieces in the same column

-  **Diagonal (Down-Right)**
    - Four consecutive pieces diagonally from top-left to bottom-right

- **Diagonal (Down-Left)**
    - Four consecutive pieces diagonally from top-right to bottom-left

## Building and Running Game
This game uses a Makefile to compile and run, with GNU make. This project
also uses g++ to compile the code.<br>
To build and run the game with the Makefile: (The command builds both the game and the tests)
```bash
make all
./game

```
To clean files:
```bash
make clean
```

## Tests
This project includes unit tests written with Acutest to verify core game logic.

### Test Files
- **tests/test_parseBoard.cpp**
  - Checks win condition logic:
    - No win
    - Horizontal win
    - Vertical win
    - Diagonal win
    - Draw (full board, no winner)

- **tests/test_init_display.cpp**
  - Checks helper functions:
    - `initBoard` initializes all cells to zero
    - `displayBoard` runs without crashing

### Running Tests
After building with the provided Makefile:
```bash

./test_parseBoard

./test_init_display
```
