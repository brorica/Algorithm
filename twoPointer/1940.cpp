#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, data, ans = 0;
    int start = 0, end, sum;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        v.push_back(data);
    } 
    sort(v.begin(), v.end());
    end = N - 1;
    while (start < end)
    {
        sum = v[start] + v[end];
        if (sum == M)
        {
            ans++;
            end--;
            start++;
        }
        else if (sum > M)
            end--;
        else
            start++;
    }
    cout << ans;
    return 0;
}