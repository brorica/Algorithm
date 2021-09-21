#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int convertNum(stack<int>& temp)
{
	int convert = 0, stacklen = temp.size();
	for (int j = 0; j < stacklen; j++)
	{
		convert += temp.top() * (int)pow(10, j);
		temp.pop();
	}
	return convert;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> number;
	vector <char> oper;
	string s;
	stack<int> temp;
	int i, j, slen, numberlen, sum, minusSum;
	cin >> s;
	slen = s.length();
	for (i = 0; i < slen; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			temp.push(s[i] - '0');
		else
		{
			number.push_back(convertNum(temp));
			oper.push_back(s[i]);
		}
	}
	number.push_back(convertNum(temp));
	numberlen = number.size();
	sum = number[0];
	for (i = 1; i < numberlen; i++)
	{
		if (oper[i - 1] == '+')
			sum += number[i];
		// 빼기일 때
		else
		{
			minusSum = number[i];
			for (j = i + 1; j < numberlen; j++)
			{
				// 또 빼기면 그냥 나감
				if (oper[j - 1] == '-')
					break;
				else
				{
					minusSum += number[j];
					i = j;
				}
			}
			sum -= minusSum;
		}
	}
	cout << sum;
	return 0;
}