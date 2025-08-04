#include <iostream>
#include <vector>
#include <algorithm>

class Number
{
public:
	int num;
	int index;
	int parent;
};

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int32_t nNum;
	std::cin >> nNum;
	std::vector<Number> nums(nNum);
	for (int i = 0; i < nNum; ++i) {
		std::cin >> nums[i].num;
		nums[i].index = i;
		nums[i].parent = i;
	}

	std::vector<std::pair<int32_t, int32_t>> lis;
	lis.reserve(nNum);

	for (int i = 0; i < nNum; ++i) {
		// 이분 탐색을 통해 LIS 찾기
		auto it = std::lower_bound(lis.begin(), lis.end(), nums[i].num, [](const auto& p, const int value) {
			return p.first < value;
			});
		int index = it - lis.begin();
		if (index != 0) {
			nums[i].parent = lis[index - 1].second;
		}
		if (it == lis.end()) {
			int num = nums[i].num;
			lis.emplace_back(num, nums[i].index);
		}
		else {
			lis[index] = { nums[i].num, nums[i].index };
		}
	}

	// 맨 뒤에 있는 숫자부터 부모를 추적하며 끝까지 탐색
	int idx = (*lis.rbegin()).second;
	std::cout << lis.size() << "\n";
	std::vector<int> stack;
	stack.reserve(lis.size());
	while (idx != nums[idx].parent) {
		stack.emplace_back(nums[idx].num);
		idx = nums[idx].parent;
	}
	stack.emplace_back(nums[idx].num); // 첫 원소 추가

	for (auto i = stack.rbegin(); i != stack.rend(); ++i) {
		std::cout << *i << " ";
	}
}
