#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> list;
int ans[16] = { 0, };
int isUsed[16] = { 0, };
int N, M;
int func(int count)
{
	int i, j;
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
			if (!isUsed[i])
			{
				isUsed[i] = 1;
				ans[count] = list[i];
				func(count + 1);
				isUsed[i] = 0;
			}

		}
	}
	return 0;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int number;
	cin >> N >> M;
	for (auto i = 0; i < N; i++)
	{
		cin >> number;
		list.push_back(number);
	}
	sort(list.begin(), list.end());
	func(0);
	return 0;
}