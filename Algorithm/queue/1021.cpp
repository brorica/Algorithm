#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int second(deque<int>& a, int find)
{
	int count = 0;
	while (a.front() != find)
	{
		a.push_back(a.front());
		a.pop_front();
		count++;
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	deque<int> ans;
	int N, M, i, find;
	int result = 0, temp;
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		ans.push_back(i);
	while (M--)
	{
		cin >> find;
		if (ans.front() == find)
			ans.pop_front();
		else
		{
			temp = second(ans, find);
			result += min(temp, (int)ans.size() - temp);
			ans.pop_front();
		}
	}
	cout << result;
	return 0;
}