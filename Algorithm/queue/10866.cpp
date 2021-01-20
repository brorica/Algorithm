#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, data;
	deque<int> ans;
	string oper;
	cin >> T;
	while (T--)
	{
		cin >> oper;
		if (oper == "push_back")
		{
			cin >> data;
			ans.push_back(data);
		}
		else if (oper == "push_front")
		{
			cin >> data;
			ans.push_front(data);
		}
		else if (oper == "pop_front")
		{
			if (ans.empty())
				cout << -1 << '\n';
			else
			{
				cout << ans.front() << '\n';
				ans.pop_front();
			}
		}
		else if (oper == "pop_back")
		{
			if (ans.empty())
				cout << -1 << '\n';
			else
			{
				cout << ans.back() << '\n';
				ans.pop_back();
			}
		}
		else if (oper == "size")
			cout << ans.size() << '\n';
		else if (oper == "empty")
			cout << ans.empty() << '\n';
		else if (oper == "front")
		{
			if (ans.empty())
				cout << -1 << '\n';
			else
				cout << ans.front() << '\n';
		}
		else if (oper == "back")
		{
			if (ans.empty())
				cout << -1 << '\n';
			else
				cout << ans.back() << '\n';
		}
	}
	return 0;
}