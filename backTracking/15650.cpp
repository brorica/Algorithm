#include <iostream>

using namespace std;

int arr[16] = { 0, };
int check[16] = { 0, };
int N, M;

int func(int index, int current)
{
	if (current == M)
	{
		for (auto i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (auto i = index; i <= N; i++)
		{
			if (!check[i])
			{
				arr[current] = i;
				check[i] = 1;
				func(i + 1, current + 1);
				check[i] = 0;
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
	func(1, 0);
	return 0;
}