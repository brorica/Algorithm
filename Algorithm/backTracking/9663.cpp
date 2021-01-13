#include <iostream>
#include <math.h>
using namespace std;
// 각 라인 퀸의 x좌표 기록
int board[16] = { 0, };
int maxLine, ans = 0;

int queen(int currentLine)
{
	int currentX, beforeLine, flag;
	if (currentLine == maxLine + 1)
		ans += 1;
	else
	{
		// 현재 라인의 x축 탐색
		for (currentX = 1; currentX <= maxLine; currentX++)
		{
			flag = 1;
			board[currentLine] = currentX;
			for (beforeLine = 1; beforeLine < currentLine; beforeLine++)
			{
				// 이전 라인 퀸들과 같은 X 좌표를 가지는지 ||
				// 대각선의 위치에 있는지
				if (board[beforeLine] == board[currentLine] || 
					(abs(board[beforeLine] - board[currentLine]) == currentLine - beforeLine))
				{
					// 있으면 다음 X 좌표 탐색 
					flag = 0;
					break;
				}
			}
			// 없으면 밑에 칸 탐색
			if (flag)
				queen(currentLine + 1);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> maxLine;
	queen(1);
	cout << ans;
	return 0;
}