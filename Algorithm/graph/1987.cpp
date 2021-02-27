#include <iostream>
#include <algorithm>
using namespace std;

int r, c, ans = 1;
int board[21][21];
bool alphabet[26] = { 0, };

int DFS(int y, int x, int count)
{
	int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
	int newX, newY, newIndex;
	ans = max(count, ans);
	alphabet[board[y][x]] = 1;
	for (int i = 0; i < 4; i++)
	{
		newX = x + dx[i];
		newY = y + dy[i];
		newIndex = board[newY][newX];
		if (0 <= newX && newX < c && 0 <= newY && newY < r)
		{
			if (alphabet[newIndex] == 0)
			{
				alphabet[newIndex] = 1;
				DFS(newY, newX, count + 1);
				alphabet[newIndex] = 0;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char ch;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> ch;
			board[i][j] = ch - 'A';
		}
	}
	DFS(0, 0, 1);
	cout << ans;
	return 0;
}