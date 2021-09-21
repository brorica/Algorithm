#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 64

typedef struct
{
    int y, x, cost;
}DIR;

int L, W, ans = 0;
DIR dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
int map[MAX][MAX];
queue<DIR> land;


int search(int y, int x);
int check(int y, int x);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> L >> W;
    for (int i = 1; i <= L; i++)
    {
        cin >> str;
        for (int j = 1; j <= W; j++) {
            if (str[j - 1] == 'L') {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= W; j++)
            if (map[i][j] == 1)
                check(i, j);

    while(!land.empty())
    {
        search(land.front().y, land.front().x);
        land.pop();
    }
    cout << ans;
    return 0;
}

int check(int y, int x)
{
    /* �� �Ʒ��� ���� ������ �ش� ��ġ��
       �׳� ���İ��� �����̶� ť�� �� �־ �� */
    if (map[y - 1][x] == 1 && map[y + 1][x] == 1)
        return 0;
    /* ���������� �¿쿡 ���� ������ �ش� ��ġ��
       �׳� ���İ��� �����̶� ť�� �� �־ �� */
    if (map[y][x - 1] == 1 && map[y][x + 1] == 1)
        return 0;
    /* ���� �� ������ �����ϰ� �Ʒ�, �����ʰ��� 2���� �������� ������ ��
       �� ������ ���� ���� �����ٸ� �ش� ����Ŭ�� �ƹ� �������� Ž���� �ص� ���� ����
       ���� ������ �ʴ´ٸ� ������ �� ������ ���������� �Ÿ��� �� ��� ������
       �ش� ��ġ�� ���İ��� �ڸ��� �ǹ�����
    */
    if (map[y][x + 1] == 1 && map[y + 1][x] == 1)
        return 0;
    land.push({ y,x,0 });
    return 0;
}

int search(int y, int x)
{
    bool visit[MAX][MAX] = { 0, };
    int hereX, hereY, hereC, thereX, thereY;
    queue<DIR> q;
    q.push({ y,x });
    visit[y][x] = 1;
    while (!q.empty())
    {
        hereY = q.front().y;
        hereX = q.front().x;
        hereC = q.front().cost;
        q.pop();
        ans = max(ans, hereC);
        for (int d = 0; d < 4; d++)
        {
            thereY = hereY + dir[d].y;
            thereX = hereX + dir[d].x;
            if (!(0 < thereX && thereX <= W && 0 < thereY && thereY <= L))
                continue;
            if (visit[thereY][thereX] || map[thereY][thereX] == 0)
                continue;
            visit[thereY][thereX] = 1;
            q.push({ thereY, thereX, hereC + 1 });
        }
    }
    return 0;
}