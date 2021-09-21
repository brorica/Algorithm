#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 64

typedef struct
{
    int y, x;
}DIR;

int N, M, ans = 0x7FFFFFFF, chickenHouseCount;
int map[MAX][MAX];

vector<DIR> house;
vector<DIR> chickenHouse;

int closeChickenHouse(int index, int count);
int calc();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                house.push_back({ i,j });
            else if (map[i][j] == 2)
                chickenHouse.push_back({ i,j });
        }
    }
    chickenHouseCount = chickenHouse.size();
    closeChickenHouse(0, 0);
    cout << ans;
    return 0;
}
// count : �����Ų ġŲ�� ��
int closeChickenHouse(int index, int count)
{
    // ���� ����
    if (chickenHouseCount - count <= 0 && count != 0)
        return 0;
    // ��� �� ���� ���ܾ� ��
    if (chickenHouseCount - count >= 1 && chickenHouseCount - count <= M)
    {
        calc();
    }
    // ����
    for (int i = index; i < chickenHouseCount; i++)
    {
        map[chickenHouse[i].y][chickenHouse[i].x] = 0;
        closeChickenHouse(i + 1, count + 1);
        map[chickenHouse[i].y][chickenHouse[i].x] = 2;
    }
    return 0;
}

int calc()
{
    queue<DIR> chickenQ;
    int distanceMap[MAX][MAX];
    int chikenHouseX, chikenHouseY, houseX, houseY;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            distanceMap[i][j] = 0x7FFFFFFF;
            if (map[i][j] == 2)
                chickenQ.push({ i,j });
        }
    }


    while (!chickenQ.empty())
    {
        chikenHouseX = chickenQ.front().x;
        chikenHouseY = chickenQ.front().y;
        chickenQ.pop();
        for (int i = 0; i < house.size(); i++)
        {
            houseX = house[i].x;
            houseY = house[i].y;
            // �Ÿ��� ���ϰ�
            int distance = abs(houseX - chikenHouseX) + abs(houseY - chikenHouseY);
            // �Ÿ��� �ּҰ��� ����
            if (distanceMap[houseY][houseX] > distance)
                distanceMap[houseY][houseX] = distance;
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (distanceMap[i][j] != 0x7FFFFFFF)
                sum += distanceMap[i][j];

    ans = min(ans, sum);
    return 0;
}