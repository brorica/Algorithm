#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 4000001 로 바꾸기
#define max 4000001
int F[max] = { 0, };
string T, P;
int failure(int n)
{
	int j = 0;
	for (auto i = 1; i < n; i++)
	{
		while (P[i] != P[j])
		{
			if (j == 0)
				break;
			j = F[j - 1];
		}
		if (P[i] == P[j])
		{
			j += 1;
			F[i] = j;
		}
	}
	return 0;
}
// A B C D A B D
// 0 0 0 0 1 2 0
int kmp(int Tlen, int Plen)
{
	int j = 0;
	int count = 0;
	vector<int> position;
	for (auto i = 0; i < Tlen; i++)
	{
		while (T[i] != P[j])
		{
			if (j == 0)
				break;
			j = F[j - 1];
		}
		if (T[i] == P[j])
		{
			j += 1;
			if (j == Plen)
			{
				count++;
				position.push_back(i - Plen + 2);
			}
		}
	}
	cout << count << '\n';
	for (auto i = 0; i < position.size(); i++)
		cout << position[i] << ' ';
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Tlen, Plen;
	vector<int> ans;
	getline(cin, T);
	getline(cin, P);
	Tlen = T.length();
	Plen = P.length();
	failure(Plen);
	kmp(Tlen, Plen);
	return 0;
}