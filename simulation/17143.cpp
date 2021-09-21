#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 128

typedef struct {
    int y, x, s, d, z;
}SHARKINFO;

typedef struct {
    int dy, dx;
}DIR;

int r, c, m;
DIR dir[4] = { {-1, 0} , {1, 0} , {0, 1} , {0, -1} };
vector<SHARKINFO> map[MAX][MAX];

int fisher(int x);
int sharkMove();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int y, x, s, d, z, ans = 0;
    cin >> r >> c >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> y >> x >> s >> d >> z;
        // 제자리로 돌아오는 경우 체크
        if (d <= 2)
            s %= (2 * r - 2);
        else
            s %= (2 * c - 2);
        map[y][x].push_back({ y, x, s, d - 1, z });
    }
    for (int i = 1; i <= c; i++)
    {
        ans += fisher(i);
        sharkMove();
    }
    cout << ans;
    return 0;
}

int fisher(int x)
{
    int ret = 0;
    for (int i = 1; i <= r; i++)
    {
        if (map[i][x].size())
        {
            ret = map[i][x][0].z;
            map[i][x].clear();
            break;
        }
    }
    return ret;
}

int sharkMove()
{
    int sharkY, sharkX, sharkS, sharkD, sharkZ;

    queue<SHARKINFO> sharkQ;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (map[i][j].size())
            {
                sharkQ.push(map[i][j][0]);
                map[i][j].clear();
            }
        }
    }

    while (!sharkQ.empty())
    {
        sharkY = sharkQ.front().y;
        sharkX = sharkQ.front().x;
        sharkS = sharkQ.front().s;
        sharkD = sharkQ.front().d;
        sharkZ = sharkQ.front().z;
        sharkQ.pop();

        for (int i = 0; i < sharkS; i++)
        {
            // 위, 아래
            if (sharkD < 2)
            {
                int nextY = sharkY + dir[sharkD].dy;
                if (nextY < 1 || nextY > r)
                    sharkD = 1 - sharkD;
                sharkY += dir[sharkD].dy;
            }
            else
            {
                int nextX = sharkX + dir[sharkD].dx;
                if (nextX < 1 || nextX > c)
                    sharkD = 5 - sharkD;
                sharkX += dir[sharkD].dx;
            }
        }

        if (map[sharkY][sharkX].size())
        {
            if (map[sharkY][sharkX][0].z < sharkZ)
            {
                map[sharkY][sharkX].clear();
                map[sharkY][sharkX].push_back({ sharkY, sharkX, sharkS, sharkD, sharkZ });
            }
        }
        else
            map[sharkY][sharkX].push_back({ sharkY, sharkX, sharkS, sharkD, sharkZ });
    }
    return 0;
}