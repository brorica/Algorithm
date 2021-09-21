#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int> ans;
	int T, ip, sum = 0, stackSize;
	cin >> T;
	while (T--)
	{
		cin >> ip;
		if (ip != 0)
			ans.push(ip);
		else
			ans.pop();
	}
	stackSize = ans.size();
	for (int i = 0; i < stackSize; i++)
	{
		sum += ans.top();
		ans.pop();
	}
	cout << sum;
	return 0;
}