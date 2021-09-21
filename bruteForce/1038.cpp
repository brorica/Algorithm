#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1000000

int N;
int index = 10;
queue<long long> q;
long long table[MAX + 1] = { 0, };

int calc();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= 9; i++)
    {
        q.push(i);
        table[i] = i;
    }
    calc();
    if (table[N] == 0)
        cout << -1;
    else
        cout << table[N];
    return 0;
}

int calc()
{
    while (index <= N)
    {
        if (q.empty())
            break;
        long long temp = q.front();
        q.pop();
        // 마지막 자릿수 확인
        int lastNum = temp % 10;
        for (int i = 0; i < lastNum; i++)
        {
            q.push(temp * 10 + i);
            table[index++] = temp * 10 + i;
        }
    }
    return 0;
}