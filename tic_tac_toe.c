#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

// Global variable for the 3x3 playing board
int board[SIZE][SIZE];

// The winner symbol as int
int winner;

void initializeBoard(void)
{
        // Initializes the playing board with 0 wich represent the empty fields
        for (int i = 0; i < SIZE; i++)
        {
                for (int j = 0; j < SIZE; j++)
                {
                        board[i][j] = 0;
                }
        }
}

void printBoard(void)
{
        // Print a pretty formated 3x3 grid
        for (int i = 0; i < SIZE; i++)
        {
                for (int j = 0; j < SIZE; j++)
                {
                        if (j != 2)
                        {
                                // Convert the int grid to the regarding symbols
                                if (board[i][j] == 0)
                                {
                                        printf("   |");
                                }
                                if (board[i][j] == 1)
                                {
                                        printf(" O |");
                                }
                                if (board[i][j] == 2)
                                {
                                        printf(" X |");
                                }
                        }
                        else
                        {
                                // Convert the int grid to the regarding symbols
                                if (board[i][j] == 0)
                                {
                                        printf("    ");
                                }
                                if (board[i][j] == 1)
                                {
                                        printf(" O  ");
                                }
                                if (board[i][j] == 2)
                                {
                                        printf(" X  ");
                                }

                        }
                }
                if (i != 2)
                {
                        printf("\n---+---+---\n");
                }
        }
        printf("\n\n");
}


void player1(void)
{

        // Turn of player1 (O)
        int row = 5;
        int column = 5;

        while (row < 0 || row > SIZE)
        {
                printf("Select row: ");
                scanf("%d", &row);
        }

        while (column < 0 || column > SIZE)
        {
                printf("Select column: ");
                scanf("%d", &column);
        }
        printf("\n");

        // Check collisions
        while (board[row-1][column-1] != 0)
        {
                printf("This tile is occupied \n");
                player1();
        }
        // Update board
        board[row-1][column-1] = 1;
}


void player2(void)
{
        // Turn of player2 (X)
        int row = 5;
        int column = 5;

        while (row < 0 || row > SIZE)
        {
                printf("Select row: ");
                scanf("%d", &row);
        }

        while (column < 0 || column > SIZE){
                printf("Select column: ");
                scanf("%d", &column);
        }
        printf("\n");

        // Check collisions
        while (board[row-1][column-1] != 0)
        {
                printf("This tile is occupied \n");
                player2();
        }
        // Update board
        board[row-1][column-1] = 2;
}

void printWinner(int winner)
{
        // Convert the winner to an char version
        if (winner == 1)
        {
                printf("O wins!\n");
        }
        if (winner == 2)
        {
                printf("X wins!\n");
        }
}


bool isWinner(void)
{
        // Check rows and columns
        for (int i = 0; i < SIZE; i++) {
                if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                {
                        winner = board[i][0];
                        return true; // Row winner
                }
                if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                {
                        winner = board[0][i];
                        return true; // Column winner
                }
        }

        // Check diagonals
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
                winner = board[2][0];
                return true; // Main diagonal winner
        }
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
                winner = board[0][2];
                return true; // Anti-diagonal winner
        }
        return false; // No winner yet
}

bool isDraw(void)
{
        // Checks if there is a draw (no empty tiles)
        for (int i = 0; i < SIZE; i++)
        {
                for (int j = 0; j < SIZE; j++)
                {
                        if (board[i][j] == 0)
                        {
                                return false; // There are emty tiles left
                        }
                }
        }
        return true;
}

int main(void)
{
        printf("Tic-Tac-Toe!\n");
        initializeBoard();
        printBoard();

        // Run the main event loop
        while (!isWinner())
        {
                printf("Turn of player one (O)\n");
                player1();
                printBoard();
                if (isDraw())
                {
                        printf("It's a draw!\n");
                        break;
                }
                if (isWinner())
                {
                        printWinner(winner);
                        break;
                }

                printf("Turn of player two (X)\n");
                player2();
                printBoard();
                if (isDraw())
                {
                        printf("It's a draw!\n");
                        break;
                }
                if (isWinner())
                {
                        printWinner(winner);
                        break;
                }

        }
}

