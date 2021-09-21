#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 128

typedef struct
{
    int y, x;
}DIR;

int N, M;
int map[MAX][MAX] = { 0, };

DIR dir[4] = { {0,1}, {0, -1}, {1, 0}, {-1,0} };
queue<DIR> chocolate;

int serachOutSide(int y, int x);
int melt();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                serachOutSide(i, j);
                melt();
                ans++;
            }
        }
    }
    cout << ans - 1;
    return 0;
}

int serachOutSide(int y, int x)
{
    int hereX, hereY, thereX, thereY;
    bool visit[MAX][MAX] = { 0, };
    queue<DIR> q;

    q.push({ y, x });
    visit[y][x] = 1;
    map[y][x] = 2;

    while (!q.empty())
    {
        hereY = q.front().y;
        hereX = q.front().x;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            thereY = hereY + dir[d].y;
            thereX = hereX + dir[d].x;
            // 범위 이탈
            if (!(0 <= thereX && thereX < M && 0 <= thereY && thereY < N))
                continue;
            //  탐색한 곳
            if (visit[thereY][thereX] == 1)
                continue;
            visit[thereY][thereX] = 1;
            // 초콜릿
            if (map[thereY][thereX] == 1)
                chocolate.push({ thereY, thereX });
            // 외부 공기
            else
            {
                map[thereY][thereX] = 2;
                q.push({ thereY, thereX });
            }
        }
    }
    return 0;
}

int melt()
{
    int hereX, hereY, thereX, thereY;
    int visit[MAX][MAX] = { 0, };
    queue<DIR> meltChocolat;

    while (!chocolate.empty())
    {
        hereY = chocolate.front().y;
        hereX = chocolate.front().x;
        chocolate.pop();
        for (int d = 0; d < 4; d++)
        {
            thereY = hereY + dir[d].y;
            thereX = hereX + dir[d].x;
            // 범위 이탈
            if (!(0 <= thereX && thereX < M && 0 <= thereY && thereY < N))
                continue;
            // 외부 공기와 닿았을 때
            if (map[thereY][thereX] == 2)
                visit[hereY][hereX]++;
        }
        // 외부 공기와 닿은 횟수가 2 이상이면 녹여버림
        if (visit[hereY][hereX] >= 2)
            map[hereY][hereX] = 0;
    }
    return 0;
}