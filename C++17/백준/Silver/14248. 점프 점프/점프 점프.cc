#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nStone;
	std::cin >> nStone;
	std::vector<int> move(nStone);
	std::vector<bool> visit(nStone, false);
	for (int i = 0; i < nStone; ++i) {
		std::cin >> move[i];
	}

	std::function<bool(int)> IsValid = [&](int x) {
		return x >= 0 && x < nStone;
	};


	int start;
	std::cin >> start;

	std::queue<int> stones;
	stones.emplace(start - 1);
	visit[start - 1] = true;

	int nVisit = 0;
	while (!stones.empty()) {
		int s = stones.front();
		stones.pop();
		nVisit += 1;

		for (int i = 0; i < 2; ++i) {
			int next = s + (i * 2 - 1) * move[s];
			if (IsValid(next) && visit[next] == false) {
				visit[next] = true;
				stones.emplace(next);
			}
		}
	}

	std::cout << nVisit;
}
