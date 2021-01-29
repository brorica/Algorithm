#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, oper, data;
	priority_queue <int> q;
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
				cout << q.top() * -1;
				q.pop();
			}
			cout << '\n';
		}
		else
			q.push(oper * -1);
	}
	return 0;
}