#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nTestCase = 0;
	cin >> nTestCase;

	while (nTestCase > 0) {
		int target = 0;
		cin >> target;

		vector<int> dp(target + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i < target + 1; ++i) {
			// dp[i - k]에 k을 추가해서 i를 만드는 경우
			dp[i] = (static_cast<long long>(dp[i - 1]) + dp[i - 2] + dp[i - 3]) % 100'000'000'9;
			// dp[i - 1]: 마지막에 1을 더한 경우
			// dp[i - 3]: 마지막에 3을 더한 경우
			// dp[i - 2]: 마지막에 2를 더한 경우
		}
		cout << dp[target] << "\n";
		nTestCase -= 1;
	}
}