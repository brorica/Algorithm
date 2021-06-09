#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
long ans = 0;
vector<int> v;
int alphabetCount[32];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        int temp = 1;
        for (int j = str.length() - 1; j >= 0; j--)
        {
            alphabetCount[str[j] - 'A'] += temp;
            temp *= 10;
        }
    }
    for (int i = 0; i < 27; i++)
    {
        if (alphabetCount[i] != 0)
            v.push_back(alphabetCount[i]);
    }
    sort(v.begin(), v.end());

    int value = 9;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        ans += v[i] * value;
        value--;
    }
    cout << ans;
    return 0;
}
