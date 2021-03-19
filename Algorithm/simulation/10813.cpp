#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int recommend[128] = { 0, };
	int order[128] = { 0, };
	int N, M, a, b=0;
	cin >> N >> M;
	for(int i=1;i<=M;i++)
	{
		cin >> a;
		// ������ ����
		if (recommend[a])
			recommend[a]++;
		// ������ ����
		else
		{
			if (b < N)
			{
				recommend[a] = 1;
				order[a] = i;
				b++;
			}
			// ���� ��ü
			else
			{
				int MIN = 0x7FFFF;
				int minIndex = 0;
				for (int i = 1; i <= 100; i++)
				{
					if (recommend[i] != 0 && recommend[i] < MIN)
					{
						MIN = recommend[i];
						minIndex = i;
					}
					else if (recommend[i] == MIN)
					{
						// ���� ū �� �ֽ���
						if (order[minIndex] > order[i])
						{
							minIndex = i;
						}
					}
				}
				recommend[minIndex] = 0;
				order[minIndex] = 0;
				recommend[a] = 1;
				order[a] = i;
			}
		}
	}
	for (int i = 1; i <= 100; i++)
	{
		if (recommend[i])
			cout << i << ' ';
	}
	return 0;
}