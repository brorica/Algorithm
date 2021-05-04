#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int map[32][32] = { 0, };
int dice[8] = { 0, };
int diceClone[8] = { 0, };
int dx[8] = { 1, -1, 0, 0 };
int dy[8] = { 0, 0, -1, 1 };

int diceChange(int direct) {
	memcpy(diceClone, dice, sizeof(dice));
	// À­¸é 0
	// ¹Ø¸é 5
	if (direct == 1) {
		dice[0] = diceClone[4];
		dice[2] = diceClone[0];
		dice[4] = diceClone[5];
		dice[5] = diceClone[2];
	}

	else if (direct == 2) {
		dice[0] = diceClone[2];
		dice[2] = diceClone[5];
		dice[4] = diceClone[0];
		dice[5] = diceClone[4];
	}

	else if (direct == 3) {
		dice[0] = diceClone[1];
		dice[1] = diceClone[5];
		dice[3] = diceClone[0];
		dice[5] = diceClone[3];
	}

	else if (direct == 4) {
		dice[0] = diceClone[3];
		dice[1] = diceClone[0];
		dice[3] = diceClone[5];
		dice[5] = diceClone[1];
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, hereX, hereY, K;
	cin >> N >> M >> hereY >> hereX >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int command;
	int thereX = 0, thereY = 0;
	while (K--)
	{
		cin >> command;
		thereX = hereX + dx[command - 1];
		thereY = hereY + dy[command - 1];
		if (thereX < 0 || thereX >= M || thereY < 0 || thereY >= N)
			continue;
		else
		{
			diceChange(command);
			if (map[thereY][thereX] == 0)
			{
				map[thereY][thereX] = dice[5];
			}
			else
			{
				dice[5] = map[thereY][thereX];
				map[thereY][thereX] = 0;
			}

			hereY = thereY;
			hereX = thereX;
			cout << dice[0] << '\n';
		}
	}
	return 0;
}