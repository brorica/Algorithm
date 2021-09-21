#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, data;
    int start = 0, mid, end, sub, MIN = 0x7FFFFFFF;
    vector<int> v;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        v.push_back(data);
    }
    sort(v.begin(), v.end());
    for (int i = N - 1; i > 0; i--)
    {
        int temp = i;
        end = temp - 1;
        start = 0;
        while (start <= end)
        {
            mid = (start + end) / 2;
            sub = v[temp] - v[mid];
            if (sub >= M)
            {
                if (sub < MIN)
                    MIN = sub;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }
    cout << MIN;
    return 0;
}