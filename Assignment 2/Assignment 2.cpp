// Assignment 2 Find the gold game application
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

// Declare namespace and class
using namespace std;
class FindGoldGame;

//Declaring Const for rows and columns used by board
const int ROWS = 8;
const int COLS = 8;

// declared variables used by application
char answer;

void printArray(int boardArray[ROWS][COLS]);
void displayInstructions();



//Main Function
int main()
{

	// do while used to later ask user if they wish to run program again
	do
	{
		int board[ROWS][COLS];

		printArray(board);
		displayInstructions();

		// asks user if they would like to run program again
		cout << "\nPlay again? Enter 'Y' ";
		cin >> answer;

	} while (answer == 'y' || answer == 'Y');

    return 0;
}

// Function used to Present board to user
void printArray(int boardArray[ROWS][COLS])
{
	int rows, cols;

	cout << "   ";

	for (cols = 0; cols < COLS; cols++)

		cout << cols + 1 << "  ";
	cout << endl;
	cout << "   ------------------------"<< endl;


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

