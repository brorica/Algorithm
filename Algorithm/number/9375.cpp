#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, n, ans, i;
	string name, type;
	cin >> T;
	while (T--)
	{
		map <string, int> m;
		cin >> n;
		ans = 1;
		for (i = 0; i < n; i++)
		{
			cin >> name >> type;
			if (m.find(type) == m.end())
				m.insert({ type, 1 });
			else
				m[type]++;
		}
		for (auto iter : m)
			ans *= (iter.second + 1);
		cout << ans - 1 << '\n';
	}
	return 0;
}