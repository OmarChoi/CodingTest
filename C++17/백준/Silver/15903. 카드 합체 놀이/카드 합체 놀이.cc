#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nNum = 0;
	int nSum = 0;
	cin >> nNum >> nSum;

	priority_queue<long long, vector<long long>, greater<long long>> nums;
	for (int i = 0; i < nNum; ++i) {
		long long n;
		cin >> n;
		nums.emplace(n);
	}

	while (nSum > 0) {
		nSum -= 1;
		long long x = nums.top();
		nums.pop();
		long long y = nums.top();
		nums.pop();

		nums.emplace(x + y);
		nums.emplace(x + y);
	}

	long long sum = 0;
	while (!nums.empty()) {
		sum += nums.top();
		nums.pop();
	}

	cout << sum;
}