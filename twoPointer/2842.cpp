#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char charMap[51][51];
int intMap[51][51] = { 0, };

int dfs(int startX, int startY)
{

    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, startX, startY, high;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> charMap[i][j];
            if (charMap[i][j] == 'P')
            {
                startX = j;
                startY = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> intMap[i][j];
            if (charMap[i][j] == 'P')
                high = intMap[i][j];
        }
    }


    return 0;
}