#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int flag;
	int slen, i;
	string s;
	while (1)
	{
		stack<char> bracket;
		flag = 0;
		getline(cin, s);
		if (s[0] == '.')
			break;
		slen = s.length();
		for (i = 0; i < slen; i++)
		{
			if (s[i] == '(')
				bracket.push('(');
			else if (s[i] == '[')
				bracket.push('[');
			else if (s[i] == ')')
			{
				if (bracket.empty() || bracket.top() != '(')
				{
					flag = 1;
					break;
				}
				bracket.pop();
			}
			else if (s[i] == ']')
			{
				if (bracket.empty() || bracket.top() != '[')
				{
					flag = 1;
					break;
				}
				bracket.pop();
			}
		}
		if (flag || !bracket.empty())
			cout << "no";
		else
			cout << "yes";
		cout << '\n';
	}
	return 0;
}