#include <iostream>
#include <array>
#include <vector>

constexpr int MaxCount = 20;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nNum;
	std::cin >> nNum;
	std::vector<std::vector<int64_t>> results(nNum, std::vector<int64_t>(MaxCount + 1));
	
	int startNum = 0;
	std::cin >> startNum;
	results[0][startNum] += 1;

	for (int i = 1; i < nNum - 1; ++i) {
		int64_t num = 0;
		std::cin >> num;

		for (int64_t j = 0; j <= MaxCount; ++j) {
			int64_t prevNum = results[i - 1][j];
			if (prevNum != 0) {
				if (j + num <= MaxCount) {
					results[i][j + num] += prevNum;
				}

				if (j - num >= 0) {
					results[i][j - num] += prevNum;
				}
			}
		}
	}

	int32_t target = 0;
	std::cin >> target;
	std::cout << results[nNum - 2][target] << "\n";
}
