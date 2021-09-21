#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	int sLen, tLen, sPointer = 0, ans = 0;
	int check[200001] = { 0, };
	cin >> sLen >> tLen;
	cin >> s >> t;
	for (sPointer; sPointer < sLen; sPointer++)
	{
		if (s[sPointer] == t[0])
		{
			check[0] = sPointer;
			sPointer += 1;
			break;
		}
	}

	for (int i = 1; i < tLen; i++)
	{
		for (sPointer; sPointer < sLen; sPointer++)
		{
			if (s[sPointer] == t[i])
				check[i] = sPointer;
			else
				break;
		}
	}
	for (int i = 1; i < tLen; i++)
	{
		ans = max(ans, check[i] - check[i - 1]);
	}
	cout << ans;
	return 0;
}