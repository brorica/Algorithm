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
		st.top()이 이전의 st.top()보다 크면,
		maxStack.top()과 비교.
		maxStack을 pop한 뒤, 새로운 maxStack의 top()과 비교.
		이런식으로 maxStack의 top이 더 크다면, ans 스택에 maxStack의 top push.
		반대로, maxStack의 마지막 원소보다 커서, maxStack의 size가 0이 되면,
		ans 스택엔 -1 push, maxStack엔 해당 원소 push
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