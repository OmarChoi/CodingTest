#include <iostream>
#include <vector>

constexpr int32_t MAX = 100;

int32_t GetMax(const std::vector<int32_t>& lVec, const std::vector<int32_t>& rVec, int32_t currRound) {
	int32_t lIdx = 1, rIdx = MAX - 1;
	int32_t nL = lVec[lIdx], nR = rVec[rIdx];	// 중복되는 숫자 처리를 위해 추가
	int32_t nPair = 0;
	int32_t maxValue = 0;

	// 현재 Round가 N일 때, 최대 만들 수 있는 쌍의 개수는 N개
	while (nPair < currRound) {
		if (lIdx >= MAX || rIdx < 0) break;
		while (nL <= 0) {
			// A에 있는 숫자들 중 사용하지 않은 가장 작은 숫자 인덱스
			lIdx += 1;
			if (lIdx < MAX) {
				nL = lVec[lIdx];
			}
		}
		while (nR <= 0) {
			// B에 있는 숫자들 중 사용하지 않은 가장 큰 숫자 인덱스
			rIdx -= 1;
			if (rIdx >= 0) {
				nR = rVec[rIdx];
			}
		}
		int32_t take = std::min(nL, nR);
		maxValue = std::max(maxValue, lIdx + rIdx);

		nL -= take; nR -= take;
		nPair += take;
	}

	return maxValue;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int32_t nRound = 0, currRound = 1;
	std::cin >> nRound;
	std::vector<int32_t> lVec(MAX, 0);
	std::vector<int32_t> rVec(MAX, 0);

	while (currRound <= nRound) {
		int32_t l, r;
		std::cin >> l >> r;
		lVec[l] += 1; rVec[r] += 1;

		std::cout << GetMax(lVec, rVec, currRound) << "\n";
		currRound += 1;
	}
}