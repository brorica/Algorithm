#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int A[128][128] = { 0, };
bool visit[128][128] = { 0, };
int N, L, R;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int BFS(int r, int c)
{
	queue<pair<int, int>> q, unionQ;
	int totalCost = A[r][c], totalCount = 1;
	int hereX, hereY, thereX, thereY, temp;
	q.push({ r, c });
	unionQ.push({ r, c });
	visit[r][c] = 1;
	while (!q.empty())
	{
		hereY = q.front().first;
		hereX = q.front().second;
		visit[hereY][hereX] = 1;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			thereX = hereX + dx[i];
			thereY = hereY + dy[i];
			if (thereX > N || thereY > N || thereX < 1 || thereY < 1 || visit[thereY][thereX])
				continue;
			temp = abs(A[thereY][thereX] - A[hereY][hereX]);
			if (temp >= L && temp <= R)
			{
				visit[thereY][thereX] = 1;
				unionQ.push({ thereY, thereX });
				q.push({ thereY, thereX });
				totalCost += A[thereY][thereX];
				totalCount++;
			}
		}
	}
	int avg = totalCost / totalCount;
 	while (!unionQ.empty())
	{
		hereY = unionQ.front().first;
		hereX = unionQ.front().second;
		A[hereY][hereX] = avg;
		unionQ.pop();
	}
	return totalCount - 1;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	cin >> N >> L >> R;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			cin >> A[r][c];
	while (1)
	{
		bool check = false;
		memset(visit, 0, sizeof(visit));
		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= N; c++)
			{
				if (visit[r][c] == 0)
				{
					if (BFS(r, c))
						check = true;
				}
			}
		}
		if (check)
			ans++;
		else
			break;

	}
	cout << ans;
	return 0;
}