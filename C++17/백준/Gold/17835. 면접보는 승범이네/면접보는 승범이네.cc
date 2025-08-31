#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int64_t MAX_DIST = 500'000'000'01;

void CalculateDist(int start, vector<int64_t>& dist, const vector<vector<pair<int, int>>>& roads)
{
	priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
	pq.emplace(0, start);	// cost, townIndex
	dist[start] = 0;
	while (!pq.empty()) {
		auto [cost, currTown] = pq.top();
		pq.pop();

		if (cost > dist[currTown]) {
			// 이미 더 낮은 비용으로 처리가 된 경우 스킵
			continue;
		}

		for (const auto& [c, t] : roads[currTown]) {
			if (dist[t] > cost + c) {
				// 기존 비용이 갱신하려는 비용보다 큰 경우에만 갱신
				dist[t] = cost + c;
				pq.emplace(dist[t], t);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nTown, nRoad, nPlace;
	cin >> nTown >> nRoad >> nPlace;
	vector<int> places(nPlace);
	vector<vector<pair<int, int>>> roads(nTown + 1);
	vector<int64_t> dist(nTown + 1, MAX_DIST);

	for (int i = 0; i < nRoad; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		// 면접 장부터 각 도시까지 역추적 하기 위해 반대 방향을 저장
		roads[e].emplace_back(c, s);
	}

	for (int i = 0; i < nPlace; ++i) {
		cin >> places[i];
	}

	// 해당 면접장에서 각 마을까지의 최저 비용 계산
	for (int idx : places) {
		CalculateDist(idx, dist, roads);
	}
	
	int64_t maxValue = 0;
	int maxIndex = 0;
	for (int i = 1; i <= nTown; ++i) {
		if (dist[i] == MAX_DIST) {
			continue;
		}

		if (dist[i] > maxValue) {
			maxValue = dist[i];
			maxIndex = i;
		}
	}

	cout << maxIndex << "\n" << maxValue << "\n";
}
