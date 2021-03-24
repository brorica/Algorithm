#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[128][128] = { 0, };
vector<int> v;
int x, y, d, g;
// x, yÀÇ ÁÂÇ¥¸¦ ¹Ù²ã¾ß ÇÑ´Ù.
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int countRectangle()
{
	int count = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
				count++;
		}
	}
	return count;
}

int drawing()
{
	int size = v.size();
	for (int i = size - 1; i >= 0; i--)
	{
		int newD = (v[i] + 1) % 4;
		x += dx[newD];
		y += dy[newD];
		board[x][y] = 1;
		v.push_back(newD);
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> y >> x >> d >> g;
		v.clear();
		v.push_back(d);
		board[x][y] = 1;
		x += dx[d];
		y += dy[d];
		board[x][y] = 1;
		for (int i = 0; i < g; i++)
			drawing();
	}
	cout << countRectangle() << '\n';
	return 0;
}