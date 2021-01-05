#include <iostream>
#include <string.h>
using namespace std;

int cache[101][101][101] = { 0 , };

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (cache[a + 50][b + 50][c + 50] != 0)
		return cache[a + 50][b + 50][c + 50];
	if (a < b && b < c)
	{
		if (cache[a + 50][b + 50][c + 50] == 0)
			cache[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return cache[a + 50][b + 50][c + 50];
	}
	if (cache[a + 50][b + 50][c + 50] == 0)
		cache[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return cache[a + 50][b + 50][c + 50];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}

	return 0;
}