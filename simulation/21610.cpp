#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 51
#define COMMAND_MAX 101


int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int copyDx[4] = { -1, -1, 1, 1 };
int copyDy[4] = { -1, 1, -1, 1 };

int bag[MAX][MAX] = { 0, };
int copyBag[MAX][MAX] = { 0, };
vector<pair<int, int>> cloud;
int N, M;

int moveCloudAndGiveWater(int d, int s);
int moveCloud(int temp);
int copyWater();
int disappearAndMakeCloud();
int calc();


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int d, s;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> bag[i][j];
	// 초기 구름
	cloud.push_back({ N - 1, 0 });
	cloud.push_back({ N - 1, 1 });
	cloud.push_back({ N - 2, 0 });
	cloud.push_back({ N - 2, 1 });

	for (int i = 0; i < M; i++)
	{
		cin >> d >> s;
		moveCloudAndGiveWater(d - 1, s);
		copyWater();
		disappearAndMakeCloud();
	}
	cout << calc();
	return 0;
}

int moveCloudAndGiveWater(int d, int s)
{
	int xTemp, yTemp;
	for (int i = 0; i < cloud.size(); i++)
	{
		xTemp = cloud[i].second;
		yTemp = cloud[i].first;
		for (int j = 0; j < s; j++)
		{
			xTemp = moveCloud(xTemp + dx[d]);
			yTemp = moveCloud(yTemp + dy[d]);
		}
		cloud[i].second = xTemp;
		cloud[i].first  = yTemp;
		bag[yTemp][xTemp] += 1;
	}
	return 0;
}

int moveCloud(int temp)
{
	if (temp == -1)
		temp = N - 1;
	else if (temp == N)
		temp = 0;
	return temp;
}

int copyWater()
{
	int hereX, hereY;
	int thereX, thereY;
	for (int i = 0; i < cloud.size(); i++)
	{
		hereX = cloud[i].second;
		hereY = cloud[i].first;
		for (int d = 0; d < 4; d++)
		{
			thereX = hereX + copyDx[d];
			thereY = hereY + copyDy[d];
			if (thereX < 0 || thereX >= N || thereY < 0 || thereY >= N)
				continue;
			// 물복사
			if (bag[thereY][thereX] > 0)
				bag[hereY][hereX]++;
		}
	}
	return 0;
}

int disappearAndMakeCloud()
{
	memcpy(copyBag, bag, sizeof(bag));
	// 기존 구름 자리 표시 후 없앰
	for (int i = 0; i < cloud.size(); i++)
		copyBag[cloud[i].first][cloud[i].second] = -1;
	cloud.clear();
	// 새 구름 추가
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (copyBag[i][j] >= 2)
			{
				cloud.push_back({ i, j });
				bag[i][j] -= 2;
			}
		}
	}
	return 0;
}

int calc()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum += bag[i][j];
		}
	}
	return sum;
}