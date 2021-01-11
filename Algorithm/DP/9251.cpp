#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string A, B;
	int LCS[1024][1024] = { 0, };
	int i, j, temp = 0;
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
	i = Alen - 1;
	j = Blen - 1;
	while (i & j)
	{
		if (A[i] != B[j])
			break;
		else
		{
			Alen--;
			Blen--;
			temp++;
		}
		i--;
		j--;
	}
	if (Alen == 0 || Blen == 0)
		cout << temp;
	else
	{
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
		cout << LCS[i - 1][j - 1] + temp;
	}
	return 0;
}