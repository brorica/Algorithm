#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define nano 10000000 

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, n, data;
    int start, end, sum;
    while (1)
    {
        cin >> x;
        if (cin.eof())
            break;
        vector<int> Lego;
        x *= nano;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> data;
            Lego.push_back(data);
        }
        sort(Lego.begin(), Lego.end());
        start = 0;
        end = n - 1;
        sum = 0;
        while (start < end)
        {
            sum = (Lego[start] + Lego[end]);
            if (sum == x )
            {
                cout << "yes " << Lego[start] << ' ' << Lego[end] << '\n';
                break;
            }
            else if (sum >= x)
                end--;
            else
                start++;
        }
        if (sum != x)
            cout << "danger\n";
    }
    return 0;
}