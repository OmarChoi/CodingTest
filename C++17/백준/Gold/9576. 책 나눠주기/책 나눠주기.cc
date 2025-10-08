#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

// i 이상에서 남아있는 가장 작은 책
int Find(std::vector<int>& book, int i) {
	while (book[i] != i) {
		book[i] = book[book[i]];
		i = book[i];
	}
	return i;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nTestCase = 0;
	std::cin >> nTestCase;

	while (nTestCase-- > 0) {
		int N, M;
		std::cin >> N >> M;
		std::vector<std::pair<int, int>> req(M);

		for (int i = 0; i < M; ++i) {
			std::cin >> req[i].first >> req[i].second;
		}

		std::sort(req.begin(), req.end(), [](const auto& a, const auto& b) {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second < b.second;
			});

		std::vector<int> book(N + 2, 1);
		std::iota(book.begin(), book.end(), 0);

		int answer = 0;
		for (const auto& [s, e] : req) {
			int b = Find(book, s);
			if (b <= e) {
				// 사용한 책 제거하고 옆에 책 연결
				book[b] = Find(book, b + 1);
				answer += 1;
			}
		}
		std::cout << answer << '\n';
	}
}
