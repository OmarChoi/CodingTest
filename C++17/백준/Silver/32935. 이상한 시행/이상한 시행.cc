#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nNum;
	std::cin >> nNum;

	int64_t sum = 0;
	std::vector<int> nums(nNum);
	for (int i = 0; i < nNum; ++i) {
		std::cin >> nums[i];
		sum += nums[i];
	}

	std::sort(nums.begin(), nums.end());

	for (int i : nums) {
		if (i >= -sum) {
			break;
		}
		int64_t temp = sum;
		sum -= i;
		sum += (-temp);
	}

	std::cout << sum;
}