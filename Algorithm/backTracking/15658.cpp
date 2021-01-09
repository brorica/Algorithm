#include <iostream>
using namespace std;

int T, operlen = 0;
long long N[16];
long long NumMax = -1000000001, NumMin = 1000000001;
int oper[4] = { 0, };
int func(int count, long long sum)
{
	if (count == T)
	{
		if (sum > NumMax)
			NumMax = sum;
		if (sum < NumMin)
			NumMin = sum;
	}
	else
	{
		if (oper[0] > 0)
		{
			oper[0] -= 1;
			func(count + 1, sum + N[count]);
			oper[0] += 1;
		}
		if (oper[1] > 0)
		{
			oper[1] -= 1;
			func(count + 1, sum - N[count]);
			oper[1] += 1;
		}
		if (oper[2] > 0)
		{
			oper[2] -= 1;
			func(count + 1, sum * N[count]);
			oper[2] += 1;
		}
		if (oper[3] > 0)
		{
			oper[3] -= 1;
			func(count + 1, sum / N[count]);
			oper[3] += 1;
		}
	}
	return sum;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	int plus, minus, multi, divide;
	cin >> T;
	for (i = 0; i < T; i++)
		cin >> N[i];
	for (i = 0; i < 4; i++)
		cin >> oper[i];
	func(1, N[0]);
	cout << NumMax << '\n' << NumMin;
	return 0;
}