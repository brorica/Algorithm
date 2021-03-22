#include <iostream>
#include <algorithm>
using namespace std;

// 0 : ºÏ, 1 : ³², 2 : ¼­, 3 : µ¿
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
// left [0] right : [1]
int status[4][2] = { { 2, 3 }, { 3, 2 }, { 1, 0 }, { 0, 1 } };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		string command;
		int commandLen;
		int x = 0, y = 0;
		int dirX = 0, dirY = 1, dir = 0;
		int maxX = 0, minX = 0, maxY = 0, minY = 0;
		cin >> command;
		commandLen = command.length();
		for (int i = 0; i < commandLen; i++)
		{
			if (command[i] == 'F')
			{
				x += dirX;
				y += dirY;
			}
			else if (command[i] == 'B')
			{
				x -= dirX;
				y -= dirY;
			}
			else
			{
				if (command[i] == 'L')
				{
					dir = status[dir][0];
					dirX = dx[dir];
					dirY = dy[dir];
				}
				else if (command[i] == 'R')
				{
					dir = status[dir][1];
					dirX = dx[dir];
					dirY = dy[dir];
				}
			}
			maxX = max(maxX, x);
			maxY = max(maxY, y);
			minX = min(minX, x);
			minY = min(minY, y);


		}
		int ans = (maxX - minX) * (maxY - minY);
		cout << ans << '\n';

	}

	return 0;
}