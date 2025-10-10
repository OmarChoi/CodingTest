#include <iostream>
#include <vector>
#include <algorithm>

// node, cost, visited, graph cost
void DFS(int i, std::vector<int>& cost, std::vector<bool>& visit,
	const std::vector<std::vector<std::pair<int, int>>>& graph) {
	// 방문 검사
	if (visit[i] == true) {
		return;
	}
	visit[i] = true;

	// 연결된 노드 비용 업데이트 및 탐색 진행
	for (const auto& [c, d] : graph[i]) {
		if (visit[d] == false) {
			cost[d] = cost[i] + c;
			DFS(d, cost, visit, graph);
		}
	}
}

// maxIndex, maxValue
std::pair<int, int> GetMax(std::vector<int>& cost) {
	int maxIdx = -1;
	int maxValue = 0;

	for (int i = 0; i < cost.size(); ++i) {
		if (cost[i] > maxValue) {
			maxValue = cost[i];
			maxIdx = i;
		}
	}
	return { maxIdx, maxValue };
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	// 1번 노드에서 가장 멀리 있는 노드 탐색
	// 해당 노드에서 가장 멀리 있는 노드까지의 거리가 트리의 지름
	int nNode;
	std::cin >> nNode;
	if (nNode == 1) {
		std::cout << 0 << "\n";
		return 0;
	}

	std::vector<std::vector<std::pair<int, int>>> graph(nNode);
	std::vector<bool> visit(nNode, false);
	std::vector<int> cost(nNode, 0);
	for (int i = 0; i < nNode - 1; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		graph[a - 1].emplace_back(c, b - 1);
		graph[b - 1].emplace_back(c, a - 1);
	}

	// 한 점에서 가장 멀리 있는 노드 탐색
	DFS(0, cost, visit, graph);

	// 위에서 찾은 노드에서 가장 먼 노드까지의 비용 탐색
	int next = GetMax(cost).first;
	std::fill(visit.begin(), visit.end(), false);
	std::fill(cost.begin(), cost.end(), 0);
	DFS(next, cost, visit, graph);

	std::cout << GetMax(cost).second << "\n";
}
