#include <stdio.h>
#pragma warning(disable : 4996) 

int main()
{
	int n1, n2;
	int test;
	int j;
	int gcd;
	scanf("%d", &test);

	for (int i = 0; i < test; i++)
	{
		gcd = 1;
		j = 2;
		scanf("%d %d", &n1, &n2);
		while (n1 != 1 || n2 != 1)
		{
			if (n1 % j == 0 && n2 % j == 0)
			{
				n1 /= j;
				n2 /= j;
				gcd *= j;
			}
			else if (n1 % j == 0 && n2 % j != 0)
			{
				n1 /= j;
				gcd *= j;
			}
			else if (n1 % j != 0 && n2 % j == 0)
			{
				n2 /= j;
				gcd *= j;
			}
			else if (n1 % j != 0 && n2 % j != 0)
			{
				j++;
			}
		}
		printf("%d\n", gcd);
	}
	return 0;
}