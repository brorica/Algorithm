#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, i, j, data, Top, prevTop = -1;
	int stSize, tempSize;
	stack<int> st, maxStack;
	stack<int> ans;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		st.push(data);
	}
	stSize = st.size();
	maxStack.push(-1);
	/*
		st.top()�� ������ st.top()���� ũ��,
		maxStack.top()�� ��.
		maxStack�� pop�� ��, ���ο� maxStack�� top()�� ��.
		�̷������� maxStack�� top�� �� ũ�ٸ�, ans ���ÿ� maxStack�� top push.
		�ݴ��, maxStack�� ������ ���Һ��� Ŀ��, maxStack�� size�� 0�� �Ǹ�,
		ans ���ÿ� -1 push, maxStack�� �ش� ���� push
	*/
	for (i = 0; i < stSize; i++)
	{
		Top = st.top();
		if (Top >= prevTop)
		{
			tempSize = maxStack.size();
			for (j = 0; j < tempSize; j++)
			{
				if (Top >= maxStack.top())
					maxStack.pop();
				else
				{
					ans.push(maxStack.top());
					maxStack.push(Top);
					break;
				}
			}
			if (maxStack.empty())
			{
				ans.push(-1);
				maxStack.push(Top);
			}
		}
		else
		{
			ans.push(prevTop);
			maxStack.push(prevTop);
		}
		prevTop = Top;
		st.pop();
	}
	tempSize = ans.size();
	for (i = 0; i < tempSize; i++)
	{
		cout << ans.top() << ' ';
		ans.pop();
	}
	return 0;
}