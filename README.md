# Group5ProfessionalSkills
MISCADA Collaborative Software Development

## Building and Running Game
This game uses a Makefile to compile and run. GNU Make is used for this
project. This project uses g++ to complile.<br>
To build the program, type *make game* into the terminal.<br>
To run the game type *./game* into the terminal.<br>
To clean up files type *make clean* into terminal.


## Tests

This project includes unit tests written with **Acutest** to verify core game logic.

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
make test_parseBoard
./test_parseBoard

make test_init_display
./test_init_display
