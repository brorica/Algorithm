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
		// ������ 1�� ���� �����Ѵ� �����Ͽ� ����
		count[i] = count[i - 1] + 1;
		// i ���� ������ �ּ� ���갪�� ������ 3�̳� 2�� ���������������� ���� ��
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