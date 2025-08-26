#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
constexpr int MAX = 100'000'000;
int nNode, nEdge, dest;

void CalculateDist(int start, vector<int>& dist, const vector<vector<pair<int, int>>>& route) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, start);
	dist[start] = 0;
	while (!pq.empty()) {
		auto [cost, curr] = pq.top();
		pq.pop();

		if (cost > dist[curr]) {
			continue;
		}

		for (const auto& [c, v] : route[curr]) {
			if (dist[v] > cost + c) {
				dist[v] = cost + c;
				pq.emplace(dist[v], v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> nNode >> nEdge >> dest;
	vector<vector<pair<int, int>>> routes(nNode + 1);	// i에서 출발했을 때, 각 지점까지의 최단 경로
	vector<vector<int>> dist(nNode + 1, vector<int>(nNode + 1, MAX));
	for (int i = 0; i < nEdge; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		routes[s].emplace_back(c, e);
	}

	// 모든 정점에서 다른 정점까지의 최단거리 계산하기
	for (int i = 1; i <= nNode; ++i) {
		CalculateDist(i, dist[i], routes);
	}

	// 각 마을 -> 파티장 -> 각 마을 이동 거리를 계산해서 최댓값 저장
	int max = 0;
	for (int i = 1; i <= nNode; ++i) {
		if (i == dest) {
			continue;
		}

		int cost = dist[i][dest] + dist[dest][i];
		if (cost > max) {
			max = cost;
		}
	}

	cout << max;
}
