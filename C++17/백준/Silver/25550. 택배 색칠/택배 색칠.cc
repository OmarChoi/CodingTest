#include <iostream>
#include <vector>

constexpr int dy[4] = { -1, 0, 1, 0, };
constexpr int dx[4] = { 0, 1, 0, -1 };

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);


	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> h(N + 2, std::vector<int>(M + 2, 0));
	for (int j = 1; j <= N; ++j) {
		for (int i = 1; i <= M; ++i) {
			std::cin >> h[j][i];
		}
	}

	// 4면에서 가릴 수 있는 블록 개수 확인
	int64_t answer = 0;
	for (int j = 1; j <= N; ++j) {
		for (int i = 1; i <= M; ++i) {
			int height = h[j][i];
			if (height <= 0) {
				continue;
			}

			int low = 100'000'000'1;
			for (int d = 0; d < 4; ++d) {
				int near = h[j + dy[d]][i + dx[d]];
				if (near < low) {
					low = near;
				}
			}

			answer += std::min(low, height - 1);
		}
	}

	std::cout << answer;
}
