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
	int xCoordinate, yCoordinate;


	// do while used to later ask user if they wish to run program again
	do
	{
		int i;
		int board[ROWS][COLS];

		printArray(board);
		displayInstructions();

		// asks user for inout and checks to see if valid
		for (i = 0; i < 5; i++)
		{
			cout << "Enter X coordinate: ";
			cin >> xCoordinate;
			do
			{
				if (xCoordinate < 1 || xCoordinate>8)
				{
					cout << "Please enter a value between 1-8"<<endl;
					cout << "Enter X coordinate: ";
					cin >> xCoordinate;
					cout << endl;
				}
			} while (xCoordinate < 1 || xCoordinate>8);
			cout << "Enter Y coordinate: ";
			cin >> yCoordinate;
			do
			{
				if (yCoordinate < 1 || yCoordinate>8)
				{
					cout << "Please enter a value between 1-8"<<endl;
					cout << "Enter y coordinate: ";
					cin >> yCoordinate;
					cout << endl;
				}
			} while (yCoordinate < 1 || yCoordinate>8);
			cout << endl;
		}
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

