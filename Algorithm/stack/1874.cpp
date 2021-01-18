#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> check;
	queue<char> ans;
	int N, i, j, a;
	int MAX = 0;
	cin >> N;
	while(N--)
	{
		cin >> a;
		if (a > MAX)
		{
			for (i = MAX + 1; i <= a; i++)
			{
				check.push(i);
				ans.push('+');
			}
		}
		else
		{
			if (a != check.top())
			{
				cout << "NO";
				return 0;
			}
		}
		ans.push('-');
		MAX = max(MAX, check.top());
		check.pop();
	}

	j = ans.size();
	for (i = 0; i < j; i++)
	{
		cout << ans.front() << '\n';
		ans.pop();
	}
	return 0;
}