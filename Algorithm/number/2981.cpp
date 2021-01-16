#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector <int> ans;
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
	int n, i, data, maxGCD;
	vector <int> v;
	vector <int> ans;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());

	maxGCD = v[1] - v[0];
	for (i = 2; i < n; i++)
		maxGCD = gcd(maxGCD, v[i] - v[i - 1]);

	for (i = 2; i <= sqrt(maxGCD); i++)
	{
		if (maxGCD % i == 0)
		{
			ans.push_back(i);
			ans.push_back(maxGCD / i);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << maxGCD;
	return 0;
}