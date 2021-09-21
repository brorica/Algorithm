#include <iostream>

using namespace std;

int arr[8] = { 0, };
int check[8] = { 0, };

//	최대 수, 한 줄에 뽑아야 하는 수, 현재 수
int func(int N, int M, int current)
{
	if (current == M)
	{
		for (auto i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
	{
		for (auto i = 0; i < N; i++)
		{
			if (!check[i])
			{
				arr[current] = i + 1;
				check[i] = 1;
				func(N, M, current + 1);
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
	int N, M;
	cin >> N >> M;
	func(N, M, 0);
	return 0;
}