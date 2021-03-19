#include <iostream>
#include <algorithm>
using namespace std;

struct Cow {
	int start;
	int end;
}cow[25000];

bool compare(Cow a, Cow b)
{
	return a.start < b.start;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T;
	int current = 0, end = 0, ans = 0;
	cin >> N >> T;
	for (int i = 0; i < N; i++)
		cin >> cow[i].start >> cow[i].end;
	sort(cow, cow + N, compare);
	// 시작점은 1부터 시작해야 한다.
	if (cow[0].start > 1)
		ans = -1;
	else
	{
		while (end < T)
		{
			int MAX = -1;
			while (current < N && cow[current].start <= end + 1)
			{
				MAX = max(MAX, cow[current].end);
				current++;
			}
			if (MAX == -1)
			{
				ans = -1;
				break;
			}
			ans++;
			end = MAX;
		}
	}
	cout << ans;
	return 0;
}