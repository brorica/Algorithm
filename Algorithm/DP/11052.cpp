#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j, MAX = 0, temp;
	int cache[1024] = { 0, };
	int pack[1024] = { 0, };

	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> pack[i];
	for (i = 0; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (i + j <= N)
			{
				temp = cache[i] + pack[j];
				cache[i + j] = max(temp, cache[i + j]);
			}
			else if (i + j > N)
				break;
		}
	}
	cout << cache[N];
	return 0;
}