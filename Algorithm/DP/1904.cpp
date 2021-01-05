#include <iostream>
#include <string.h>
using namespace std;

unsigned long long cache[1000001] = { 1, 1};
int tile(int T)
{
	if (T == 0 || T == 1)
		return cache[T];
	if (cache[T] == 0)
		cache[T] = (tile(T - 1) + tile(T-2)) % 15746;
	return cache[T];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	tile(T);
	cout << cache[T];
	return 0;
}