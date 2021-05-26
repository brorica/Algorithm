#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

char map[16][16];
queue<pair<int, int>> q;
int R, C;

int start();
int remakeMap();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(map, '.', sizeof(map));

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'X')
                q.push({ i,j });
        }
    }

    start();
    remakeMap();
    return 0;
}

int start()
{
    int hereX, hereY, thereX, thereY;
    bool visit[16][16] = { 0, };
    while (!q.empty())
    {
        hereY = q.front().first;
        hereX = q.front().second;
        q.pop();

        int count = 0;
        for (int d = 0; d < 4; d++)
        {
            thereX = hereX + dx[d];
            thereY = hereY + dy[d];
            if (!(0 <= thereX && thereX <= C + 1 && 0 <= thereY && thereY <= R + 1))
                continue;
            if (map[thereY][thereX] == '.')
                count++;
        }
        // °¡¶ó¾ÉÀ½, S : sink
        if (count >= 3)
            map[hereY][hereX] = 'S';
    }
    return 0;
}

int remakeMap()
{
    int minX = 15, maxX = -1, minY = 15, maxY = -1;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (map[i][j] == 'X')
            {
                if (i > maxY)
                    maxY = i;
                if (i < minY)
                    minY = i;
                if (j > maxX)
                    maxX = j;
                if (j < minX)
                    minX = j;
            }
        }
    }

    for (int i = minY; i <= maxY; i++)
    {
        for (int j = minX; j <= maxX; j++)
        {
            if (map[i][j] == 'S')
                cout << '.';
            else
                cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}