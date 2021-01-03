#include <iostream>
#include <stack>

using namespace std;

int T;
int N[16];
long long NumMax = -1000000001, NumMin = 1000000001;
int operCheck[512] = { 0, };
char oper[512];
long long result;
int func(int count)
{
	long long temp = result;
	if (count == T)
	{
		if (result > NumMax)
			NumMax = result;
		if (result < NumMin)
			NumMin = result;
	}
	else
	{
		for (auto i = 1; i < T; i++)
		{
			if (!operCheck[i])
			{
				operCheck[i] = 1;
				switch (oper[i])
				{
				case '+': result += N[count]; break;
				case '-': result -= N[count]; break;
				case '/': result /= N[count]; break;
				case '*': result *= N[count]; break;
				}
				func(count + 1);
				result = temp;
				operCheck[i] = 0;
			}
		}
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, operlen = 1;
	int plus, minus, multi, divide;
	cin >> T;
	for (i = 0; i < T; i++)
		cin >> N[i];
	cin >> plus >> minus >> multi >> divide;
	for (i = 0; i < plus; i++)
		oper[operlen++] = '+';
	for (i = 0; i < minus; i++)
		oper[operlen++] = '-';
	for (i = 0; i < multi; i++)
		oper[operlen++] = '*';
	for (i = 0; i < divide; i++)
		oper[operlen++] = '/';
	result = N[0];
	func(1);
	cout << NumMax << '\n' << NumMin;
	return 0;
}