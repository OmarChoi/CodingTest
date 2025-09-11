#include <iostream>
#include <vector>
using namespace std;

// 자르려는 섬 번호, 해당 섬을 앞에 섬과 자르는데 드는 비용, 연결 벡터
int CalCost(int idx, int cost, vector<bool>& visit, const vector<vector<pair<int, int>>>& connected ) {
	if (visit[idx] == true) {
		return 0;
	}
	visit[idx] = true;

	int total = 0;
	// 아래쪽 연결된 섬을 자르는 비용
	for (const auto& [i, c] : connected[idx]) {
		total += CalCost(i, c, visit, connected);
	}

	// 본인이 제일 마지막 섬인 경우
	if (total == 0) {
		return cost;
	}
	else if (total > cost) {
		return cost;
	}
	else {
		return total;
	}

}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nTestCase = 0;
	cin >> nTestCase;

	while (nTestCase-- > 0) {
		int nIsland, nBridge;
		cin >> nIsland >> nBridge;
		vector<vector<pair<int, int>>> connected(nIsland + 1);
		vector<bool> visit(nIsland + 1);
		for (int i = 0; i < nBridge; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			connected[a].emplace_back(b, c);
			connected[b].emplace_back(a, c);
		}

		int total = 0;
		visit[1] = true;
		// 아래쪽 연결된 섬을 자르는 비용
		for (const auto& [i, c] : connected[1]) {
			total += CalCost(i, c, visit, connected);
		}
		cout << total << "\n";
	}
}
