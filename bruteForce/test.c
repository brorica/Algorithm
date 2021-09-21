#include <stdio.h>
#include <limits.h>

int main() {
	printf("\n현재 시스템의 C컴파일러의 데이터 유형의 크기와 값의 범위:\n");

	printf("signed char: ");
	printf("%d byte, 범위: %d ~ %d \n", sizeof("d"), CHAR_MIN, CHAR_MAX);
	return 0;
}
