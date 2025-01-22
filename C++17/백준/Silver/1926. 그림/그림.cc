#include <iostream>
#include <vector>

using namespace std;

int height, width;
int dy[4]{ -1, 0, 1, 0 };
int dx[4]{ 0, 1, 0, -1 };

bool IsValid(int y, int x) {
	if (y >= height || y < 0) return false;
	if (x >= width || x < 0) return false;
	return true;
}

void DFS(const vector<vector<int>>& paper, vector<vector<bool>>& visit,
	int yPos, int xPos, int& size) {
	if (paper[yPos][xPos] == 0) return;
	if (visit[yPos][xPos] == true)
		return;
	size += 1;
	visit[yPos][xPos] = true;

	for (int i = 0; i < 4; ++i) {
		int nextY = yPos + dy[i];
		int nextX = xPos + dx[i];
		if (IsValid(nextY, nextX) == false) continue;
		if (paper[nextY][nextX] == 0) continue;
		if (visit[nextY][nextX] == true) continue;
		DFS(paper, visit, nextY, nextX, size);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> height >> width;
	vector<vector<int>> paper(height, vector<int>(width, 0));
	vector<vector<bool>> visit(height, vector<bool>(width, false));

	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			cin >> paper[j][i];
		}
	}

	int maxSize = -1;
	int nImage = 0;
	for (int j = 0; j < height; ++j) {
		for (int i = 0; i < width; ++i) {
			int size = 0;
			if (visit[j][i] == true) continue;
			DFS(paper, visit, j, i, size);
			if (size > 0) nImage += 1;
			maxSize = max(size, maxSize);
		}
	}
	cout << nImage  << "\n" << maxSize;
}