#include <iostream>
#include <unordered_map>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int sum = 0;
	int maxCount = 0;
	int maxValue = -1;
	std::unordered_map<int, int> numMap;
	for (int i = 0; i < 10; ++i) {
		int num;
		std::cin >> num;

		auto& count = numMap[num];
		count += 1;
		if (count > maxCount) {
			maxCount = count;
			maxValue = num;
		}

		sum += num;
	}

	std::cout << sum / 10 << "\n";
	std::cout << maxValue << "\n";
}
