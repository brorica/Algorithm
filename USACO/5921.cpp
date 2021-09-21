#include <iostream>
using namespace std;

int N, MAX = -1, cow[32];
int rec(int index, int sum, int count)
{
	if (count > MAX)
		MAX = count;
	if (index >= N)
		return 0;
	int temp1 = sum;
	int temp2 = cow[index];
	// ������ 0�� �� �� ���� �˻�
	while (temp1 > 0 && temp2 > 0)
	{
		if (temp1 % 10 + temp2 % 10 >= 10)
			break;
		temp1 /= 10;
		temp2 /= 10;
	}
	// ������ 0�̶� �� ĳ���� �߻����� �ʾҴ� �ǹ�
	if (temp1 == 0 || temp2 == 0)
		rec(index + 1, sum + cow[index], count + 1);
	rec(index + 1, sum, count);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> cow[i];
	rec(0, 0, 0);
	cout << MAX;
	return 0;
}