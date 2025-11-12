# Group5ProfessionalSkills
MISCADA Collaborative Software Development









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
