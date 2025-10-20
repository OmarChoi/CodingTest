#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nCarriage;
	std::cin >> nCarriage;

	std::vector<int> customers(nCarriage + 1);
	for (int i = 1; i <= nCarriage; ++i) {
		std::cin >> customers[i];
	}

	int nCanCarry;
	std::cin >> nCanCarry;
	
	std::vector<int> prefixSum(nCarriage + 1);
	for (int i = 1; i <= nCarriage; ++i) {
		prefixSum[i] = prefixSum[i - 1] + customers[i];
	}

	// i번쨰 객차까지 j개의 기관차를 이용해서 옮길 수 있는 최대 승객 수
	std::vector<std::vector<int>> dp(nCarriage + 1, std::vector<int>(4, 0));

	// j - 1개의 기관차로 옮길 수 있는 수 + i - nCanCarry ~ i 구간에 새로운 객차 배정하는 경우와
	// j개의 기관차로 i - 1번 객차까지 옮기는 최댓값 비교
	for (int j = 1; j <= 3; j++) {
		// j개의 기관차를 놓을 수 있는 최소 객차 수부터 탐색
		for (int i = nCanCarry * j; i <= nCarriage; i++) {
			dp[i][j] = std::max(dp[i - 1][j],
				dp[i - nCanCarry][j - 1] + (prefixSum[i] - prefixSum[i - nCanCarry]));
		}
	}

	std::cout << dp[nCarriage][3] << "\n";
}