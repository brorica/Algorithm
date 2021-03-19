#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, w, L, i, sum = 0, count = 0;
	int truck[1024] = { 0, };
	queue <int> order;
	cin >> n >> w >> L;
	for (i = 0; i < n; i++)
	{
		cin >> truck[i];
	}
	i = 0;
	while(i < n)
	{
		if (sum + truck[i] <= L)
		{
			sum += truck[i];
			order.push(truck[i]);
			i++;
		}
		else
			order.push(0);
		count++;
		if (count >= w)
		{
			if (order.front() > 0)
				sum -= order.front();
			order.pop();
		}
	}
	cout << count + w;
	return 0;
}