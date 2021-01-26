#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000000
vector<int> nArray, mArray, mSort;
int ans[20000001] = { 0, };

int Search(int find)
{
	int left = 0, mid, right;
	right = mSort.size();
	while (left < right)
	{
		mid = (left + right) / 2;
		if (mSort[mid] < find)
			left = mid + 1;
		else if (mSort[mid] > find)
			right = mid;
		else
			return 1;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, i, data;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> data;
		nArray.push_back(data + MAX);
	}
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> data;
		mArray.push_back(data + MAX);
		mSort.push_back(data + MAX);
	}
	sort(mSort.begin(), mSort.end());
	for (i = 0; i < N; i++)
		ans[nArray[i]]+=Search(nArray[i]);
	for (i = 0; i < M; i++)
	{
		cout << ans[mArray[i]] << ' ';
	}
	return 0;
}