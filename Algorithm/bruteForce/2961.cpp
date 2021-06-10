#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int ans = 0x7FFFFFFF;
bool check[16] = { 0, };
typedef struct
{
    int s, b;
}FLAVOR;

int N;
vector<FLAVOR> v;

int search(int count, int mul, int sum);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int S, B;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S >> B;
        v.push_back({ S,B });
    }
    search(0, 1, 0);
    cout << ans;
    return 0;
}

int search(int count, int mul, int sum)
{
    if (count == N)
    {
        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            if (check[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return 0x7FFFFFFF;
        ans = min(ans, abs(mul - sum));
        return 0;
    }
    check[count] = 1;
    search(count + 1, mul * v[count].s, sum + v[count].b);
    check[count] = 0;
    search(count + 1, mul, sum);
    return 0;
}