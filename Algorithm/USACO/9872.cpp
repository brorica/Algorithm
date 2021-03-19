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
	string list[1024];
	int T, count, MAX = -1;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string name[3];
		for (int i = 0; i < 3; i++)
			cin >> name[i];
		sort(name, name + 3);
		list[i] = name[0] + name[1] + name[2];
	}
	sort(list, list + T);
	count = 1;
	for (int i = 0; i < T; i++, count++)
	{
		if (list[i] != list[i + 1])
		{
			if (MAX < count)
				MAX = count;
			count = 0;
		}
	}
	cout << MAX;
	return 0;
}