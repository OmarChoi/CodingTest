#include <iostream>
#include <vector>

int width, height;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

using namespace std;

bool CanGo(int y, int x) 
{
	if (y < 0 || y >= height) return false;
	if (x < 0 || x >= width) return false;
	return true;
}

int DFS(const vector<vector<char>>& world, vector<vector<bool>>& visit,
	int yPos, int xPos, const char color)
{
	if (visit[yPos][xPos] == true)
		return 0;
	if (world[yPos][xPos] != color)
		return 0;
	visit[yPos][xPos] = true;
	int sum = 1;
	for (int i = 0; i < 4; ++i) 
	{
		int nextY = yPos + dy[i];
		int nextX = xPos + dx[i];
		if (CanGo(nextY, nextX) == false) continue;
		if (visit[nextY][nextX] == true) continue;
		if (world[nextY][nextX] != color) continue;
		sum += DFS(world, visit, nextY, nextX, color);
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> width >> height;
	vector<vector<char>> world(height, vector<char>(width));
	vector<vector<bool>> visit(height, vector<bool>(width));
	for (int j = 0; j < height; ++j) 
		for (int i = 0; i < width; ++i)
			cin >> world[j][i];
	long long whiteSum = 0;
	long long BlackSum = 0;
	for (int j = 0; j < height; ++j)
	{
		for (int i = 0; i < width; ++i)
		{
			if (visit[j][i] == true) continue;
			if (world[j][i] == 'W')
			{
				long long rev = DFS(world, visit, j, i, 'W');
				whiteSum += (rev * rev);
			}
			else
			{
				long long rev = DFS(world, visit, j, i, 'B');
				BlackSum += (rev * rev);
			}
		}
	}
	cout << whiteSum << " " << BlackSum << "\n";
}