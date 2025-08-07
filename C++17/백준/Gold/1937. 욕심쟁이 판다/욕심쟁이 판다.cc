#include <iostream>
#include <vector>

int32_t n;
std::vector<std::vector<int>> forest;
std::vector<std::vector<int>> maxLength;	// 해당 지점부터 출발해서 먹을 수 있는 대나무 수
std::vector<std::vector<bool>> visit;

constexpr int dy[4] = { -1, 0, 1, 0 };
constexpr int dx[4] = { 0, 1, 0, -1 };

// 해당 지점의 
int32_t DFS(int y, int x) {
	if (maxLength[y][x] != -1) {
		return maxLength[y][x];
	}
	int length = 0;
	for (int i = 0; i < 4; ++i) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (nextY >= n || nextY < 0) continue;
		if (nextX >= n || nextX < 0) continue;
		if (forest[nextY][nextX] <= forest[y][x]) continue;
		int total = DFS(nextY, nextX);
		if (total > length) {
			length = total;
		}
	}
	maxLength[y][x] = length + 1;
	return maxLength[y][x];
}

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;
	forest = std::vector<std::vector<int>>(n, std::vector<int>(n));
	maxLength = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));
	visit = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			std::cin >> forest[y][x];
		}
	}

	int max = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			int total = DFS(y, x);
			if (total > max) {
				max = total;
			}
		}
	}
	std::cout << max;
}
