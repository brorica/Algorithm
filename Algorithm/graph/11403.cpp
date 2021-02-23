#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j, k, data;
	int array[101][101] = { 0, };
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> array[i][j];

	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (array[i][j])
					continue;
				else
				{
					if (array[i][k] && array[k][j])
						array[i][j] = 1;
				}
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (array[i][j])
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << '\n';
	}

	return 0;
}