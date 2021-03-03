#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000001

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> Prime;
	int N, start = 0, end = 0, ans = 0, sum = 0;
	bool PrimeArray[MAX] = { 0, };
	cin >> N;
	for (int i = 2; i < MAX; i++)
	{
		if (PrimeArray[i])
			continue;
		for (int j = i * 2; j < MAX; j += i)
			PrimeArray[j] = true;
	}
	for (int i = 2; i < MAX; i++)
	{
		if (PrimeArray[i] == 0)
			Prime.push_back(i);
	}
	int size = Prime.size();
	Prime.push_back(0);
	while (end <= size)
	{
		if (Prime[start] > N)
			break;
		if (sum < N)
		{
			sum += Prime[end];
			end++;
		}
		else
		{
			sum -= Prime[start];
			start++;
		}
		if (sum == N)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}