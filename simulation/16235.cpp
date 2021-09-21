#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

vector<int> trees[16][16];
int land[16][16] = { 0, };
int input[16][16] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	int x, y, age;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> input[i][j];
			land[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> age;
		trees[x][y].push_back(age);
	}
	int hereX, hereY;
	while (K--)
	{
		vector<pair<int, pair<int, int>>> deadTrees;
		vector<pair<int, pair<int, int>>> copyTrees;

		// 봄
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				sort(trees[i][j].begin(), trees[i][j].end());
				for (int k = 0; k < trees[i][j].size(); k++)
				{
					age = trees[i][j][k];
					if (land[i][j] < age)
					{
						deadTrees.push_back({ age / 2, { i, j } });
						trees[i][j].erase(trees[i][j].begin() + k);
						k--;
					}
					else
					{
						land[i][j] -= age;
						trees[i][j][k]++;
						if (trees[i][j][k] % 5 == 0)
							copyTrees.push_back({ 1, {i, j} });
					}

				}
			}
		}

		// 여름
		for (int i = 0; i < deadTrees.size(); i++)
		{
			hereX = deadTrees[i].second.first;
			hereY = deadTrees[i].second.second;
			age = deadTrees[i].first;
			land[hereX][hereY] += age;
		}

		// 가을
		int thereX, thereY;
		for (int i = 0; i < copyTrees.size(); i++)
		{
			hereX = copyTrees[i].second.first;
			hereY = copyTrees[i].second.second;
			age = copyTrees[i].first;
			for (int j = 0; j < 8; j++)
			{
				thereY = hereY + dy[j];
				thereX = hereX + dx[j];
				if (thereY < 1 || thereY > N || thereX < 1 || thereX > N)
					continue;
				trees[thereX][thereY].push_back(age);
			}
		}
		// 겨울
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				land[i][j] += input[i][j];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans += trees[i][j].size();
		}
	}
	cout << ans;
	return 0;
}