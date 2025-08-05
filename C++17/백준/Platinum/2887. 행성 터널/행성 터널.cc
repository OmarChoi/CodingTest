#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>

class Planet
{
public:
	int index;
	std::array<int, 3> pos;

	int32_t GetDist(Planet& other) {
		int xDist = std::abs(pos[0] - other.pos[0]);
		int yDist = std::abs(pos[1] - other.pos[1]);
		int zDist = std::abs(pos[2] - other.pos[2]);
		return std::min(xDist, std::min(yDist, zDist));
	}
};

class Tunnel
{
public:
	int a;
	int b;
	int cost;

	Tunnel(int x, int y, int c) : a(x), b(y), cost(c) {};
	
	bool operator < (const Tunnel& rhs) const {
		return cost < rhs.cost;
	}
};

std::vector<int> mainPlanet;
int Find(int a) {
	if (mainPlanet[a] == a) {
		return a;
	}
	return mainPlanet[a] = Find(mainPlanet[a]);
}

void Union(int a, int b) {
	int aMain = Find(a);
	int bMain = Find(b);
	if (aMain != bMain) {
		mainPlanet[aMain] = bMain;
	}
}

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int nPlanet;
	std::cin >> nPlanet;
	mainPlanet.resize(nPlanet);
	std::iota(mainPlanet.begin(), mainPlanet.end(), 0);

	std::vector<Planet> planets(nPlanet);
	for (int i = 0; i < nPlanet; ++i) {
		std::cin >> planets[i].pos[0] >> planets[i].pos[1] >> planets[i].pos[2];
		planets[i].index = i;
	}

	std::vector<Tunnel> tunnels;
	for (int i = 0; i < 3; ++i) {
		std::sort(planets.begin(), planets.end(), [i](const Planet& p1, const Planet& p2) {
			return p1.pos[i] < p2.pos[i];
			});
		for (int i = 1; i < nPlanet; ++i) {
			int cost = planets[i].GetDist(planets[i - 1]);
			tunnels.emplace_back(planets[i].index, planets[i - 1].index, cost);
		}
	}

	std::sort(tunnels.begin(), tunnels.end());
	int nConnect = 0;
	int totalCost = 0;
	for (auto& t : tunnels) {
		if (Find(t.a) == Find(t.b)) {
			continue;
		}
		Union(t.a, t.b);
		nConnect += 1;
		totalCost += t.cost;
		if (nConnect == nPlanet - 1) {
			break;
		}
	}
	std::cout << totalCost;
}
