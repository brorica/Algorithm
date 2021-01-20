#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K, i;
	queue<int> ans;
	cin >> N >> K;
	for (i = 1; i <= N; i++)
		ans.push(i);
	cout << '<';
	while (1)
	{
		for (i = 1; i <= K - 1; i++)
		{
			ans.push(ans.front());
			ans.pop();
		}
		cout << ans.front();
		ans.pop();
		if (ans.empty())
			break;
		cout << ", ";
	}
	cout << '>';
	return 0;
}