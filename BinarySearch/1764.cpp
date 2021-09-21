#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, temp;
	int left, mid, right;
	vector<string> v1;
	vector<string> ans;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		v1.push_back(str);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		left = 0;
		right = v1.size() - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			temp = v1[mid].compare(str);
			if (temp == -1)
				left = mid + 1;
			else if (temp == 0)
			{
				ans.push_back(v1[mid]);
				break;
			}
			else
				right = mid - 1;

		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}