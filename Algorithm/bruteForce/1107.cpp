#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, ans;
bool brokenNumberArray[10] = { 0, };

int brokenCheck(int num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int brokenNumber, len = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> brokenNumber;
        brokenNumberArray[brokenNumber] = 1;
    }
    ans = abs(100 - N);
    for (int i = 0; i <= 1000000; i++)
    {
        // 고장난 버튼이 있는지 확인
        int len = brokenCheck(i);
        if (len == 0)
            continue;
        // 숫자 찍은 후 +, - 입력
        len += abs(N - i);
        ans = min(ans, len);

    }
    cout << ans;
    return 0;
}

int brokenCheck(int num)
{
    int ret = 0;
    if (num == 0)
    {
        if (brokenNumberArray[0] == 1)
            return 0;
        else
            return 1;
    }
    while (num)
    {
        int temp = num % 10;
        if (brokenNumberArray[temp] == 1)
            return 0;
        ret++;
        num /= 10;
    }
    return ret;
}
