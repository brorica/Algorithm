#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, data;
	string oper;
	queue<int> ans;
	cin >> T;
	while (T--)
	{
		cin >> oper;
		if (oper == "push")
		{
			cin >> data;
			ans.push(data);
			continue;
		}
		else if (oper == "front")
		{
			if (ans.empty())
				cout << "-1";
			else
				cout << ans.front();
		}
		else if (oper == "back")
		{
			if (ans.empty())
				cout << "-1";
			else
				cout << ans.back();
		}
		else if (oper == "size")
			cout << ans.size();
		else if (oper == "empty")
			cout << ans.empty();
		else if (oper == "pop")
		{
			if (ans.empty())
				cout << "-1";
			else
			{
				cout << ans.front();
				ans.pop();
			}
		}
		cout << '\n';
	}
	return 0;
}