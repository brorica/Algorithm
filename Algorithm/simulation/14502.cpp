#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
    int y, x;
}DIR;

DIR dir[4] = { {-1, 0} , {1, 0} , {0, 1} , {0, -1} };
queue<DIR> q;
vector<DIR> emptyV;

int N, M, emptySize, ans = 0;
int map[10][10];

int setWall(int count, int index);
int spread();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                q.push({ i,j });
            else if (map[i][j] == 0)
                emptyV.push_back({ i,j });
        }
    }
    emptySize = emptyV.size();
    setWall(0, 0);
    cout << ans;
    return 0;
}

int setWall(int count, int index)
{
    if (count == 3)
    {
        spread();
        return 0;
    }
    for (int i = index; i < emptySize; i++)
    {
        map[emptyV[i].y][emptyV[i].x] = 1;
        setWall(count + 1, i + 1);
        map[emptyV[i].y][emptyV[i].x] = 0;
    }
    return 0;
}

int spread()
{
    queue<DIR> tempQ = q;
    bool visit[10][10] = { 0, };
    int copyMap[10][10];
    int hereX, hereY, thereX, thereY;
    memcpy(copyMap, map, sizeof(copyMap));

    while (!tempQ.empty())
    {
        hereY = tempQ.front().y;
        hereX = tempQ.front().x;
        tempQ.pop();
        visit[hereY][hereX] = 1;

        for (int d = 0; d < 4; d++)
        {
            thereX = hereX + dir[d].x;
            thereY = hereY + dir[d].y;
            if (!(0 <= thereX && thereX < M && 0 <= thereY && thereY < N))
                continue;
            // 벽 or 방문한 곳
            if (copyMap[thereY][thereX] == 1 || visit[thereY][thereX])
                continue;
            visit[thereY][thereX] = 1;
            copyMap[thereY][thereX] = 2;
            tempQ.push({ thereY, thereX });
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copyMap[i][j] == 0)
                count++;
        }
    }
    ans = max(ans, count);
    return 0;
}

