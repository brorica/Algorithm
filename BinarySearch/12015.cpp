#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, data, end;
	vector<int> ans;
	cin >> N;
	ans.push_back(-1);
	for (i = 0; i < N; i++)
	{
		cin >> data;
		if (ans.back() < data)
			ans.push_back(data);
		else
		{
			int left = 1, mid, right = ans.size() - 1;
			while (left < right)
			{
				mid = (left + right) / 2;
				if (ans[mid] >= data)
					right = mid;
				else
					left = mid + 1;
			}
			ans[left] = data;
		}
	}
	cout << ans.size() - 1;
	return 0;
}