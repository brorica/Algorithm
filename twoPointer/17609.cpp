#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int search(string str, int start, int end, int counter)
{
    int ret1, ret2;
    if (counter == 2)
        return 2;
    while (start < end)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            ret1 = search(str, start, end - 1, counter + 1);
            ret2 = search(str, start + 1, end, counter + 1);
            return min(ret1, ret2);
        }
    }
    if (counter == 1)
        return 1;
    else
        return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << search(str, 0, str.length() - 1, 0) << '\n';
    }
    return 0;
}