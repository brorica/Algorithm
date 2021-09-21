#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int cache[32][15001] = { 0, };
int N, M;
vector<int> weights, marble;

int dp(int index, int weight)
{
	int& ret = cache[index][weight];
	if (ret)
		return 0;
	else
		ret = 1;
	if (index == N)
		return 0;
	dp(index + 1, weight + weights[index]);
	dp(index + 1, weight);
	dp(index + 1, abs(weight - weights[index]));
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, data;
	// Ãß
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		weights.push_back(data);
	}
	// ±¸½½
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> data;
		marble.push_back(data);
	}
	dp(0, 0);
	for (i = 0; i < M; i++)
	{
		if (cache[N][marble[i]])
			cout << "Y ";
		else
			cout << "N ";
	}
	return 0;
}