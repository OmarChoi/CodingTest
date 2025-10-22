#include <iostream>
#include <vector>

struct Meeting
{
	int duration;
	int pay;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int day;
	std::cin >> day;

	std::vector<Meeting> meetings(day + 1);
	for (int i = 1; i <= day; ++i) {
		std::cin >> meetings[i].duration >> meetings[i].pay;
	}

	std::vector<int> cost(day + 1);
	for (int i = 1; i <= day; ++i) {
		auto& [dur, pay] = meetings[i];
		cost[i] = std::max(cost[i], cost[i - 1]);
		if (i + dur - 1 <= day) {
			cost[i + dur - 1] = std::max(cost[i + dur - 1], cost[i - 1] + pay);
		}
	}

	std::cout << cost[day];
}
