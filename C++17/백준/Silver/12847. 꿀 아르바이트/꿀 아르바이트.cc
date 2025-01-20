#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> salary(n);
	vector<long long> salarySum(n);
	cin >> salary[0];
	salarySum[0] = salary[0];

	for (int i = 1; i < n; ++i) {
		cin >> salary[i];
		salarySum[i] = salary[i] + salarySum[i - 1];
	}

	if (m == n) {
		cout << salarySum[n - 1];
		return 0;
	}

	long long maxEarn = salarySum[m - 1];
	for (int i = m; i < n; ++i) {
		if (salarySum[i] - salarySum[i - m] > maxEarn)
			maxEarn = salarySum[i] - salarySum[i - m];
	}
	cout << maxEarn;
}