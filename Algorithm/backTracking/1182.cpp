#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> element;
int ans = 0;
int N, S;

int func(int index)
{
	int i, j, sum = 0;
	if (index == N)
		return 0;
	else
	{
		for (i = index; i < N; i++)
		{
			sum += element[i];
			if (sum == S)
				ans++;
		}
		func(index + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int number;
	cin >> N >> S;
	for (auto i = 0; i < N; i++)
	{
		cin >> number;
		element.push_back(number);
	}
	//sort(element.begin(), element.end());
	func(0);
	cout << ans;
	return 0;
}