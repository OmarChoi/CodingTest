#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nStation;
	std::cin >> nStation;
	
	std::vector<int> loads(nStation - 1);
	for (int& i : loads) {
		std::cin >> i;
	}

	std::vector<int> stations(nStation);
	for (int& i : stations) {
		std::cin >> i;
	}

	// 왼쪽부터 하나씩 탐색하며 가장 낮은 가격으로 다음 거리만큼 결제
	int64_t minCost = 100'000'000'0;
	int64_t totalCost = 0;

	for (int i = 0; i < nStation - 1; ++i) {
		int64_t cost = stations[i];		    // 이번 주유소 가격
        // 지금까지 나온 주유소 중에 최저가로 다음 경로만큼 결제
		if (cost < minCost) {	            
			totalCost += (cost * loads[i]);
			minCost = cost;
		}
		else {
			totalCost += (minCost * loads[i]);
		}
	}
	std::cout << totalCost << std::endl;
}
