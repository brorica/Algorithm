#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define square(i, j) (i / 3) * 3 + (j / 3)

int board[9][9] = { 0, };
int rowBoard[9][9] = { 0, };
int columnBoard[9][9] = { 0, };
int squareBoard[9][9] = { 0, };

int func(int Count)
{
	int i, j;
	int row = Count / 9, column = Count % 9;
	if (Count == 81)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}
	if (board[row][column] == 0)
	{
		for (i = 1; i <= 9; i++)
		{
			if (rowBoard[row][i] == 0 && columnBoard[column][i] == 0 && squareBoard[square(row, column)][i] == 0)
			{
				board[row][column] = i;
				rowBoard[row][i] = 1;
				columnBoard[column][i] = 1;
				squareBoard[square(row, column)][i] = 1;
				func(Count + 1);
				board[row][column] = 0;
				rowBoard[row][i] = 0;
				columnBoard[column][i] = 0;
				squareBoard[square(row, column)][i] = 0;
			}
		}
	}
	else
		func(Count + 1);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0)
			{
				rowBoard[i][board[i][j]] = 1;
				columnBoard[j][board[i][j]] = 1;
				squareBoard[square(i, j)][board[i][j]] = 1;
			}
		}
	}
	func(0);
	return 0;
}