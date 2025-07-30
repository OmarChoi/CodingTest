#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

int Width, Height;
std::vector<int> parent;

const std::pair<int, int> movements[4] = { 
    {-1,0}, // Up
    {0,1},  // Right
    {1,0},  // Down
    {0,-1}  // Left
};

int GetIndex(int yPos, int xPos) {
	return Width * yPos + xPos;
}

bool IsValid(int yPos, int xPos) {
    if (yPos < 0 && yPos >= Height) return false;
    if (xPos < 0 && xPos >= Width) return false;
    return true;
}

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        parent[a] = b;
}

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> Height >> Width;
    parent.resize(Height * Width);
    std::iota(parent.begin(), parent.end(), 0);
    std::vector<std::vector<char>> dir(Height, std::vector<char>(Width));
    for (int j = 0; j < Height; j++) {
        for (int i = 0; i < Width; i++) {
            std::cin >> dir[j][i];
        }
    }

    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            int d;
            switch (dir[y][x]) {
            case 'U': d = 0; break;
            case 'R': d = 1; break;
            case 'D': d = 2; break;
            case 'L': d = 3; break;
            default: continue;
            }
            int ny = y + movements[d].first;
            int nx = x + movements[d].second;
            if (IsValid(ny, nx) == false) continue;
            Union(GetIndex(y, x), GetIndex(ny, nx));
        }
    }

    std::unordered_set<int> roots;
    for (int i = 0; i < parent.size(); ++i) {
        roots.emplace(Find(i));
    }
    std::cout << roots.size();
}
