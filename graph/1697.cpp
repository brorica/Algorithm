#include <iostream>
#include <queue>
using namespace std;

int bfs(int N, int K)
{
	int count = 0, here, i, qSize;
	bool visit[100001] = { 0, };
	queue<int> q;
	q.push(N);
	if (N > K)
		return N - K;
	while (!q.empty())
	{
		qSize = q.size();
		for (i = 0; i < qSize; i++)
		{
			here = q.front();
			if (here == K)
				return count;
			if (here + 1 <= 100000)
			{
				if (!visit[here + 1])
				{
					q.push(here + 1);
					visit[here + 1] = 1;
				}
			}
			if (here - 1 >= 0)
			{
				if (!visit[here - 1])
				{
					q.push(here - 1);
					visit[here - 1] = 1;
				}
			}
			if (here * 2 <= 100000)
			{
				if (!visit[here * 2])
				{
					q.push(here * 2);
					visit[here * 2] = 1;
				}
			}
			q.pop();
		}
		count++;
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	cout << bfs(N, K);

	return 0;
}