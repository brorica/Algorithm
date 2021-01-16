#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long five(int n)
{
	unsigned long long ret = 0;
	while (n >= 5)
	{
		ret += n / 5;
		n /= 5;
	}
	return ret;
}

unsigned long long two(int n)
{
	unsigned long long ret = 0;
	while (n >= 2)
	{
		ret += n / 2;
		n /= 2;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, temp;
	unsigned long long topFive = 0, topTwo = 0;
	unsigned long long bottomFive = 0, bottomTwo = 0;
	cin >> N >> M;

	temp = N - M;
	topFive = five(N);
	topTwo = two(N);
	bottomFive += five(M) + five(temp);
	bottomTwo += two(M) + two(temp);
	cout << min(topFive - bottomFive, topTwo - bottomTwo);
	return 0;
}