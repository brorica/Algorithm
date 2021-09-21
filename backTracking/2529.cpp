#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int T;
int isUsed[10] = { 0, };
char ans[16] = { 0, };
char list[16];
vector <string> ansList;

int func(int count, int before)
{
	if (count == T+1)
		ansList.push_back(ans);
	else
	{
		for (auto i = 0; i <= 9; i++)
		{
			if (!isUsed[i])
			{
				if (count == 0)
					ans[0] = i + '0';
				else
				{
					if (list[count - 1] == '>' && before <= i)
						return 0;
					if (list[count - 1] == '<' && before >= i)
						continue;
					ans[count] = i + '0';
				}
				isUsed[i] = 1;
 				func(count + 1, i);
				isUsed[i] = 0;
			}
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (auto i = 0; i < T; i++)
		cin >> list[i];
	func(0, -1);
	cout << ansList[ansList.size()-1] << '\n';
	cout << ansList[0] << '\n';
	return 0;
}