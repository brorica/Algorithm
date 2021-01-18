#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i, data;
	string ip;
	stack <int> ans;
	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> ip;
		if (ip == "top")
		{
			if (ans.empty())
				cout << "-1\n";
			else
				cout << ans.top() << '\n';
		}
		else if (ip == "size")
			cout << ans.size() << '\n';
		else if (ip == "empty")
			cout << ans.empty() << '\n';
		else if (ip == "push")
		{
			cin >> data;
			ans.push(data);
		}
		else if (ip == "pop")
		{
			if (ans.empty())
				cout << "-1\n";
			else
			{
				cout << ans.top() << '\n';
				ans.pop();
			}
		}
	}
	return 0;
}