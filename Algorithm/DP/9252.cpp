#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string A, B, ans;
	int LCS[1024][1024] = { 0, };
	int i, j;
	int Alen, Blen;

	cin >> A >> B;
	A = '0' + A;
	B = '0' + B;
	Alen = A.length();
	Blen = B.length();
	if (Blen > Alen)
	{
		swap(A, B);
		swap(Alen, Blen);
	}
	for (i = 1; i < Alen; i++)
	{
		for (j = 1; j < Blen; j++)
		{
			if (A[i] == B[j])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
	cout << LCS[i - 1][j - 1] << '\n';
	Alen--;
	Blen--;
	while (LCS[Alen][Blen] != 0)
	{
		if (LCS[Alen][Blen] == LCS[Alen][Blen - 1]) //¿ÞÂÊ ºñ±³
			Blen--;
		else if (LCS[Alen][Blen] == LCS[Alen - 1][Blen]) //À­ÂÊ ºñ±³
			Alen--;
		else if (LCS[Alen][Blen] - 1 == LCS[Alen - 1][Blen - 1]) {
			ans.push_back(A[Alen]);
			Alen--;
			Blen--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}