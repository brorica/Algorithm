#include <stdio.h>
#include <limits.h>

int main() {
	printf("\n���� �ý����� C�����Ϸ��� ������ ������ ũ��� ���� ����:\n");

	printf("signed char: ");
	printf("%d byte, ����: %d ~ %d \n", sizeof("d"), CHAR_MIN, CHAR_MAX);
	return 0;
}
