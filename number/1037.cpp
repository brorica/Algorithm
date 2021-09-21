#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long N, A;
	vector < unsigned long long > v;
	cin >> N;
	while (N--)
	{
		cin >> A;
		v.push_back(A);
	}
	sort(v.begin(), v.end());
	cout << v[0] * v[v.size() - 1];
	return 0;
}