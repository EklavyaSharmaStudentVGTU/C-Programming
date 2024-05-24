#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defines the maximum size of the game board
#define MAX_SIZE 10

// Defines the symbols for players
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Defines the symbols for empty and invalid positions
#define EMPTY ' '
#define INVALID -1

// Defines the directions for movement
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

// Defines the directions for movement using arrow keys
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77

// Defines a structure representing the game board
typedef struct {
    char board[MAX_SIZE][MAX_SIZE]; // 2D array to store the game board.
    int size;                       // Size of the game board.
} TicTacToe;

/**
 * Initializes the game board with empty positions
 */
void initializeBoard(TicTacToe* game) {              // game is a pointer to the TicTacToe object.
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            game->board[i][j] = EMPTY;
        }
    }
}

/**
 * Prints the game board
 */
void printBoard(const TicTacToe* game) {
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

/**
 * Checks if a position on the game board is valid
 */
bool isValidPosition(const TicTacToe* game, int row, int col) {     // row is the row index of the position and col is the column index of the position.
    return (row >= 0 && row < game->size && col >= 0 && col < game->size && game->board[row][col] == EMPTY);
}

/**
 * Checks if the game board is full
 */
bool isBoardFull(const TicTacToe* game) {
    for (int i = 0; i < game->size; i++) {
        for (int j = 0; j < game->size; j++) {
            if (game->board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Checks if a player has won the game
 */
bool hasPlayerWon(const TicTacToe* game, char player) {   // player is the symbol of the player.
    // Check rows
    for (int i = 0; i < game->size; i++) {
        bool rowWin = true;
        for (int j = 0; j < game->size; j++) {
            if (game->board[i][j] != player) {
                rowWin = false;
                break;
            }
        }
        if (rowWin) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < game->size; j++) {
        bool colWin = true;
        for (int i = 0; i < game->size; i++) {
            if (game->board[i][j] != player) {
                colWin = false;
                break;
            }
        }
        if (colWin) {
            return true;
        }
    }

    // Check diagonals
    bool diagonal1Win = true;
    bool diagonal2Win = true;
    for (int i = 0; i < game->size; i++) {
        if (game->board[i][i] != player) {
            diagonal1Win = false;
        }
        if (game->board[i][game->size - 1 - i] != player) {
            diagonal2Win = false;
        }
    }
    if (diagonal1Win || diagonal2Win) {
        return true;
    }

    return false;
}

/**
 * Makes a move on the game board
 */
void makeMove(TicTacToe* game, int row, int col, char player) {
    game->board[row][col] = player;
}

/**
 * Gets the next move from the player
 */
void getPlayerMove(TicTacToe* game, char player) {
    int row, col;
    printf("Player %c's turn\n", player);
    printf("Enter row and column (0-%d): ", game->size - 1);
    scanf("%d %d", &row, &col);

    while (!isValidPosition(game, row, col)) {
        printf("Invalid position. Enter row and column (0-%d): ", game->size - 1);
        scanf("%d %d", &row, &col);
    }

    makeMove(game, row, col, player);
}

/**
 * Gets the next move from the computer
 */
void getComputerMove(TicTacToe* game, char player) {
    int row, col;

    // Randomly generate row and column until a valid position is found.
    do {
        row = rand() % game->size;
        col = rand() % game->size;
    } while (!isValidPosition(game, row, col));

    makeMove(game, row, col, player);
}

/**
 * Starts the Tic Tac Toe game
 */
void playTicTacToe(int size, char player) {    // size is the size of the game board
    TicTacToe game;
    game.size = size;

    initializeBoard(&game);

    // Randomly determine who plays first.
    char currentPlayer = (rand() % 2 == 0) ? PLAYER_X : PLAYER_O;

    printf("Welcome to Tic Tac Toe!\n");
    printf("Rules:\n");
    printf("1. The game board is a %d x %d grid.\n", size, size);
    printf("2. Use WASD or arrow keys to move the cursor.\n");
    printf("3. Press Enter to place your symbol.\n");
    printf("4. The first player to get %d symbols in a row, column, or diagonal wins.\n", size);
    printf("5. You will play as %c.\n", player);
    printf("Let's begin!\n\n");

    printBoard(&game);

    while (true) {
        if (currentPlayer == player) {
            getPlayerMove(&game, currentPlayer);
        } else {
            getComputerMove(&game, currentPlayer);
        }

        system("clear"); // Clear the console screen.

        printBoard(&game);

        if (hasPlayerWon(&game, currentPlayer)) {
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (isBoardFull(&game)) {
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

int main() {
    int size;
    char player;

    printf("Enter the size of the game board: ");
    scanf("%d", &size);

    printf("Enter the symbol you want to play with (X or O): ");
    scanf(" %c", &player);

    playTicTacToe(size, player);

    return 0;
}