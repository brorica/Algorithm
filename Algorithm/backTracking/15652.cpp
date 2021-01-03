#include <iostream>

using namespace std;

int arr[8] = { 0, };
int check[8] = { 0, };
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
		for (auto i = index; i < N; i++)
		{
			arr[current] = i + 1;
			func(i, current + 1);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	func(0, 0);
	return 0;
}