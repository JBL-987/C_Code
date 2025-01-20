#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 100  // Define MAX size for playername

void displayBoard(char board[3][3]){
    printf("\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Check for a winner
bool checkWinner(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Player move
void playerMove(char board[3][3], char player) {
    int row, col;
    printf("Enter row for your move: ");
    scanf("%d", &row);
    getchar();
    printf("Enter coloumn for your move: ");
    scanf("%d", &col);
    getchar();
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        printf("Invalid move, try again.\n");
        playerMove(board, player);  // Recursively ask for input
    }
}

// Computer move
void computerMove(char board[3][3], char computer) {
    int row, col;
    // Simple AI: Choose the first available spot
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (board[row][col] == ' ') {
                board[row][col] = computer;
                printf("Computer places %c at %d %d\n", computer, row, col);
                return;
            }
        }
    }
}

int main() {
    printf("Welcome to TicTacToe Game\n");
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char playername[MAX];
    char playerchoice;
    printf("What is your name? ");
    scanf("%[^\n]", playername);
    getchar();
    printf("Choose (X) or (O): ");
    scanf("%c", &playerchoice);
    getchar();

    if (playerchoice != 'X' && playerchoice != 'O') {
        printf("Invalid Choice\n");
        return 1;
    }
    
    char computerchoice = (playerchoice == 'X') ? 'O' : 'X';  // Computer gets the opposite choice
    
    displayBoard(board);  
    while (true) {
        playerMove(board, playerchoice);
        displayBoard(board);
        if (checkWinner(board, playerchoice)) {
            printf("%s wins!\n", playername);
            break;
        }
        if (checkDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
        computerMove(board, computerchoice);
        displayBoard(board);
        if (checkWinner(board, computerchoice)) {
            printf("Computer wins!\n");
            break;
        }
        if (checkDraw(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

