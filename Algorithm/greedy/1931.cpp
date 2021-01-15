#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, start, end, i, j, ans = 0;
	vector <pair<int, int>> schedule;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> start >> end;
		// 이렇게 end start 바꿔 넣는건 생각 못했네
		schedule.push_back(make_pair(end, start));
	}
	sort(schedule.begin(), schedule.end());
	end = 0;
	for (i = 0; i < n; i++)
	{
		if (schedule[i].second < end)
			continue;
		end = schedule[i].first;
		ans++;
	}
	cout << ans;
	return 0;
}