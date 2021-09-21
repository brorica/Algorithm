#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, count=0, MIN=0x7FFFFFFF;
	char data;
	vector<char> v;
	queue<char> q;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	for (int i = 0; i < N; i++)
	{
		if (v[i] == '1')
			count++;
		q.push(v[i]);
		if (count == K)
		{
			count--;
			while (q.front() != '1')
				q.pop();
			if (MIN > q.size())
				MIN = q.size();
			q.pop();
		}
	}
	if (MIN == 0x7FFFFFFF)
		cout << "-1\n";
	else
		cout << MIN;
	return 0;
}