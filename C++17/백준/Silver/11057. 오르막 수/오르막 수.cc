#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int digit;
	cin >> digit;

	vector<array<int, 10>> dp(digit + 1);

	dp[0].fill(1);
	if (digit == 0) {
		cout << "10\n";
		return 0;
	}

	for (int j = 1; j <= digit; ++j) {
		int sum = 0;
		for (int i = 9; i >= 0; --i) {
			sum = ((sum % 100'07) + (dp[j - 1][i] % 100'07)) % 100'07;
			dp[j][i] = sum;
		}
	}
	cout << dp[digit][0];
}