#include <iostream>
#include <queue>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int start, target;
	std::cin >> start >> target;

    std::queue<std::pair<int, int>> q;
    std::vector<bool> visit(target + 1, false);
    q.emplace(start, 0);
    visit[start] = true;

    while (!q.empty()) {
        auto [n, cnt] = q.front();
        q.pop();

        if (n == target) {
            std::cout << cnt;
            return 0;
        }

        if (n + 1 <= target && !visit[n + 1]) {
            visit[n + 1] = true;
            q.emplace(n + 1, cnt + 1);
        }

        if (n * 2 <= target && !visit[n * 2]) {
            visit[n * 2] = true;
            q.emplace(n * 2, cnt + 1);
        }
    }
}
