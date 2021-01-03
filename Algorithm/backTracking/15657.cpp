#include <iostream>
#include <algorithm>
using namespace std;
int M;
int func(int* array, int* ans, int count)
{
	int i;
	if (count == M)
	{
		for (i = count; *(ans - i) != 0; i--)
			cout << *(ans - i) << ' ';
		cout << '\n';
	}
	else
	{
		for (i = 0; *(array + i) != 0; i++)
		{
			*ans = *(array + i);
			func(array + i, ans + 1, count + 1);
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
	func(array, ans, 0);
	return 0;
}