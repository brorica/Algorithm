#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    int flag = 0;
    int dp[2][1024] = { 0, };
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;

    for (int i = 1; i < b.length(); i++)
    {
        for (int j = 1; j < a.length(); j++)
        {
            if (b[i] == a[j])
                dp[flag][j] = dp[flag ^ 1][j - 1] + 1;
            else
                dp[flag][j] = max(dp[flag ^ 1][j], dp[flag][j - 1]);
        }
        flag ^= 1;
    }
    cout << dp[flag ^ 1][a.length() - 1];
    return 0;
}
