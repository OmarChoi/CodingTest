#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

class Room;
int N, M;
std::vector<std::vector<bool>> visit;
std::vector<std::vector<Room>> rooms;

class Room
{
public:
	int y, x;
	bool light{ false };
	std::vector<std::pair<int, int>> switches;

	void AddSwitch(int yPos, int xPos) {
		switches.emplace_back(yPos, xPos);
	}

	void turnOnSwitches(std::queue<std::pair<int, int>>&  q, int& answer) {
		for (const auto& s : switches) {
			if (rooms[s.first][s.second].light == true) continue;
			rooms[s.first][s.second].light = true;

			if (visit[s.first][s.second] == true) {
				// 불을 킬 때, 이미 방문한 방이면 해당 방을 큐에 재삽입
				q.emplace(s.first, s.second);
				visit[s.first][s.second] = false;
			}
			answer += 1;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	visit.resize(N, std::vector<bool>(N, false));
	rooms.resize(N, std::vector<Room>(N));
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < N; ++i) {
			rooms[j][i].y = j;
			rooms[j][i].x = i;
		}
	}
	for (int i = 0; i < M; ++i) {
		int y, x, tY, tX;
		cin >> y >> x >> tY >> tX;
		rooms[y - 1][x - 1].AddSwitch(tY - 1, tX - 1);
	}

	std::queue<std::pair<int, int>> q;
	rooms[0][0].light = true;
	q.emplace(0, 0);
	int answer = 1;
	while (!q.empty()) {
		auto r = q.front();
		Room& room = rooms[r.first][r.second];
		q.pop();
		if (visit[room.y][room.x] == true) {
			continue;
		}
		visit[r.first][r.second] = true;

		if (room.light == false) {
			continue;
		}

		room.turnOnSwitches(q, answer);

		for (int i = 0; i < 4; ++i) {
			int nY = room.y + dy[i];
			int nX = room.x + dx[i];
			if (nY < 0 || nY >= N || nX < 0 || nX >= N) continue;
			if (visit[nY][nX] == true) continue;
			q.emplace(nY, nX);
		}
	}
	std::cout << answer << "\n";
}
