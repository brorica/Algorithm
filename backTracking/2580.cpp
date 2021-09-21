#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define square(i, j) (i / 3) * 3 + (j / 3)

int board[9][9] = { 0, };
int yBoard[9][9] = { 0, };
int xBoard[9][9] = { 0, };
int squareBoard[9][9] = { 0, };

int func(int Count)
{
	int i, j;
	int y = Count / 9, x = Count % 9;
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
	if (board[y][x] == 0)
	{
		for (i = 1; i <= 9; i++)
		{
			if (yBoard[y][i] == 0 && xBoard[x][i] == 0 && squareBoard[square(y, x)][i] == 0)
			{
				// 일단 빈 숫자가 있으면 넣어보고,
				board[y][x] = i;
				yBoard[y][i] = 1;
				xBoard[x][i] = 1;
				squareBoard[square(y, x)][i] = 1;
				func(Count + 1);
				// 아니면 다시 뺀다.
				board[y][x] = 0;
				yBoard[y][i] = 0;
				xBoard[x][i] = 0;
				squareBoard[square(y, x)][i] = 0;
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
				yBoard[i][board[i][j]] = 1;
				xBoard[j][board[i][j]] = 1;
				squareBoard[square(i, j)][board[i][j]] = 1;
			}
		}
	}
	func(0);
	return 0;
}