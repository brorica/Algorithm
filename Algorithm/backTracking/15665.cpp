#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int list[16];
int ans[16] = { 0, };
int isUsed[10] = { 0, };
int func(int index, int count)
{
	int i, before = 0;
	if (count == M)
	{
		for (i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			if (i == 0 || before != list[i])
			{
				ans[count] = list[i];
				before = list[i];
				func(i, count + 1);
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (auto i = 0; i < N; i++)
		cin >> list[i];
	sort(list, list + N);
	func(0, 0);
	return 0;
}