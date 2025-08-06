#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int nNum = 0;
	std::cin >> nNum;
	std::vector<int> nums(nNum);
	std::vector<int> dp(nNum, 1);
	std::vector<int> prev(nNum, -1);

	for (int i = 0; i < nNum; ++i) {
		std::cin >> nums[i];
	}

	for (int j = 0; j < nNum; ++j) {
		for (int i = j + 1; i < nNum; ++i) {
			if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}

	int maxIdx = max_element(dp.begin(), dp.end()) - dp.begin();
	std::cout << dp[maxIdx] << "\n";
	std::vector<int> route(dp[maxIdx]);
	int idx = dp[maxIdx] - 1;
	while (idx >= 0) {
		route[idx] = nums[maxIdx];
		maxIdx = prev[maxIdx];
		idx -= 1;
	}
	for (int i : route) {
		std::cout << i << " ";
	}
}
