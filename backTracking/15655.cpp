#include <iostream>
#include <algorithm>
using namespace std;
int M;
int func(int* array, int* ans, int count)
{
	int i = 0, j;
	if (count == 0)
	{
		for (i = M; *(ans - i) != 0; i--)
			cout << *(ans - i) << ' ';
		cout << '\n';
	}
	else
	{
		while (*(array+i) != 0)
		{
			*ans = *(array + i);
			i++;
			func(array + i, ans + 1, count - 1);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int array[16] = { 0, };
	int ans[16] = { 0, };
	cin >> N >> M;
	for (auto i = 0; i < N; i++)
		cin >> array[i];
	sort(array, array + N);
	func(array, ans, M);
	return 0;
}