#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int NArray[41] = { 0, };
int N, C;

int dfs(int start, int end, int sum, vector<int> &v)
{
	if (start == end)
	{
		v.push_back(sum);
		return 0;
	}
	dfs(start + 1, end, sum, v);
	dfs(start + 1, end, sum + NArray[start], v);
	return 0;
}

long long calc(vector<int>& first, vector<int>& second)
{
	int firstIndex = 0, secondIndex = 0;
	int firstSize = first.size();
	int secondSize = second.size();
	long long ans = 0;

	while (firstIndex < firstSize && secondIndex < secondSize)
	{
		int sum = first[firstIndex] + second[secondIndex];
		if (sum == C)
		{
			long long temp1 = 1, temp2 = 1;
			firstIndex++;
			secondIndex++;
			while (firstIndex < firstSize && first[firstIndex - 1] == first[firstIndex])
			{
				temp1++;
				firstIndex++;
			}
			while (secondIndex < secondSize && second[secondIndex - 1] == second[secondIndex])
			{
				temp2++;
				secondIndex++;
			}
			ans += temp1 * temp2;
		}
		else if (sum < C)
			firstIndex++;
		else
			secondIndex++;
	}
	// 둘 다 0 고르는 경우 제외
	if (C == 0)
		ans--;
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> first;
	vector<int> second;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> NArray[i];
	dfs(0, N / 2, 0, first);
	dfs(N / 2, N, 0, second);
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());
	cout << calc(first, second);
	return 0;
}