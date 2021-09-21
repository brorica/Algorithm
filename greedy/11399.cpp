#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int N, i;
	int array[1000];
	int waitTime = 0;
	int totalTime = 0;
	std::cin >> N;
	for (i = 0; i < N; i++)
	{
		std::cin >> array[i];
	}
	std::sort(array, array + N);
	for (i = 0; i < N; i++)
	{
		waitTime = waitTime + array[i];
		totalTime += waitTime;
	}
	std::cout << totalTime;
	return 0;
}