#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 64

typedef struct
{
    int y, x;
}DIR;

int L, W, ans = 0;
DIR dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
char map[MAX][MAX];
vector<DIR> land;


int search(int y, int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> W;
    for (int i = 0; i < L; i++)
        cin >> map[i];

    for (int i = 0; i < L; i++)
        for (int j = 0; j < W; j++)
            if (map[i][j] == 'L')
                land.push_back({ i,j });

    for (int i = 0; i < land.size(); i++)
    {
        search(land[i].y, land[i].x);
    }
    cout << ans;
    return 0;
}

int search(int y, int x)
{
    int visit[MAX][MAX] = { 0, };
    int hereX, hereY, thereX, thereY, cost = 1;
    queue<DIR> q;
    q.push({ y,x });
    visit[y][x] = cost;
    while (!q.empty())
    {
        int size = q.size();
        cost++;
        for (int i = 0; i < size; i++)
        {
            hereY = q.front().y;
            hereX = q.front().x;
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                thereY = hereY + dir[d].y;
                thereX = hereX + dir[d].x;
                if (!(0 <= thereX && thereX < W && 0 <= thereY && thereY < L))
                    continue;
                if (visit[thereY][thereX] || map[thereY][thereX] == 'W')
                    continue;
                visit[thereY][thereX] = cost;
                q.push({ thereY, thereX });
            }
        }
    }
    ans = max(cost - 2, ans);
    return 0;
}