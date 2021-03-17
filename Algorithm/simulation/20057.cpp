#include <iostream>
using namespace std;
int sandBox[512][512] = { 0, };
int N, ans = 0;
/* 
 * 0 : left  
 * 1 : down  
 * 2 : right  
 * 3 : up
*/
int dx[4][9] = { 
	{1, 1 ,0, 0, 0, 0, -1, -1, -2}, 
	{ 1, -1, 1, -1, 2, -2, 1, -1 ,0 },
	{ -1, -1, 0, 0, 0, 0, 1, 1, 2 }, 
	{ 1, -1, 1, -1, 2, -2, 1, -1, 0 }  
};
int dy[4][9] = { 
	{1, -1 ,1, -1, 2, -2, 1, -1, 0}, 
	{-1, -1, 0, 0, 0, 0, 1, 1, 2},
	{ 1, -1, 1, -1, 2, -2, 1, -1 ,0 }, 
	{ 1, 1, 0, 0, 0, 0 ,-1 ,-1, -2 }  
};
int calc[9] = { 1,1,7,7,2,2,10,10,5 };


int a(int x, int y, int remain)
{
	if (x < 1 || x > N || y < 1 || y > N)
		return remain;
	else
		sandBox[y][x] += remain;
	return 0;
}

int solve(int x, int y, int turn)
{
	int total = sandBox[y][x], remain = 0, temp;
	int thereX, thereY;
	for (int i = 0; i < 9; i++)
	{
		thereX = x + dx[turn][i];
		thereY = y + dy[turn][i];
		temp = (total * calc[i]) / 100;
		// 궤도 이탈
		if (thereX < 1 || thereX > N || thereY < 1 || thereY > N)
			ans += temp;
		else
			sandBox[thereY][thereX] += temp;
		remain += temp;
	}
	sandBox[y][x] = 0;
	remain = total - remain;
	switch (turn)
	{
		case 0: return a(--x, y, remain); break;	// left
		case 1: return a(x, ++y, remain); break;	// down
		case 2: return a(++x, y, remain); break;	// right
		case 3: return a(x, --y, remain); break;	// up
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, x, y;
	int move = 0;		 // 이동할 양
	int moveCount = 0;   // 2로 나눈 나머지가 0이면 move 1 증가
	int turn = 0;		 // 0 : ←, 1 : ↓, 2 : →, 3 : ↑ // 매번 증가
	cin >> N;
	x = (N + 1) / 2; y = (N + 1) / 2;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			cin >> sandBox[i][j];
	while (1)
	{
		if (moveCount % 2 == 0)
			move++;
		for (int i = 1; i <= move; i++)
		{
			switch (turn % 4)
			{
				case 0: x--; ans += solve(x, y, 0); break;	// left
				case 1: y++; ans += solve(x, y, 1); break;  // down
				case 2: x++; ans += solve(x, y, 2); break;	// right
				case 3: y--;  ans += solve(x, y, 3); break;	// up
			}
			if (x == 1 && y == 1)
			{
				cout << ans;
				return 0;
			}
		}
		turn++;
		moveCount++;
	}
	return 0;
}