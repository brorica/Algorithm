#include <iostream>
using namespace std;

int bag[1000] = { 0, };
int N, K;
int MAX = 0;
int dp(int n)
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int W = 0, V = 0;
	cin >> N >> K;
	for (auto i = 0; i < K; i++)
	{
		cin >> W >> V;
		bag[W] = V;
	}
	dp(0);
	return 0;
}