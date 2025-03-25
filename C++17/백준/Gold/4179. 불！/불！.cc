#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
int WIDTH, HEIGHT;
vector<vector<char>> maze;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool CanGo(int yPos, int xPos) {
	// 사람 또는 불이 이동할 수 있는지 확인하는 함수
	if (yPos < 0 || yPos >= HEIGHT) return false;
	if (xPos < 0 || xPos >= WIDTH) return false;
	if (maze[yPos][xPos] == '#') return false;
	return true;
}

bool CheckEscape(int yPos, int xPos) {
	if (yPos == 0 || yPos == HEIGHT - 1) return true;
	if (xPos == 0 || xPos == WIDTH - 1) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> HEIGHT >> WIDTH;
	maze = vector<vector<char>>(HEIGHT, vector<char>(WIDTH));
	vector<vector<bool>> visit(HEIGHT, vector<bool>(WIDTH, false));

	queue<pair<int, int>> q;
	queue<pair<int, int>> f;

	pair<int, int> startPos;
	for (int j = 0; j < HEIGHT; ++j) {
		for (int i = 0; i < WIDTH; ++i) {
			cin >> maze[j][i];
			if (maze[j][i] == 'J') {
				q.emplace(make_pair(j, i));
				visit[j][i] = true;
				if (CheckEscape(j, i)) {
				    cout << 1 << "\n";
				    return 0;
				}
			}
			else if(maze[j][i] == 'F') {
				f.emplace(make_pair(j, i));
			}
		}
	}

	int count = 1;
	while (!q.empty() || !f.empty()) {
		int nFire = f.size();
		for(int j = 0; j < nFire; ++j) {
			pair<int, int> curr = f.front();
			f.pop();
			for (int i = 0; i < 4; ++i) {
				int nextY = curr.first + dy[i];
				int nextX = curr.second + dx[i];
				if (CanGo(nextY, nextX) == false) continue;
				if (maze[nextY][nextX] == 'F') continue;
				f.emplace(make_pair(nextY, nextX));
				maze[nextY][nextX] = 'F';
			}
		}

		int nRoute = q.size();
		for (int j = 0; j < nRoute; ++j) {
			pair<int, int> curr = q.front();
			q.pop();

			if (CheckEscape(curr.first, curr.second)) {
				cout << count << "\n";
				return 0;
			}

			for (int i = 0; i < 4; ++i) {
				int nextY = curr.first + dy[i];
				int nextX = curr.second + dx[i];
				if (CanGo(nextY, nextX) == false) continue;
				if (visit[nextY][nextX] == true) continue;
				if (maze[nextY][nextX] == 'F') continue;
				visit[nextY][nextX] = true;
				q.emplace(make_pair(nextY, nextX));
			}
		}
		count += 1;
	}
	cout << "IMPOSSIBLE\n";
}
