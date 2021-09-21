#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int,vector<int>, greater<int>> upper;
	priority_queue<int> lower;
	int N, num;
	cin >> N;
	cin >> num;
	cout << num << '\n';
	upper.push(num);
	for(int i = 1;i<N;i++)
	{
		cin >> num;
		if (upper.top() >= num)
			lower.push(num);
		else
			upper.push(num);
		if (upper.size() > lower.size())
		{
			lower.push(upper.top());
			upper.pop();
		}
		else if(lower.size() > upper.size() + 1)
		{
			upper.push(lower.top());
			lower.pop();
		}
		cout << lower.top() << '\n';
	}
	return 0;
}