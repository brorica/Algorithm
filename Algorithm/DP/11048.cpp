#include <iostream>
#include <algorithm>
using namespace std;

// 토글링 기법

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, candy;
    int DP[1024] = { 0, };
    cin >> N >> M;
    while (N--)
    {
        for (int i = 1; i <= M; i++)
        {
            cin >> candy;
            DP[i] = max(DP[i - 1], DP[i]) + candy;
        }
    }
    cout << DP[M];
    return 0;
}
