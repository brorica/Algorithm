#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 20

typedef struct
{
	int y, x;
}Dir;

Dir dir[5] = { {0, -1}, {-1, 0}, {-1, -1}, {0, 1}, {-1, 1} };

int N, M, D, ans = 0, archorLine;
int map[MAX][MAX];
int copyMap[MAX][MAX];
bool visit[MAX][MAX];
vector<int> archor;
vector<Dir> enemy;

int myTurn();
int enemyTurn();
int check();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ret;
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		archor.push_back(i);
		for (int j = i + 1; j < M; j++)
		{
			archor.push_back(j);
			for (int k = j + 1; k < M; k++)
			{
				archor.push_back(k);
				archorLine = N;

				memcpy(copyMap, map, sizeof(copyMap));
				ret = 0;
				while (check())
				{
					ret += myTurn();
					enemyTurn();
				}

				ans = max(ans, ret);
				archor.pop_back();
			}
			archor.pop_back();
		}
		archor.pop_back();
	}
	cout << ans;
	return 0;
}

int myTurn()
{
	int enemyX, enemyY, enemyD, archorX, archorY;
	int attackX = MAX, attackY = MAX, attackD;
	int ret = 0;

	for (int i = 0; i < archor.size(); i++)
	{
		archorY = archorLine;
		archorX = archor[i];
		attackX = MAX;
		attackD = D;

		for (int j = 0; j < enemy.size(); j++)
		{
			enemyX = enemy[j].x;
			enemyY = enemy[j].y;
			enemyD = abs(enemyX - archorX) + abs(enemyY - archorY);

			if (enemyD <= D)
			{
				// ����� ��
				if (enemyD < attackD)
				{
					attackX = enemyX;
					attackY = enemyY;
					attackD = enemyD;
				}
				// ���� ��Ÿ� �� ���� ������
				else if (enemyD == attackD)
				{
					if (enemyX < attackX)
					{
						attackX = enemyX;
						attackY = enemyY;
					}

				}
			}
		}
		if (attackY == MAX && attackX == MAX)
			continue;
		//ó�� ���� ���� ���
		if (copyMap[attackY][attackX] == 1)
			ret++;
		copyMap[attackY][attackX] = -1;
	}
	return ret;
}

int enemyTurn()
{
	// �ü����� ���� �ø�
	memset(copyMap[archorLine - 1], 0, sizeof(copyMap[0]));
	archorLine--;
	return 0;
}


int check()
{
	// ���� �ϳ��� ������ ���� ����
	int flag = 0;
	enemy.clear();
	for (int i = 0; i < archorLine; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (copyMap[i][j] == 1)
			{
				flag = 1;
				enemy.push_back({ i, j });
			}
			else if (copyMap[i][j] == -1)
				copyMap[i][j] = 0;
		}
	}
	return flag;
}