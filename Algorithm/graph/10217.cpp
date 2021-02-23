#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


#define INF 0x7FFFFFFF

struct temp {
	int d;
	int c;
	int v;
};

struct compare {
	bool operator()(const temp& t1, const temp& t2) {
		if (t1.d == t2.d) {
			return t1.c < t2.c;
		}
		else {
			return t1.d < t2.d;
		}
	}
};

vector<temp> plane[101];
int dp[101][10001];

int search(int N, int M)
{
	priority_queue<temp, vector<temp>, compare> q;
	int size, here, hereCost, hereTime;
	int there, thereCost, thereTime;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= 10000; j++)
			dp[i][j] = INF;
	q.push({ 0, 0, 1 });
	dp[1][0] = 0;
	while (!q.empty())
	{
		here = q.top().v;
		hereCost = q.top().c;
		hereTime = q.top().d * -1;
		size = plane[here].size();
		q.pop();
		if (hereCost > M || dp[here][hereCost] < hereTime)
			continue;
		if (here == N)
			return hereTime;
		for (int i = 0; i < size; i++)
		{
			there = plane[here][i].v;
			thereCost = plane[here][i].c + hereCost;
			thereTime = plane[here][i].d + hereTime;
			if (thereCost > M)
				continue;
			if (dp[there][thereCost] > thereTime)
			{
				for (int j = thereCost + 1; j <= M; j++)
				{
					if (dp[there][j] <= thereTime)
						break;
					dp[there][j] = thereTime;
				}
				dp[there][thereCost] = thereTime;
				// thereCost에 -넣으면 메모리 터지는데 이유를 모르겠네
				q.push({ -thereTime, thereCost,  there });
			}
		}
	}
	return INF;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, ans;
	cin >> T;
	int N, M, K;
	int u, v, c, d;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++)
			plane[i].clear();
		for (int i = 0; i < K; i++)
		{
			cin >> u >> v >> c >> d;
			plane[u].push_back({ d, c, v });
		}
		ans = search(N, M);
		if (ans != INF)
			cout << ans << '\n';
		else
			cout << "Poor KCM\n";

	}
	return 0;
}