#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int array[1024] = { 0, };
	int N, ans = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> array[i];
	sort(array, array + N);

	for (int i = 0; i < N; i++)
	{
		if (ans < array[i])
			break;
		ans += array[i];
	}
	cout << ans; 
	return 0;
}