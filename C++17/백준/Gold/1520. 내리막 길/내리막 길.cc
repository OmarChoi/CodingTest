#include <iostream>
#include <vector>

using namespace std;

int WIDTH, HEIGHT;
vector<vector<int>> map;
vector<vector<int>> route;
int yTrans[4] = { -1, 0, 1, 0 };
int xTrans[4] = { 0, 1, 0, -1 };

bool CanGo(int yPos, int xPos)
{
	if (yPos < 0 || yPos >= HEIGHT) return false;
	if (xPos < 0 || xPos >= WIDTH) return false;
	return true;
}

int DFS(int yPos, int xPos)
{
	if (yPos == HEIGHT - 1 && xPos == WIDTH - 1)
		return 1;
	if (route[yPos][xPos] != -1) 
		return route[yPos][xPos];
	route[yPos][xPos] = 0;

	for (int i = 0; i < 4; ++i)
	{
		int nextYPos = yPos + yTrans[i];
		int nextXPos = xPos + xTrans[i];
		if (CanGo(nextYPos, nextXPos) == false) continue;
		if (map[yPos][xPos] > map[nextYPos][nextXPos])
			route[yPos][xPos] += DFS(nextYPos, nextXPos);
	}
	return route[yPos][xPos];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> HEIGHT >> WIDTH;
	map = vector<vector<int>>(HEIGHT, vector<int>(WIDTH, 0));
	route = vector<vector<int>>(HEIGHT, vector<int>(WIDTH, -1));

	for (int j = 0; j < HEIGHT; ++j)
		for (int i = 0; i < WIDTH; ++i)
			cin >> map[j][i];
	cout << DFS(0, 0);
}