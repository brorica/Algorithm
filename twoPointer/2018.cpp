#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, start = 1, end = 1, limit;
    int sum = 0, count = 1; // 자기 자신
    cin >> N;
    while (end <= N)
    {
        if (sum > N)
        {
            sum -= start;
            start++;
        }
        else
        {
            sum += end;
            end++;
        }
        if (sum == N)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}