#include <iostream>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int nTestCase;
	std::cin >> nTestCase;

	for (int tc = 0; tc < nTestCase; ++tc) {
		int nCustomer;
		std::cin >> nCustomer;

		std::priority_queue<int> pq;
		for (int i = 0; i < nCustomer; ++i) {
			int n;
			std::cin >> n;
			pq.emplace(n);
		}

		int cnt = 0;
		int64_t sum = 0;
		while (!pq.empty()) {
			int t = pq.top();
			pq.pop();

			// 이미 tip을 받을 수 없는 경우
			if (t <= cnt) {
				continue;
			}

			sum += (t - cnt);
			cnt += 1;
		}

		std::cout << sum << "\n";
	}
}