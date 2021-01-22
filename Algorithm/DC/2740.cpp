#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int A[101][101] = { 0, };
	int B[101][101] = { 0, };
	int N, M, K;
	int i, j, k, temp;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> A[i][j];
	cin >> M >> K;
	for (i = 0; i < M; i++)
		for (j = 0; j < K; j++)
			cin >> B[i][j];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < K; j++)
		{
			temp = 0;
			for (k = 0; k < M; k++)
			{
				temp += A[i][k] * B[k][j];
			}
			cout << temp << ' ';
		}
		cout << '\n';
	}
	return 0;
}