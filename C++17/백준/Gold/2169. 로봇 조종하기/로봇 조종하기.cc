#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int Height, Width;
	std::cin >> Height >> Width;

	std::vector<std::vector<int>> value(Height, std::vector<int>(Width));
	std::vector<std::vector<int>> maxValue(Height, std::vector<int>(Width));
	for (int j = 0; j < Height; ++j) {
		for (int i = 0; i < Width; ++i) {
			std::cin >> value[j][i];
		}
	}

	// 첫번째 행은 무조건 오른쪽으로만
	maxValue[0][0] = value[0][0];
	for (int i = 1; i < Width; ++i) {
		maxValue[0][i] = maxValue[0][i - 1] + value[0][i];
	}

	std::vector<int> LtoR(Width, 0);	// 왼쪽 -> 오른쪽 방향으로 계산
	std::vector<int> RtoL(Width, 0);	// 오른쪽 -> 왼쪽 방향으로 계산

	for (int j = 1; j < Height; ++j) {
		// 시작점은 무조건 위에 값 + 자기 자신
		LtoR[0] = maxValue[j - 1][0] + value[j][0];	
		for (int i = 1; i < Width; ++i) {
			// 왼쪽 값과 위에 값 중에 더 큰 값을 기반으로 누적
			LtoR[i] = std::max(LtoR[i - 1], maxValue[j - 1][i]) + value[j][i];
		}

		RtoL[Width - 1] = maxValue[j - 1][Width - 1] + value[j][Width - 1];
		for (int i = Width - 2; i >= 0; --i) {
			// 오른쪽 값과 위에 값 중에 더 큰 값을 기반으로 누적
			RtoL[i] = std::max(RtoL[i + 1], maxValue[j - 1][i]) + value[j][i];
		}

		// 두 결과 중 더 큰 값을 저장
		for (int i = 0; i < Width; ++i) {
			maxValue[j][i] = std::max(LtoR[i], RtoL[i]);
		}
	}

	std::cout << maxValue[Height - 1][Width - 1];
}