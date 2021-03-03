#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, data, start = 0, end;
    long long sum, a, b, MIN = LLONG_MAX;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        v.push_back(data);
    }
    end = N - 1;
    while (start < end)
    {
        sum = v[start] + v[end];
        if (llabs(sum) < MIN)
        {
            MIN = llabs(sum);
            a = v[start];
            b = v[end];
        }
        else if (sum > 0)
            end--;
        else
            start++;
    }
    cout << a << ' ' << b;
    return 0;
}