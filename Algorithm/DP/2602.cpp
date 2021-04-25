#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main()
{
	int dp[32][2][128] = { 0, };
	char scroll[32];
	char bridge[2][128];
	int bridgeLen, scrollLen;
	// 0 : 악마  1 : 천사
	cin >> scroll >> bridge[0] >> bridge[1];
	bridgeLen = strlen(bridge[0]);
	scrollLen = strlen(scroll);

	for (int i = 0; i <= bridgeLen; i++)
	{
		dp[0][0][i] = 1;
		dp[0][1][i] = 1;
	}
	for (int i = 1; i <= scrollLen; i++)
	{
		for (int j = 1; j <= bridgeLen; j++)
		{
			// 천사 돌다리 점검
			if (scroll[i - 1] == bridge[1][j - 1])
				dp[i][0][j] += dp[i - 1][1][j - 1];
			// 악마 돌다리 점검
			if (scroll[i - 1] == bridge[0][j - 1])
				dp[i][1][j] += dp[i - 1][0][j - 1];
			// 건너뛰어서 오는 경우 합산
			dp[i][1][j] += dp[i][1][j - 1];
			dp[i][0][j] += dp[i][0][j - 1];
		}
	}
	cout << dp[scrollLen][0][bridgeLen] + dp[scrollLen][1][bridgeLen];
	return 0;
}