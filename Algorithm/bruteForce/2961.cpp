#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, K, ans = 0;
vector<int> bits;

int search(int index, int count, int learn);
int calc(int learn);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int learn = 0;
    cin >> N >> K;

    if (K < 5)
    {
        cout << 0;
        return 0;
    }
    K -= 5;

    learn |= (1 << ('a' - 'a'));
    learn |= (1 << ('n' - 'a'));
    learn |= (1 << ('t' - 'a'));
    learn |= (1 << ('i' - 'a'));
    learn |= (1 << ('c' - 'a'));

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        int bit = learn;
        for (int j = 4; j < str.length() - 4; j++)
        {
            int temp = str[j] - 'a';
            bit |= (1 << temp);
        }
        bits.push_back(bit);
    }

    search(0, 0, learn);
    cout << ans;
    return 0;
}

int search(int index, int count, int learn)
{
    if (count >= K)
    {
        calc(learn);
        return 0;
    }
    for (int i = index; i < 26; i++)
    {
        // a, c, i, n, t °Ç³Ê¶Ü
        if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19)
            continue;
        if ((learn & (1 << i)) == 0)
        {
            learn |= (1 << i);
            search(i + 1, count + 1, learn);
            learn ^= (1 << i);
        }
    }
    return 0;
}

int calc(int learn)
{
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        if ((bits[i] & learn) == bits[i])
            ret++;
    }
    ans = max(ans, ret);
    return 0;
}