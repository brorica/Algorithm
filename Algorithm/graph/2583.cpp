#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool board[101][101] = { 0, };
int M, N;
int BFS(int startY, int startX)
{
	queue<pair<int, int>> q;
	int tempY, tempX, newY, newX, count = 0;
	int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
	q.push({ startY, startX });
	while (!q.empty())
	{
		tempY = q.front().first;
		tempX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			newY = tempY + dy[i];
			newX = tempX + dx[i];
			if (0 <= newY && newY < M && 0 <= newX && newX < N)
			{
				if (board[newY][newX] == 0)
				{
					board[newY][newX] = 1;
					q.push({newY, newX});
					count++;
				}
			}
		}
	}
	if (count == 0)
		return 1;
	return count;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int K, ans = 0;
	int bottomX, bottomY, topX, topY;
	vector <int> v;
	cin >> M >> N >> K;
	for (int k = 0; k < K; k++)
	{
		cin >> bottomX >> bottomY >> topX >> topY;
		for (int i = bottomY; i < topY; i++)
			for (int j = bottomX; j < topX; j++)
				board[i][j] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0)
				v.push_back(BFS(i, j));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	return 0;
}