#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int isUsed[10] = { 0, };
int T;
int ans = -128;

int Permutation(int * array, int start, int end)
{
	int sum = 0;
	if (start == end)
	{
		for (auto i = 0; i < T - 1; i++)
			sum += abs(array[i] - array[i + 1]);
		if (sum > ans)
			ans = sum;
	}
	else
	{
		for (auto i = 0; i < end; i++)
		{
			swap(array[start], array[i]);
			Permutation(array,start + 1, end);
			swap(array[start], array[i]);
		}
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int array[16] = { 0, };
	cin >> T;
	for (auto i = 0; i < T; i++)
		cin >> array[i];
	Permutation(array, 0, T);
	cout << ans;
	return 0;
}