#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
constexpr int MAX = 100'000'00;
int nNode, nEdge;

void GetRoute(int s, vector<int>& dist, const vector<vector<pair<int, int>>>& routes) {
	// S에서 출발해서 각 지점까지 드는 비용
	vector<bool> visit(nNode + 1);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, s);
	dist[s] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (cost != dist[idx]) {
			continue;
		}

		for (const auto& p : routes[idx]) {
			if (dist[p.second] > cost + p.first) {
				dist[p.second] = cost + p.first;
				pq.emplace(dist[p.second], p.second);
			}
		}
	}
}

void PrintVec(const vector<int>& vec) {
	for (int i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> nNode >> nEdge;
	vector<vector<pair<int, int>>> routes(nNode + 1);	// 도착지점, 비용
	for (int i = 0; i < nEdge; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		routes[s].emplace_back(c, e);
		routes[e].emplace_back(c, s);
	}

	int v1, v2;
	cin >> v1 >> v2;

	vector<int> d1(nNode + 1, MAX);
	GetRoute(1, d1, routes);	// 0번 지점 기준 각 정점까지 가는 비용
	
	vector<int> dv1(nNode + 1, MAX); 
	GetRoute(v1, dv1, routes);	// v1기준 각 정점까지 가는 비용
	
	vector<int> dv2(nNode + 1, MAX); 
	GetRoute(v2, dv2, routes);	// v2기준 각 정점까지 가는 비용

	int cost1 = MAX;
	// 출발점 -> v1 -> v2 -> 도착점 순서로 가는 경우
	if (d1[v1] != MAX && dv1[v2] != MAX && dv2[nNode] != MAX) {
		cost1 = d1[v1] + dv1[v2] + dv2[nNode]; 
	}

	int cost2 = MAX;
	// 출발점 -> v1 -> v2 -> 도착점 순서로 가는 경우
	if (d1[v2] != MAX && dv2[v1] != MAX && dv1[nNode] != MAX) {
		cost2 = d1[v2] + dv2[v1] + dv1[nNode]; 
	}

	int min = std::min(cost1, cost2);
	if (min == MAX) {
		cout << "-1";
	}
	else {
		cout << min;
	}
}
