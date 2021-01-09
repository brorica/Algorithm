#include <iostream>
#include <algorithm>
using namespace std;

int N, MIN = 0x7FFFFFFF;
int check[11] = { 0, };
int town[11][11] = { 0, };

int visit(int count, int start, int current, int sum)
{
	if (sum > MIN)
		return 0;
	if (count == N && start == current) 
	{
		MIN = min(sum, MIN);
		return 0;
	}
	for (auto i = 0; i < N; i++)
	{
		if (check[i] == 1 || current == i || town[current][i] == 0)
			continue;
		else
		{
			check[i] = 1;
			visit(count + 1, start, i, sum + town[current][i]);
			check[i] = 0;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> town[i][j];
	for (i = 0; i < N; i++)
		visit(0, i, i, 0);
	cout << MIN;
	return 0;
}