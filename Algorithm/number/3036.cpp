#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, first, i, circle, temp;
	cin >> n >> first;
	for (i = 1; i < n; i++)
	{
		cin >> circle;
		temp = gcd(circle, first % circle);
		cout << first / temp << '/' <<  circle / temp << '\n';
	}
	return 0;
}