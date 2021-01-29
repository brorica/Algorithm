#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<pair<int, int>> q;
	int N, oper;
	cin >> N;
	while (N--)
	{
		cin >> oper;
		if (oper == 0)
		{
			if (q.empty())
				cout << 0;
			else
			{
				cout << q.top().second;
				q.pop();
			}
			cout << '\n';
		}
		else
			q.push(make_pair(abs(oper), oper));
	}
	return 0;
}