#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, N, d, k, c, data;
    int start = 0, temp = 0, MAX = 0;
    int check[3001] = { 0, };
    vector<int> chobab;
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        chobab.push_back(data);
    }
    for (i = 0; i < k; i++)
    {
        if (check[chobab[i]] == 0)
            temp++;
        check[chobab[i]]++;
    }
    for (i; i <= N + k; i++)
    {
        if (check[chobab[start % N]] == 1)
            temp--;
        check[chobab[start % N]]--;

        if (check[chobab[i % N]] == 0)
            temp++;
        check[chobab[i % N]]++;

        if (check[c] == 0)
        {
            check[c]++;
            temp++;
        }
        if (temp > MAX)
            MAX = temp;
        start++;
    }
    cout << MAX;
    return 0;
}
