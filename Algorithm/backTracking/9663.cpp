#include <iostream>
#include <math.h>
using namespace std;
int position[16] = { 0, };
int N, ans = 0;
int queen(int count)
{
	int i, j, flag;
	if (count == N)
		ans += 1;
	else
	{
		for (i = 0; i < N; i++)
		{
			flag = 1;
			position[count] = i;
			for (j = 0; j < count; j++)
			{
				if (position[j] == position[count] || (abs(position[j] - position[count]) == count - j))
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				queen(count + 1);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	queen(0);
	cout << ans;
	return 0;
}