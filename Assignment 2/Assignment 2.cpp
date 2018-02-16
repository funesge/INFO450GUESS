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


//Main Function
int main()
{

	// do while wraps around code in order to later ask user if they wish to run program again
	do
	{
		int board[ROWS][COLS];

		printArray(board);

		// asks user if they would like to run program again
		cout << "\nPlay again? Enter 'Y' ";
		cin >> answer;

	} while (answer == 'y' || answer == 'Y');

    return 0;
}

// Prints the board with the unknown spaces 
void printArray(int boardArray[ROWS][COLS])
{
	int r, c;

	cout << "   ";

	for (c = 0; c < COLS; c++)

		cout << c + 1 << "  ";
	cout << endl;
	cout << "   ------------------------"<< endl;


	for (r = 0; r < ROWS; r++)
	{
		cout << r + 1 << " ";
		cout << "|";
		for (c = 0; c < COLS; c++)
		{
			cout << "?" << "  ";
		}
		
		cout << endl;
		

	}
}

