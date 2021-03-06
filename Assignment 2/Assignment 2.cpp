// Assignment 2 Find the gold game application


#include "stdafx.h"
#include <iostream>
#include <time.h>

// Declare namespace and class
using namespace std;
class FindGoldGame;

//Declaring Const for rows and columns used by boards
const int ROWS = 8;
const int COLS = 8;
const int GUESSES = 5;
const int GOLD = 5;
const int BOMBS = 1;


//declares functions
void initializeArray(char board[ROWS][COLS]);
void presentArray(char boardArray[ROWS][COLS]);
void hideGoldBombs(char board[ROWS][COLS]);
void displayInstructions();



//Main Function
int main()
{
	char answer;
	// do while used to later ask user if they wish to run program again
	do
	{
		int xCoordinate, yCoordinate;
		int guessesRemaining = GUESSES;
		int score = 0;
		char board[ROWS][COLS];

		initializeArray(board);
		presentArray(board);
		hideGoldBombs(board);
		displayInstructions();

		// asks user for input and checks to see if valid
		while (guessesRemaining > 0)
		{
			cout << endl;
			cout << "Enter a x-coordinate between: ";
			cin >> xCoordinate;
			//checks for correct input
			do
			{
				if (xCoordinate < 1 || xCoordinate>8)
				{
					cout << "Please enter a value between 1-8" << endl;
					cout << "Enter X coordinate: ";
					cin >> xCoordinate;
					cout << endl;
				}
			} while (xCoordinate < 1 || xCoordinate>8);
			cout << endl;
			cout << "Enter a y-coordinate between: ";
			cin >> yCoordinate;
			// checks input
			do
			{
				if (yCoordinate < 1 || yCoordinate>8)
				{
					cout << "Please enter a value between 1-8" << endl;
					cout << "Enter y coordinate: ";
					cin >> yCoordinate;
					cout << endl;
				}
			} while (yCoordinate < 1 || yCoordinate>8);

			// checks input against board to see if gold or bomb found
			// coordinates decremented so user can enter 1 instead of 0
			if (board[xCoordinate -1][yCoordinate-1] == 'G')
			{
				cout << endl;
				cout << "You found GOLD! You earned one extra guess. ";
				// coordinates decremented so user can enter 1 instead of 0
				board[xCoordinate-1][yCoordinate-1] = 'F';
				score = score + 1;
				guessesRemaining--;
				guessesRemaining++; // adds an extra guess when gold found
				cout << "You have " << guessesRemaining << " guesses to go." << endl;
				cout << endl;
				continue;
			}
			// coordinates decremented so user can enter 1 instead of 0
			else if (board[xCoordinate-1][yCoordinate-1] == 'B')
			{
				cout << endl;
				guessesRemaining = 0;
				cout << "Bomb! GAME OVER" << endl;
				break;

			}
			else
				cout << endl;
			guessesRemaining--;
			cout << "Too bad...";
			cout << "You have " << guessesRemaining << " guesses to go" << endl;
			cout << endl;

		}
		//displays score and board with contents
		cout << "You earned " << score << " points!" << endl;
		cout << "Better Luck Next Time" << endl;
		cout << "Here's your board: " << endl;
		cout << endl;

		cout << endl;
		cout << "    ";
		for (xCoordinate = 0; xCoordinate < COLS; xCoordinate++)
			cout << "  " << xCoordinate + 1;
		cout << endl;
		cout << "   ------------------------------" << endl;

		for (yCoordinate = 0; yCoordinate < ROWS; yCoordinate++)
		{
			cout << " " << yCoordinate + 1 << " |";
			for (xCoordinate = 0; xCoordinate < COLS; xCoordinate++)
			{
				cout << "  " << board[xCoordinate][yCoordinate];
			}
			cout << endl;
		}
		cout << " " << "--------------------------------" << endl;

		// asks user if they would like to run program again
		cout << "\nPlay again? Enter 'Y' ";
		cin >> answer;

	} while (answer == 'y' || answer == 'Y');

	return 0;
}

//function initializes board
void initializeArray(char board[ROWS][COLS])
{
	int rows, cols;

	for (rows = 0; rows < ROWS; rows++)
	{

		for (cols = 0; cols < COLS; cols++)
		{
			board[rows][cols] = ' ';
		}
	}
}

// Function used to Present mystery board to user
void presentArray(char boardArray[ROWS][COLS])
{
	int rows, cols;

	cout << "   ";

	for (cols = 0; cols < COLS; cols++)

		cout << cols + 1 << "  ";
	cout << endl;
	cout << "   ------------------------" << endl;


	for (rows = 0; rows < ROWS; rows++)
	{
		cout << rows + 1 << " ";
		cout << "|";
		for (cols = 0; cols < COLS; cols++)
		{
			cout << "?" << "  ";
		}

		cout << endl;

	}
	cout << "   ------------------------" << endl;
}

//function used to hide gold and bombs
void hideGoldBombs(char board[ROWS][COLS])
{
	int gold = 0;
	int x, y;
	int bombs = 0;
	srand(time(NULL));

	for (gold = 0; gold < GOLD; gold++)
	{
		x = rand() % ROWS;
		y = rand() % COLS;
		board[x][y] = 'G';
	}

	for (bombs = 0; bombs < BOMBS; bombs++)
	{
		x = rand() % ROWS;
		y = rand() % COLS;
		board[x][y] = 'B';
	}

}
// Function used to display instructions to user
void displayInstructions()
{
	cout << " ** ********************* **" << endl;
	cout << " **       Find Gold!      **" << endl;
	cout << " **  You have 5 guesses,  **" << endl;
	cout << " **   5 pieces of gold    **" << endl;
	cout << " **       and 1 bomb      **" << endl;
	cout << " **       Good Luck       **" << endl;
	cout << " ** ********************* **" << endl;

}

