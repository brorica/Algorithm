#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, data;
	long long k;
	vector<long long> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> data;
		v.push_back(data);
	}
	sort(v.begin(), v.end());

	long long leftCount = 0, leftV;
	long long rightCount = v.size(), rightV;
	long long maxV = 0;

	for (int i = 0; i < n - 1; i++) {
		leftCount++;
		rightCount--;

		leftV = v[0] * leftCount;
		rightV = v[i + 1] * rightCount;

		if (maxV < leftV + rightV)
			maxV = leftV + rightV;
	}

	long long ans = k / maxV;
	if (k % maxV != 0)
		ans++;
	cout << ans;
}