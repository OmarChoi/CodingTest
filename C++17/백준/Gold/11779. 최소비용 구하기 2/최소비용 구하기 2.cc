#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Bus
{
public:
	int endCity;
	int cost;
	Bus(int e, int c) : endCity(e), cost(c) {};
};

class City
{
public:
	int cityIndex;
	int cost = 100'000'001;
	int parent = -1;
	bool operator > (const City& other) const { return cost > other.cost; }

	City() : cityIndex(0), cost(100'000'001), parent(-1) {};
	City(int i, int c, int p = -1) : cityIndex(i), cost(c) {};
	
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int nCity, nBus;
	int startCity, endCity;
	
	std::cin >> nCity >> nBus;

	std::vector<std::vector<Bus>> busInfo(nCity + 1);
	std::vector<City> cityInfo(nCity + 1);
	for (int i = 0; i <= nCity; ++i)
		cityInfo[i].cityIndex = i;
	for (int i = 0; i < nBus; ++i) {
		int sIndex, eIndex, cost;
		std::cin >> sIndex >> eIndex >> cost;
		busInfo[sIndex].emplace_back(eIndex, cost);
	}
	std::cin >> startCity >> endCity;

	std::priority_queue<City, std::vector<City>, std::greater<City>> q;
	cityInfo[startCity].cost = 0;
	q.emplace(startCity, 0);

	while (!q.empty()) {
		City currCity = q.top();
		q.pop();

		if (currCity.cityIndex == endCity)
			break;
		if (cityInfo[currCity.cityIndex].cost < currCity.cost) 
			continue;

		// 현재 도시와 연결된 지역 정보 업데이트
		for (Bus& b : busInfo[currCity.cityIndex]) {
			// 기존 비용보다 새로운 경로의 비용이 싸다면
			int next = b.endCity;
			if (cityInfo[next].cost <= b.cost + currCity.cost) continue;
			// 1. 비용 업데이트
			cityInfo[next].cost = b.cost + currCity.cost;
			// 2. 부모를 CurrCity로 설정
			cityInfo[next].parent = currCity.cityIndex;
			
			q.emplace(next, b.cost + currCity.cost);
		}
	}

	std::stack<int> route;
	route.emplace(endCity);
	while (true) {
		// 부모를 추적하며 한개씩 Stack에 삽입
		int prevCity = cityInfo[route.top()].parent;
		if (prevCity == -1)
			break;
		route.emplace(prevCity);
	}

	std::cout << cityInfo[endCity].cost << "\n" << route.size() << "\n";
	while (!route.empty()) {
		std::cout << route.top() << " ";
		route.pop();
	}
}
