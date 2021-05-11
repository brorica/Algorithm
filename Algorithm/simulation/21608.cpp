#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int seat[21][21] = { 0, };
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int studentPick[512][5] = { 0, };

int N, NN;
int retX, retY, retFavorite;

int findBlankSeat(int student)
{
	int thereX = 0, thereY = 0, favorite, blank, maxBlank = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			favorite = 0;
			blank = 0;
			// ���ڸ� Ȯ��
			if (seat[i][j])
				continue;
			
			for (int k = 0; k < 4; k++)
			{
				thereX = j + dx[k];
				thereY = i + dy[k];
				// ��ȿ�� ��ġ���� Ȯ��
				if (thereX < 0 || thereX >= N || thereY < 0 || thereY >= N)
					continue;
				// �ֺ� ��ĭ ��
				if (seat[thereY][thereX] == 0)
				{
					blank++;
					continue;
				}
				// �����ϴ� �л� �󸶳� �ִ��� Ȯ��
				for (int s = 1; s <= 4; s++)
				{
					if (seat[thereY][thereX] == studentPick[student][s])
						favorite++;
				}

			}
			// ������ �࿭ ���� �� �������� �ؼ� ���� �˻�� �� �ص� �ɵ�
			if (favorite >= retFavorite)
			{
				if (favorite == retFavorite)
				{
					if (maxBlank >= blank)
						continue;
				}
				retFavorite = favorite;
				maxBlank = blank;
				retX = j;
				retY = i;
			}
		}
	}
	return 0;
}

int calc(int y, int x)
{
	int thereY, thereX, count = 0, student;

	for (int i = 0; i < NN; i++)
	{
		if (studentPick[i][0] == seat[y][x])
		{
			student = i;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		thereY = y + dy[i];
		thereX = x + dx[i];
		if (thereX < 0 || thereX >= N || thereY < 0 || thereY >= N)
			continue;
		// �����ϴ� �л� �󸶳� �ִ��� Ȯ��
		for (int s = 1; s <= 4; s++)
		{
			if (seat[thereY][thereX] == studentPick[student][s])
				count++;
		}
	}
	if (count == 1)
		return 1;
	else if (count == 2)
		return 10;
	else if (count == 3)
		return 100;
	else if (count == 4)
		return 1000;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	cin >> N;
	NN = N * N;
	for (int i = 0; i < NN; i++)
		for (int j = 0; j < 5; j++)
			cin >> studentPick[i][j];
	// ó�� �ɴ� �ڸ�
	for (int i = 0; i < NN; i++)
	{
		retFavorite = -1;
		findBlankSeat(i);
		seat[retY][retX] = studentPick[i][0];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ans += calc(i, j);
		}
	}
	cout << ans;
	return 0;
}