#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int current, target;
	std::cin >> current >> target;

	int nMark;
	std::cin >> nMark;
	std::vector<int> bookMarks(nMark);
	for (int i = 0; i < nMark; ++i) {
		std::cin >> bookMarks[i];
	}
	std::sort(bookMarks.begin(), bookMarks.end());
	auto it = std::lower_bound(bookMarks.begin(), bookMarks.end(), target);

	int dist = 100'000'000'0;
	if (it != bookMarks.end()) {
		dist = std::min(std::abs(*it - target), dist);
	}

	if (it != bookMarks.begin()) {
		dist = std::min(std::abs(*(it - 1) - target), dist);
	}

	int answer = 0;
	answer = (std::abs(target - current) < dist + 1) ? std::abs(target - current) : dist + 1;
	std::cout << answer;
}