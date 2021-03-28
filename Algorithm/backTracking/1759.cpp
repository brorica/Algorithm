#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> ans;
char input[32];
int L, C;

int backtracking(int index, int count)
{
	if (count == L)
	{
		int vowelCount = 0;
		int consonantCount = 0;
		for (int i = 0; i < count; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				vowelCount++;
			else
				consonantCount++;
		}
		if (vowelCount >= 1 && consonantCount >= 2)
		{
			for (int i = 0; i < count; i++)
				cout << ans[i];
			cout << '\n';
		}
		return 0;
	}
	for (int i = index; i < C; i++)
	{
		ans.push_back(input[i]);
		backtracking(i + 1, count + 1);
		ans.pop_back();
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> input[i];
	sort(input, input + C);
	backtracking(0, 0);
	return 0;
}