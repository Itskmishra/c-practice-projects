# Tic-Tac-Toe Game

This is a simple command-line implementation of the classic Tic-Tac-Toe game in C. Play against the computer and try to win!

## Features

- Player vs Computer gameplay
- 3x3 game board
- Random computer moves
- Win detection for rows, columns, and diagonals
- Option to play multiple games

## How to Play

1. Compile the program:
```
gcc main.c -o tic_tac_toe
```
2. Run the compiled program:
```
./tic_tac_toe
```
3. When prompted, enter 'y' or 'Y' to start a game.

4. On your turn:
- Enter a row number (1-3)
- Enter a column number (1-3)

5. Try to get three of your symbols ('O') in a row, column, or diagonal before the computer does.

6. After the game ends, you can choose to play again or quit.

## Game Logic

- The player uses 'O' and the computer uses 'X'.
- The computer makes random moves.
- The game checks for a winner after each move.
- If all spaces are filled and there's no winner, it's a tie.

## Functions

- `game()`: Main game loop
- `reset_board()`: Clears the game board
- `print_board()`: Displays the current game state
- `check_free_spaces()`: Counts empty spaces on the board
- `player_move()`: Handles the player's turn
- `computer_move()`: Generates the computer's move
- `check_winner()`: Determines if there's a winner
- `print_winner()`: Displays the game result

## Limitations

- The computer's moves are random, so it doesn't use any strategy.
- There's no difficulty setting.

## Future Improvements (not sure yet)

- Implement an AI for smarter computer moves
- Add difficulty levels
- Create a graphical user interface
