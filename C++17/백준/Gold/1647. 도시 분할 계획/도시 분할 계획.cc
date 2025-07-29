#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

class Compare
{
public:
	bool operator () (std::tuple<int, int, int>& a, std::tuple<int, int, int>& b) const {
		return std::get<2>(a) > std::get<2>(b);
	}
};

std::vector<int> mainHouse;
int Find(int a) {
	if (a == mainHouse[a])
		return a;

	mainHouse[a] = Find(mainHouse[a]);
	return mainHouse[a];
}

void Union(int a, int b) {
	int aMain = Find(a);
	int bMain = Find(b);

	if (aMain > bMain) {
		mainHouse[aMain] = bMain;
	}
	else if (aMain < bMain) {
		mainHouse[bMain] = aMain;
	}
}

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int nHouse, nRoad;
	std::cin >> nHouse >> nRoad;

	// house01, house02, cost
	std::priority_queue <std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, Compare> pq;
	mainHouse.resize(nHouse + 1);
	for (int i = 1; i <= nHouse; ++i) {
		mainHouse[i] = i;
	}

	for (int i = 0; i < nRoad; ++i) {
		int h1, h2, cost;
		std::cin >> h1 >> h2 >> cost;
		pq.emplace(h1, h2, cost);
	}

	int totalCost = 0;
	int edgeCount = 0;
	while (!pq.empty() && edgeCount < nHouse - 2) {
		auto minRoad = pq.top();
		pq.pop();

		int h1 = std::get<0>(minRoad);
		int h2 = std::get<1>(minRoad);
		int cost = std::get<2>(minRoad);

		if (Find(h1) == Find(h2)) {
			continue;
		}

		Union(h1, h2);
		edgeCount += 1;
		totalCost += cost;
	}
	std::cout << totalCost << "\n";
}
