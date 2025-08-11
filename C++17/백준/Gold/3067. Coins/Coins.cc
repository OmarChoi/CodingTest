#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int32_t nTestCase = 3;
	std::cin >> nTestCase;
	while (nTestCase > 0) {
		nTestCase -= 1;
		int32_t nCoin, target;
		std::cin >> nCoin;

		std::vector<int32_t> coins(nCoin);
		for (int i = 0; i < nCoin; ++i) {
			std::cin >> coins[i];
		}
		std::cin >> target;

		std::vector<int> dp(target + 1, 0);
		dp[0] = 1;

		// 모든 코인에 대해서 해당 코인을 1개 추가하는 경우의 수 측정
		for (int c : coins) {
			for (int i = c; i <= target; ++i) {
				dp[i] += dp[i - c];
			}
		}

		std::cout << dp[target] << "\n";
	}
}
