#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i, slen, flag;
	string s;
	cin >> T;
	while (T--)
	{
		stack<int> ans;
		cin >> s;
		slen = s.length();
		flag = 0;
		for (i = 0; i < slen; i++)
		{
			if (s[i] == '(')
				ans.push(1);
			else
			{
				if (ans.empty())
				{
					cout << "NO\n";
					flag = 1;
					break;
				}
				ans.pop();
			}
		}
		if (flag)
			continue;
		if (!ans.empty())
			cout << "NO";
		else
			cout << "YES";
		cout << "\n";
	}
	return 0;
}