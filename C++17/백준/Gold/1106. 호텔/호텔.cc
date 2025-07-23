#include <iostream>
#include <vector>

using namespace std;
#define INF 210'000'000'0

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nTarget, nTown;
	cin >> nTarget >> nTown;
	vector<pair<int, int>> marketing(nTown);
	for (int i = 0; i < nTown; ++i) {
		int cost, customer;
		cin >> cost >> customer;
		marketing[i] = { cost, customer };
	}

	vector<int> dp(nTarget + 1, INF);	// 손님 i만큼 늘리는데 드는 비용
	dp[0] = 0;
	for (int j = 0; j < nTown; ++j) {
		// 0 ~ j번째 Town만 계산했을 때, 늘어난 고객 수에 따른 최소 비용
		int cost = marketing[j].first;
		int customer = marketing[j].second;
		for (int i = 0; i < nTarget; ++i) {
			if (dp[i] == INF) continue;
			int nxt = min(nTarget, i + customer);
			dp[nxt] = min(dp[nxt], dp[i] + cost);
		}
	}
	cout << dp[nTarget];
}
