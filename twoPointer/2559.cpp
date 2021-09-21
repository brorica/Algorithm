#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    int start = 0, end, MAX, sum = 0;
    int weather[100001] = { 0, };
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> weather[i];
    for (end = 0; end < K; end++)
        sum += weather[end];
    MAX = sum;
    for (end; end < N; end++, start++)
    {
        sum = sum + weather[end] - weather[start];
        if (MAX < sum)
            MAX = sum;
    }
    cout << MAX;
    return 0;
}