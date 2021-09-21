#include <stdio.h>
int main()
{
	unsigned int X;
	unsigned int count[1000001];
	unsigned int i;
	scanf("%u", &X);
	count[1] = 0;
	for (i = 2; i <= X; i++)
	{
		// 무조건 1을 빼고 시작한단 가정하에 시작
		count[i] = count[i - 1] + 1;
		// i 이전 수들의 최소 연산값은 있으니 3이나 2로 나눠떨어지는지만 보면 됨
		if (i % 3 == 0)
		{
			if ((count[i / 3] + 1) < count[i])
				count[i] = count[i / 3] + 1;
		}
		if (i % 2 == 0)
		{
			if ((count[i / 2] + 1) < count[i])
				count[i] = count[i / 2] + 1;
		}
	}
	printf("%u\n", count[X]);
	return 0;
}