#include <iostream>
#include <math.h>
using namespace std;
// �� ���� ���� x��ǥ ���
int board[16] = { 0, };
int maxLine, ans = 0;

int queen(int currentLine)
{
	int currentX, beforeLine, flag;
	if (currentLine == maxLine + 1)
		ans += 1;
	else
	{
		// ���� ������ x�� Ž��
		for (currentX = 1; currentX <= maxLine; currentX++)
		{
			flag = 1;
			board[currentLine] = currentX;
			for (beforeLine = 1; beforeLine < currentLine; beforeLine++)
			{
				// ���� ���� ����� ���� X ��ǥ�� �������� ||
				// �밢���� ��ġ�� �ִ���
				if (board[beforeLine] == board[currentLine] || 
					(abs(board[beforeLine] - board[currentLine]) == currentLine - beforeLine))
				{
					// ������ ���� X ��ǥ Ž�� 
					flag = 0;
					break;
				}
			}
			// ������ �ؿ� ĭ Ž��
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