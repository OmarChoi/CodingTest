#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

constexpr int MAX = 200'000'1;

void FindRoute(int start, std::vector<int>& cost,
	const std::vector<std::vector<std::pair<int, int>>>& load) {

	std::priority_queue<std::pair<int64_t, int>, std::vector<std::pair<int64_t, int>>,
		std::greater<std::pair<int64_t, int>>> pq; // cost, index
	
	// 시작위치 설정
	cost[start] = 0;
	pq.emplace(0, start);

	while (!pq.empty()) {
		const auto [currCost, currIdx] = pq.top();
		pq.pop();

		if (currCost > cost[currIdx]) {
			continue;
		}

		for (const auto& [nextCost, nextIdx] : load[currIdx]) {
			int64_t sumCost = nextCost + currCost;
			if (sumCost < cost[nextIdx]) {
				cost[nextIdx] = sumCost;
				pq.emplace(sumCost, nextIdx);
			}
		}
	}
}

void Solution() {
	int n, m, t;	// 교차로, 도로, 목적지 후보의 개수
	std::cin >> n >> m >> t;

	int s, g, h;	// 출발지, g <-> h 교차로는 무조건 포함
	std::cin >> s >> g >> h;

	int gh = 0;
	std::vector<std::vector<std::pair<int, int>>> load(n + 1);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		load[a].emplace_back(c, b);
		load[b].emplace_back(c, a);
		if ((a == g && b == h) || (b == g && a == h)) {
			gh = c;
		}
	}

	// 시작지점에서 모든 지점까지의 거리
	std::vector<int> costFromStart(n + 1, MAX);
	FindRoute(s, costFromStart, load);
	
	// 중간 교차로 G에서 모든 지점까지의 거리
	std::vector<int> costFromG(n + 1, MAX);
	FindRoute(g, costFromG, load);

	// 중간 교차로 H에서 모든 지점까지의 거리
	std::vector<int> costFromH(n + 1, MAX);
	FindRoute(h, costFromH, load);


	std::vector<int> answer;
	answer.reserve(t);

	// s -> g -> h -> 목적지가 s -> 목적지 값과 같은지 확인
	// s -> h -> g -> 목적지가 s -> 목적지 값과 같은지 확인
	for (int i = 0; i < t; ++i) {
		int target;
		std::cin >> target;
		std::vector<int> cost(n + 1);

		int minCost = costFromStart[target];
		if (minCost == MAX) {
			continue;
		}

		// H -> G 순서로 탐색하여 도착한 결과
		int costGH = MAX;
		if (costFromStart[g] != MAX && costFromH[target] != MAX) {
			costGH = costFromStart[g] + costFromH[target] + gh;
		}

		// G -> H 순서로 탐색하여 도착한 결과
		int costHG = MAX;
		if (costFromStart[h] != MAX && costFromG[target] != MAX) {
			costHG = costFromStart[h] + costFromG[target] + gh;
		}
		
		if (costGH == minCost || costHG == minCost) {
			answer.emplace_back(target);
		}
	}

	std::sort(answer.begin(), answer.end());

	for (int i : answer) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int nTestCase = 0;
	std::cin >> nTestCase;

	for (int tc = 0; tc < nTestCase; ++tc) {
		Solution();
	}
}