#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 100001
int sticker[2][MAX];

int solve(int N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        memset(sticker, 0, sizeof(sticker));
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                cin >> sticker[i][j];
        cout << solve(N) << '\n';
    }

    return 0;
}

/*
* cache[1][j] =
* sticker[1][j] + cache[0][j-1] // 대각선 위
* sticker[1][j] + cache[0][j-2] // 대각선 위를 선택하지 않을 때
* sticker[1][j] + cache[1][j-2] // 대각선 위를 선택하지 않을 때
*/

int solve(int N)
{
    int cache[2][MAX] = { 0, };
    int ret = max(sticker[0][1], sticker[1][1]);
    cache[0][1] = sticker[0][1];
    cache[1][1] = sticker[1][1];

    for (int j = 2; j <= N; j++)
    {
        cache[0][j] = max(cache[1][j - 1], max(cache[0][j - 2], cache[1][j - 2])) + sticker[0][j];
        cache[1][j] = max(cache[0][j - 1], max(cache[0][j - 2], cache[1][j - 2])) + sticker[1][j];
        ret = max(cache[0][j], cache[1][j]);
    }

    return ret;
}