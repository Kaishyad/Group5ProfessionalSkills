# Connect 4
<div align="center">

*A classic two-player strategy game implemented in C++*

</div>

## Collaborators

- **Kaishya Desai**
- **Reeshel Dsouza**
- **Marisa Allen**
- **Feiyang Mu**

## Game Description
Connect 4 is a two-player connection strategy game where players take turns dropping colored discs into a vertical grid. The game features:

- **6 rows × 7 columns** playing grid
- **2 players** competing in turns
- **Gravity-based** piece placement (pieces fall to the bottom)
- **Win detection** across horizontal, vertical, and diagonal lines
- **Draw detection** when the board is completely filled

The game runs in the terminal/console with a simple text-based interface that displays the board after each move.

## Win Conditions

A player wins the game by connecting **four of their pieces** in a row. Winning combinations include:

### Horizontal
Four consecutive pieces in the same row
### Vertical
Four consecutive pieces in the same column
### Diagonal (Down-Right)
Four consecutive pieces diagonally from top-left to bottom-right
### Diagonal (Down-Left)
Four consecutive pieces diagonally from top-right to bottom-left

## Building and Running Game
