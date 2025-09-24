#include <iostream>
#include <array>
#include <vector>

constexpr int COL = 3;

struct Value {
	int minV = 0;
	int maxV = 0;
};

bool IsValid(int x) {
	if (x < 0 || x >= COL) {
		return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nLine;
	std::cin >> nLine;
	std::vector<std::array<int, COL>> nums(nLine);
	std::array<Value, COL> prev;
	std::array<Value, COL> curr;

	for (int j = 0; j < nLine; ++j) {
		for (int i = 0; i < COL; ++i) {
			std::cin >> nums[j][i];
		}
	}
	
	for (int i = 0; i < COL; ++i) {
		curr[i].minV = curr[i].maxV = nums[0][i];
	}
	
	for (int j = 1; j < nLine; ++j) {
		prev = curr;
		for (int i = 0; i < COL; ++i) {
			int currMin = 900'001;
			int currMax = 0;
			
			// 왼쪽, 그대로, 오른쪽 값 중에 큰 값이랑 나랑 합치기
			for (int k = -1; k <= 1; ++k) {
				int idx = i + k;

				// 해당 인덱스가 유효하면 값 비교
				if (IsValid(idx) == true) {
					currMax = std::max(currMax, prev[idx].maxV);
					currMin = std::min(currMin, prev[idx].minV);
				}
			}

			curr[i].maxV = currMax + nums[j][i];
			curr[i].minV = currMin + nums[j][i];
		}
	}

	std::array<int, 2> answer{ -1, 900'001 };
	for (int i = 0; i < COL; ++i) {
		answer[0] = std::max(answer[0], curr[i].maxV);
		answer[1] = std::min(answer[1], curr[i].minV);
	}

	std::cout << answer[0] << " " << answer[1];
}