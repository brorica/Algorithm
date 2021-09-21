#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v(101);
int ans = 0;
bool visit[101] = { 0, };
int dfs(int start)
{
	int size = v[start].size();
	visit[start] = 1;
	for (int i = 0; i < size; i++)
	{
		if (!visit[v[start][i]])
		{
			ans++;
			dfs(v[start][i]);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, first, second, i;
	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		cin >> first >> second;
		v[first].push_back(second);
		v[second].push_back(first);
	}
	for (i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());
	dfs(1);
	cout << ans;
	return 0;
}
