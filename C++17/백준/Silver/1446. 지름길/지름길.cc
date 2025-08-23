#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Road {
public:
	int s;
	int e;
	int c;

	bool operator < (const Road& rhs) const {
		return s < rhs.s;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, D;
	cin >> N >> D;
	std::vector<int> dp(D + 1);
	std::vector<Road> road(N);
	std::iota(dp.begin(), dp.end(), 0);
	for (int i = 0; i < N; ++i) {
		cin >> road[i].s >> road[i].e >> road[i].c;
	}

	// 지름길을 시작 지점 기준으로 정렬
	sort(road.begin(), road.end());
	int idx = 0;

	for (int i = 0; i <= D; ++i) {
		// 현재 위치 i에서 시작하는 지름길이 있다면 모두 처리
		while (idx < road.size() && road[idx].s == i) {
			int e = road[idx].e;
			int c = road[idx].c;
			if (e <= D) {
				dp[e] = min(dp[e], dp[i] + c);
			}
			idx += 1;
		}

		if (i + 1 <= D) {
			dp[i + 1] = std::min(dp[i + 1], dp[i] + 1);
		}
	}

	cout << dp[D] << endl;
	return 0;
}
