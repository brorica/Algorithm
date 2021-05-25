#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define MAX 64

typedef struct
{
    int y, x;
}DIR;

int N, M, SIZE, ans = 0x7FFFFFFF, zeroCount = 0;
int map[MAX][MAX] = { 0, };

vector<DIR> virus;
DIR dir[4] = { {0,1}, {0, -1}, {1, 0}, {-1,0} };

int setVirus(int count, int Index, vector<int> & virusIndexs);
int start(vector<int>& virusIndexs);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> virusIndexs;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back({ i,j });
            else if (map[i][j] == 0)
                zeroCount++;
        }
    }
    SIZE = virus.size();
    setVirus(0, 0, virusIndexs);
    if (ans == 0x7FFF)
        cout << -1;
    else
        cout << ans;

    return 0;
}

int setVirus(int count, int index, vector<int>& virusIndexs)
{
    if (count == M)
    {
       start(virusIndexs);
       return 0;
    }
    for (int i = index; i < SIZE; i++)
    {
        virusIndexs.push_back(i);
        setVirus(count + 1, i + 1, virusIndexs);
        virusIndexs.pop_back();
    }
    return 0;
}

int start(vector<int>& virusIndexs)
{
    int timer = 0;
    int hereX, hereY, thereX, thereY;
    int count = zeroCount;
    int copyMap[MAX][MAX];
    bool visit[MAX][MAX] = { 0, };
    deque<DIR> q;

    memcpy(copyMap, map, sizeof(map));
    // 바이러스 위치 큐에 저장
    for (int i = 0; i < M; i++)
    {
        int index = virusIndexs[i];
        q.push_back({ virus[index].y, virus[index].x });
    }

    while (!q.empty())
    {
        int size = q.size();
        if (count <= 0)
            break;
        for (int i = 0; i < size; i++)
        {
            hereY = q.front().y;
            hereX = q.front().x;
            visit[hereY][hereX] = 1;
            q.pop_front();
            for (int d = 0; d < 4; d++)
            {
                thereY = hereY + dir[d].y;
                thereX = hereX + dir[d].x;
                // 범위 이탈
                if (!(0 <= thereX && thereX < N && 0 <= thereY && thereY < N))
                    continue;
                // 벽이거나 퍼진 곳
                if (copyMap[thereY][thereX] == 1 || visit[thereY][thereX] == 1)
                    continue;

                if (copyMap[thereY][thereX] == 0)
                    count--;

                visit[thereY][thereX] = 1;
                copyMap[thereY][thereX] = 1;
                q.push_back({ thereY, thereX });
            }
        }
        timer++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (copyMap[i][j] == 0)
            {
                ans = min(ans, 0x7FFF);
                return 0;
            }
        }
    }
    ans = min(ans, timer);
    return 0;
}