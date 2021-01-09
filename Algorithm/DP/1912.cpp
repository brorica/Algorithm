#include <iostream>
#include <algorithm>
using namespace std;

int n;
// 100001 로 바꾸기
int list[1000] = { 0, };
int cache[1000] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> list[i];
	return 0;
}