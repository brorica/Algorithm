#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> ppap;
	int flag = 0;
	char p;
	while (1)
	{
		cin >> p;
		if (cin.eof())
			break;
		if (p == 'A')
		{
			if (ppap.empty())
			{
				cout << "NP\n";
				return 0;
			}
			ppap.pop();
			flag = 1;
		}
		else if (p == 'P' && flag == 1)
		{
			flag = 0;
			if (ppap.empty())
			{
				cout << "NP\n";
				return 0;
			}
			ppap.pop();
		}
		else
			ppap.push(p);
	}
	cout << "PPAP";

	return 0;
}