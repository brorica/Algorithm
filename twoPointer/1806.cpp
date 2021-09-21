#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, S, data, MINLEN = 0x7FFFFFFF;
	int start = 0, end = 0, sum = 0;
	vector<int> v;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		v.push_back(data);
	}
	v.push_back(0);  // ���ͷ� �� ��, �ڿ� 0 �߰� �� ���ָ� ��Ÿ�� �����߻�
	while (end<=N)
	{
		if (sum >= S)
		{
			int gap = end - start;
			if (gap < MINLEN)
				MINLEN = gap;
			sum -= v[start];
			start++;
		}
		else
		{
			sum += v[end];
			end++;
		}
	}
	if (MINLEN == 0x7FFFFFFF)
		cout << 0;
	else
		cout << MINLEN;
	return 0;
}