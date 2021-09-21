#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100

int r, c, k;
int rCount = 3, cCount = 3;
int arr[MAX][MAX] = { 0, };

int rCalc();
int cCalc();

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = -1;
    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    for (int i = 0; i <= 100; i++)
    {
        if (arr[r - 1][c - 1] == k)
        {
            ans = i;
            break;
        }
        if (cCount >= rCount)
            rCalc();
        else
            cCalc();
    }
    cout << ans;
    return 0;
}
// 가로 방향
int rCalc()
{
    int maxRCount = rCount;
    for (int i = 0; i < cCount; i++)
    {
        map<int, int> v;
        for (int j = 0; j < rCount; j++)
        {
            if (arr[i][j] == 0)
                continue;
            v[arr[i][j]]++;
        }
        memset(arr[i], 0, sizeof(arr[i]));
        vector<pair<int, int>> vec(v.begin(), v.end());
        sort(vec.begin(), vec.end(), cmp);

        if (maxRCount < vec.size() * 2)
            maxRCount = vec.size() * 2;

        for (int vIndex = 0; vIndex < vec.size(); vIndex++)
        {
            arr[i][vIndex * 2] = vec[vIndex].first;
            arr[i][vIndex * 2 + 1] = vec[vIndex].second;
        }
    }
    rCount = maxRCount;
    return 0;
}
// 세로 방향
int cCalc()
{
    int maxCCount = cCount;
    for (int i = 0; i < rCount; i++)
    {
        map<int, int> v;
        for (int j = 0; j < cCount; j++)
        {
            if (arr[j][i] == 0)
                continue;
            v[arr[j][i]]++;
        }
        for (int j = 0; j < cCount; j++)
            arr[j][i] = 0;
        vector<pair<int, int>> vec(v.begin(), v.end());
        sort(vec.begin(), vec.end(), cmp);

        if (maxCCount < vec.size() * 2)
            maxCCount = vec.size() * 2;

        for (int vIndex = 0; vIndex < vec.size(); vIndex++)
        {
            arr[vIndex * 2][i] = vec[vIndex].first;
            arr[vIndex * 2 + 1][i] = vec[vIndex].second;
        }
    }
    cCount = maxCCount;
    return 0;
}