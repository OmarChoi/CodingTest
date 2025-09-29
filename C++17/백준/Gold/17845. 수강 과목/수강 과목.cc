#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int N, K;	// 최대 공부시간, 과목 수
	std::cin >> N >> K;

	std::vector<std::pair<int, int>> subjects(K);	// 중요도, 시간
	for (int i = 0; i < K; ++i) {
		std::cin >> subjects[i].first >> subjects[i].second;
	}

	std::vector<int> value(N + 1);

	for (const auto& [v, t] : subjects) {
        // 한 번만 포함될 수 있으니 역순으로 측정
		for (int i = N; i >= t; --i) {
			value[i] = std::max(value[i], value[i - t] + v);
		}
	}

	std::cout << value[N];
}