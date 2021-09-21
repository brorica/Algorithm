#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, top, data;
	cin >> t;
	while (t--)
	{
		stack<ll> s;
		stack<ll> ans;
		int check[100001] = { 0, };
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> data;
			s.push(data);
		}
		top = n;
		while (!s.empty())
		{
			while (1)
			{
				check[s.top()] = 1;
				ans.push(s.top());
				s.pop();
				if (ans.top() == top)
				{
					top--;
					int size = ans.size();
					for (int i = 0; i < size; i++)
					{
						cout << ans.top() << ' ';
						ans.pop();
					}
					while (check[top])
						top--;
					break;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}