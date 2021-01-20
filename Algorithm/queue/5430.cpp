#include <iostream>
#include <string>
#include <deque>
#include <string.h>
#pragma warning (disable:4996)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, i, reverseFlag;	// 0 : normal, 1 : reverse
	int operLen, numLen, errorFlag;
	char num[400001];
	string oper;
	cin >> T;
	while (T--)
	{
		deque <int> ans;
		cin >> oper >> numLen;
		cin >> num;
		char* temp = strtok(num, "[,]");
		while (temp != NULL)
		{
			ans.push_back(atoi(temp));
			temp = strtok(NULL, "[,]");
		}
		operLen = oper.length();
		errorFlag = 0;
		reverseFlag = 0;
		for (i = 0; i < operLen; i++)
		{
			if (oper[i] == 'R')
				reverseFlag = !reverseFlag;
			else
			{
				if (ans.empty())
				{
					cout << "error" << '\n';
					errorFlag = 1;
					break;
				}
				else
				{
					if (reverseFlag)
						ans.pop_back();
					else
						ans.pop_front();
				}
			}
		}
		if (!errorFlag)
		{
			cout << '[';
			numLen = ans.size();
			if (reverseFlag == 0)
			{
				for (i = 0; i < numLen; i++)
				{
					cout << ans.front();
					ans.pop_front();
					if (!ans.empty())
						cout << ',';
				}
			}
			else
			{
				for (i = 0; i < numLen; i++)
				{
					cout << ans.back();
					ans.pop_back();
					if (!ans.empty())
						cout << ',';
				}
			}
			cout << "]\n";
		}

	}
	return 0;
}