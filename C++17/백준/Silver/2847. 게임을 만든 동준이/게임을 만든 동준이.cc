#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nNum = 0;
	std::cin >> nNum;

	std::vector<int> nums(nNum);
	for (int i = 0; i < nNum; ++i) {
		std::cin >> nums[i];
	}

	int answer = 0;
	int lastScore = 20'001;
	for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
		int num = *it;

		// 앞에 값이 뒤에 값보다 작은 경우 그냥 통과
		if (num < lastScore) {
			lastScore = num;
			continue;
		}
		
		// 뒤에 값보다 큰 만큼 값을 내리고 lastScore 갱신
		int sub = num - lastScore + 1;
		answer += sub;

		// 최소한으로 점수를 내리기 때문에 이후 뒤에 값보다 1작은 값이 현재 값
		lastScore -= 1;
	}

	std::cout << answer;
}
