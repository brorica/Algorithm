#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<int> stick[4];
	vector<pair<int, int>> ans;
	int T, plate;
	int start = 1, by = 2, to = 3;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> plate;
		stick[start].push(plate);
	}
	while (T)
	{
		if (stick[start].size())
		{
			plate = stick[start].top();
			stick[start].pop();
			if (plate == T)
			{
				stick[to].push(plate);
				T--;
				ans.push_back({start, to});
			}
			else
			{
				stick[by].push(plate);
				ans.push_back({ start, by });
			}
		}
		else
			swap(start, by);
	}
	int size = ans.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}