#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, i, data, min = 0x7FFFFFFF;
	long long sum = 0;
	vector <long long> interval;
	vector <long long> price;
	cin >> n;
	for (i = 0; i < n - 1; i++)
	{
		cin >> data;
		interval.push_back(data);
	}
	for (i = 0; i < n; i++)
	{
		cin >> data;
		price.push_back(data);
	}
	for (i = 0; i < n - 1; i++)
	{
		if (min > price[i])
			min = price[i];
		sum += min * interval[i];
	}
	cout << sum;
	return 0;
}