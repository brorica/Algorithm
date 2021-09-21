#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N1, N2, timer;
	string antGroupA, antGroupB;
	vector<char> ant, symbol;
	cin >> N1 >> N2;
	cin >> antGroupA >> antGroupB;
	for (int i = 0; i < N1; i++)
	{
		ant.push_back(antGroupA[i]);
		symbol.push_back('>');
	}
	reverse(ant.begin(), ant.end());
	for (int i = 0; i < N2; i++)
	{
		ant.push_back(antGroupB[i]);
		symbol.push_back('<');
	}
	cin >> timer;
	for (int i = 0; i < timer;i++)
	{
		for (int j = 0; j < N1 + N2 - 1; j++)
		{
			if (symbol[j] == '>' && symbol[j + 1] == '<')
			{
				swap(symbol[j], symbol[j + 1]);
				swap(ant[j], ant[j + 1]);
				j++;
			}
		}
	}
	int size = ant.size();
	for (int i = 0; i < size; i++)
		cout << ant[i];
	return 0;
}