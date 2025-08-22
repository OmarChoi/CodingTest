#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Room {
public:
	int y;
	int x;
	int cost;

	Room(int y, int x, int c) : y(y), x(x), cost(c) { };

	bool operator <(const Room& rhs) const {
		return cost > rhs.cost;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	int width, height;
	cin >> width >> height;
	vector<vector<int>> Maze(height, vector<int>(width));
	vector<vector<int>> cost(height, vector<int>(width, width + height - 2));
	cost[0][0] = 0;
	for (int j = 0; j < height; ++j) {
		string str;
		cin >> str;
		for (int i = 0; i < width; ++i) {
			Maze[j][i] = str[i] - '0';
		}
	}

	// 0, 0에서 인접한 4개의 항목에 대해서 pq에 추가하며 진행
	// pq는 해당 칸까지 도달하는데 드는 비용이 작은 순서로 정렬
	priority_queue< Room, vector<Room>, less<Room>> pq;
	pq.emplace(0, 0, 0);

	while (!pq.empty()) {
		Room r = pq.top();
		pq.pop();
		if (r.y == height - 1 && r.x == width - 1) {
			cout << r.cost;
			break;
		}

		int dy[4] = { -1, 0, 1, 0 };
		int dx[4] = { 0, 1, 0, -1 };

		for (int i = 0; i < 4; ++i) {
			int nextY = dy[i] + r.y;
			int nextX = dx[i] + r.x;
			if (nextY < 0 || nextY >= height) continue;
			if (nextX < 0 || nextX >= width) continue;

			// 이미 더 적은 비용으로 해당 칸을 갔으면 추가하지 않는다.
			if (cost[nextY][nextX] <= r.cost + Maze[nextY][nextX]) continue;

			cost[nextY][nextX] = r.cost + Maze[nextY][nextX];
			pq.emplace(nextY, nextX, r.cost + Maze[nextY][nextX]);
		}
	}

	return 0;
}
