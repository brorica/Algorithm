#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int data, x;
	int start = 0, end, sum = 0, ans = 0;
	vector<int> v;
	cin >> end;
	for (int i = 0; i < end; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	cin >> x;
	end -= 1;
	sort(v.begin(), v.end());
	while (start<end)
	{
		sum = v[start] + v[end];
		if (sum == x)
		{
			start++;
			end--;
			ans++;
		}
		else if (sum > x)
			end--;
		else
			start++;
	}
	cout << ans;
	return 0;
}