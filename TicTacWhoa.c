#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
//Function to print board
void printBoard(char board[3][3]);
//Function to check win
bool checkWin(char board[3][3], char symbol);
//Function to check draw
bool checkDraw(char board[3][3]);
//Function that checks if the input is valid
bool isValidInput(char input[]);
//Function to update board based on user input
bool updateBoard(char board[3][3], char input[], char symbol);
 
//main function
int main() 
{
	char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {' ', ' ', ' '}};
	bool gameOver = false;
	int moves = 0;
    	char player1 = 'X';
    	char player2 = 'O';
    	int i;
    	printf("Welcome to Tic-Tac-Whoa!\n");
    	printf("Enter 'quit' at any time to exit.\n");

    	while (!gameOver) 
    	{
        	printBoard(board);

        	char input[3];
        	//Teritiary statement to see which players move it is
        	int player = moves % 2 == 0 ? 1 : 2;
        	//Teritiary statement to check which symbol to use
        	char symbol = player == 1 ? player1 : player2;    

        	printf("Player %d's Move: ", player);
        	//Take user input
        	scanf("%s", input);
			printf("\n");
        	//If user input is quit, breaks out of loop
        	if (strcmp(input, "quit") == 0) 
        	{	
            		printf("Thanks for playing! Goodbye!\n");
            		break;
        	}

        	//If Invlaid input, runs the loop again without any change
        	if (!isValidInput(input))   //Calls function isValidInput to check if theinputis valid
        	{
        	    	printf("Invalid move, please specify both column and row.\n");
            		continue;
        	}

        	//If the inputted location is already taken, it runs the loop again without any change
 	       	if (!updateBoard(board, input, symbol))     //Runs function updateBoard, which updates the board and also checks if the place is occupied
	        {
		        printf("Invalid move, please try again.\n");
            		continue;
        	}

        	//Check if the game is over or not
        	gameOver = checkWin(board, symbol) || checkDraw(board);     //Runs the fucntions checkWin and checkDraw to checkthe status of the game

        	//If the game is over, print the winner, or declare a draw
        	if (gameOver) 
        	{
            		printBoard(board);
            		if (checkWin(board, symbol)) 
            		{
                		printf("Player %d wins!\n", player);
            		} 
            		else 
            		{
                		printf("It's a draw!\n");
            		}
        	}

        	//Increment moves played by 1
        	moves++;

        	if (moves == 9) 
        	{
            		gameOver = true;
        	}	
    	}

    	return 0;
}

void printBoard(char board[3][3]) 
{
    	//print the board
    	printf("\n");
    	printf("3 _%c_|_%c_|_%c_\n", board[0][0], board[0][1], board[0][2]);
    	printf("2 _%c_|_%c_|_%c_\n", board[1][0], board[1][1], board[1][2]);
    	printf("1  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    	printf("   A   B   C\n");
    	printf("\n");
}

bool checkWin(char board[3][3], char symbol) 
{
    	int i;
    	// Check rows and coloumns for a win
    	for (i = 0; i < 3; i++) 
    	{
        	if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
           		(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) 
        	{
            		return true;
        	}
    	}

    	//Check diagonals for a win
    	if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        	(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) 
    	{
        	return true;
    	}

    	//Otherwise return false
    	return false;
}

bool checkDraw(char board[3][3]) 
{
    	int i;int j;
    	// Check if the board is full
    	for (i = 0; i < 3; i++) 
    	{
        	for (j = 0; j < 3; j++) 
        	{
            		if (board[i][j] == ' ' || board[i][j] == '_') 
            		{
                		return false;
            		}
        	}
    	}
    	return true;
}

bool isValidInput(char input[]) 
{
    	//If the length of input is not equal to 2 the functino returns false
    	if (strlen(input) != 2)                        
    	{
        	return false;
    	}

    	//If the first char in the String inputted is not between 'A' and'C' or between 'a' and 'c' the functino returns false
    	if (!(input[0] >= 'A' && input[0] <= 'C') && !(input[0] >= 'a' && input[0] <= 'c')) 
    	{
        	return false;
    	}

    	//If the second char is not between '1' and '3' the function returns false
    	if (!(input[1] >= '1' && input[1] <= '3')) 
    	{
        	return false;
    	}

    	//If none of the conditions are true, we return true
    	return true;
}

bool updateBoard(char board[3][3], char input[], char symbol)
{
    	int row, col;
    	if (input[0] >= 'A' && input[0] <= 'C') 
    	{
        	col = input[0] - 'A';
    	} 
    	else 
    	{
        	col = input[0] - 'a';
    	}
    	row = '3' - input[1];

    	if (board[row][col] != '_' && board[row][col]!= ' ')
    	{
        	return false;
    	}

    	board[row][col] = symbol;
    	return true;
}
