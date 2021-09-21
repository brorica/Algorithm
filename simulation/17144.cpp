#include <iostream>
#include <cstring>
using namespace std;

int r, c, t;
int room[52][52] = { 0, }, roomTemp[52][52] = { 0, }, cleaner[2];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0, };

int spread()
{
	int avg;
	int thereX, thereY;
	memcpy(roomTemp, room, sizeof(room));
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			if (room[i][j] == -1)
				continue;
			avg = room[i][j] / 5;
			for (int k = 0; k < 4; k++)
			{
				thereX = j + dx[k];
				thereY = i + dy[k];
				if (thereX < 1 || thereX > r || thereY < 1 || thereY > c || room[thereY][thereX] == -1)
					continue;
				roomTemp[i][j] -= avg;
				roomTemp[thereY][thereX] += avg;
			}
		}
	}
	memcpy(room, roomTemp, sizeof(room));
	return 0;
}

int topMove()
{
	int top = cleaner[0];
	int prevTemp, currentTemp;
	prevTemp = room[top][2];
	room[top][2] = 0;
	for (int i = 2 + 1; i <= r; i++)
	{
		currentTemp = room[top][i];
		room[top][i] = prevTemp;
		prevTemp = currentTemp;
	}
	for (int i = top - 1; i >= 1; i--)
	{
		currentTemp = room[i][r];
		room[i][r] = prevTemp;
		prevTemp = currentTemp;
	}
	for (int i = r - 1; i >= 1; i--)
	{
		currentTemp = room[1][i];
		room[1][i] = prevTemp;
		prevTemp = currentTemp;
	}
	for (int i = 1 + 1; i < top; i++)
	{
		currentTemp = room[i][1];
		room[i][1] = prevTemp;
		prevTemp = currentTemp;
	}
	return 0;
}

int bottomMove()
{
	int bottom = cleaner[1];
	int prevTemp, currentTemp;
	prevTemp = room[bottom][2];
	room[bottom][2] = 0;
	for (int i = 2 + 1; i <= r; i++)
	{
		currentTemp = room[bottom][i];
		room[bottom][i] = prevTemp;
		prevTemp = currentTemp;
	}
	for (int i = bottom + 1; i <= c; i++)
	{
		currentTemp = room[i][r];
		room[i][r] = prevTemp;
		prevTemp = currentTemp;
	}
	for (int i = r - 1; i >= 1; i--)
	{
		currentTemp = room[c][i];
		room[c][i] = prevTemp;
		prevTemp = currentTemp;
	}
	for (int i = c - 1; i > bottom; i--)
	{
		currentTemp = room[i][1];
		room[i][1] = prevTemp;
		prevTemp = currentTemp;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cleanerIndex = 0;

	cin >> c >> r >> t;
	// r : За c : ї­
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == -1)
				cleaner[cleanerIndex++] = i;
		}
	}
	while (t--)
	{
		spread();
		topMove();
		bottomMove();
	}
	int ans = 0;
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= r; j++)
		{
			if (room[i][j] != -1)
				ans += room[i][j];
		}
	}
	cout << ans;
	return 0;
}
