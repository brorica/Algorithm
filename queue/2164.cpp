#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	queue<int> ans;
	cin >> N;
	for (auto i = 1; i <= N; i++)
		ans.push(i);
	while (ans.size() > 1)
	{
		ans.pop();
		ans.push(ans.front());
		cout << ans.front() << ' ';
		ans.pop();
	}
	return 0;
}