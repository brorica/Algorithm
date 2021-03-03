#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, data;
	int aIndex = 0, bIndex = 0;
	vector<int> A, B;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		A.push_back(data);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> data;
		B.push_back(data);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	A.push_back(0x7FFFFFFF);
	B.push_back(0x7FFFFFFF);
	while (aIndex < N || bIndex < M)
	{
		if (A[aIndex] < B[bIndex])
		{
			cout << A[aIndex] << ' ';
			aIndex++;
		}
		else
		{
			cout << B[bIndex] << ' ';
			bIndex++;
		}
	}
	return 0;
}