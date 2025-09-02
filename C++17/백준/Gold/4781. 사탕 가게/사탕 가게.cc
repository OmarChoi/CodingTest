#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		int nCandy;
		float money;
		cin >> nCandy >> money;
		if (nCandy == 0) {
			break;
		}
		int maxMoney = std::lround(money * 100); // 부동소수점 오차 방지를 위해 반올림

		vector<pair<int, int>> candies(nCandy); // 칼로리, 가격 * 100
		for (int i = 0; i < nCandy; ++i) {
			int cal;
			float price;
			cin >> cal >> price;

			candies[i].first = cal;
			candies[i].second = std::lround(price * 100.0f);
		}

		
		vector<int> maxCal(maxMoney + 1); // 해당 비용으로 구할 수 있는 최대 칼로리 
		
		for (const auto& [cal, price] : candies) {
			// 해당 캔디를 구매했을 때, 최대 가격
			for (int i = price; i <= maxMoney; ++i) {
				// 해당 금액으로 더 큰 칼로리를 채울 수 있으면 갱신
				maxCal[i] = std::max(maxCal[i], maxCal[i - price] + cal);
			}
		}
		cout << *maxCal.rbegin() << "\n";
	}
}
