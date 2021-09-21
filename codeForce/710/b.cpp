#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	int n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		string s;
		vector<int> star;
		int count = 0;
		int position = 0;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '*')
				star.push_back(i);
		}
		int starSize = star.size();
		if (starSize > 0)
		{
			int point = star[0];
			count = 1;
			for (int i = 1; i < starSize; i++)
			{
				if (star[i] - point == k)
				{
					point = star[i];
					count++;
				}
				else if (star[i] - point > k)
				{
					point = star[i - 1];
					count++;
					if (i == starSize - 1)
					{
						count++;
					}
				}
				else
				{
					if (i == starSize - 1)
					{
						count++;
					}
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}