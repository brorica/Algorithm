#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, M, i, doc;
	int index, prior, count;
	cin >> T;
	while (T--)
	{
		queue<pair<int, int>> print;
		priority_queue<int> priorPrint;
		cin >> N >> M;
		for (i = 0; i < N; i++)
		{
			cin >> doc;
			print.push(make_pair(doc, i));
			priorPrint.push(doc);
		}
		count = 0;
		while (!print.empty())
		{
			prior = print.front().first;
			index = print.front().second;
			if (priorPrint.top() == prior)
			{
				priorPrint.pop();
				count++;
				if (index == M)
				{
					cout << count << '\n';
					break;
				}
			}
			else
				print.push(make_pair(prior, index));
			print.pop();
		}

	}
	return 0;
}