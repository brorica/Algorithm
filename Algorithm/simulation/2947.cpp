#include <iostream>
#include <algorithm>
using namespace std;

int stick[5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	for (int i = 0; i < 5; i++)
		cin >> stick[i];
	for (int i = 0; i < 5; i++)
	{
		a = 0;
		b = 1;
		for (int j = 0; j < 5 - i - 1; j++,a++,b++)
		{
			if (stick[a] > stick[b])
			{
				swap(stick[a], stick[b]);
				for (int k = 0; k < 5; k++)
					cout << stick[k] << ' ';
				cout << '\n';
			}
		}
	}
	return 0;
}