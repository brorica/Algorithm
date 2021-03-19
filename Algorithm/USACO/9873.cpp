#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, count = 0;
	int order[1024];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> order[i];
	}
	order[N] = 1000000000;
	sort(order, order + N);
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int range = order[j] - order[i];
			int rangedouble = range * 2;
			count += (lower_bound(order, order + N, order[j] + rangedouble + 1)
				- lower_bound(order, order + N, order[j] + range));
		}
	}
	cout << count;
	return 0;
}