#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

class Cable
{
public:
	int aTown;
	int bTown;
	int cost;

	Cable(int a, int b, int c) : aTown(a), bTown(b), cost(c) {};

	bool operator < (const Cable& rhs) const {
		return cost > rhs.cost;
	}
};

std::vector<int> mainTown;

int Find(int a) {
	if (mainTown[a] == a) {
		return a;
	}
	return mainTown[a] = Find(mainTown[a]);
}
void Union(int a, int b) {
	int aMain = Find(a);
	int bMain = Find(b);
	if (aMain != bMain) {
		mainTown[aMain] = bMain;
	}
}

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int nTown, nCable, nPower;
	std::cin >> nTown >> nCable >> nPower;
	
    mainTown.resize(nTown + 1);
	std::iota(mainTown.begin(), mainTown.end(), 0);
    
	std::vector<int> powers(nPower);
	int nConnect = nPower;
	std::cin >> powers[0];
	for (int i = 1; i < nPower; ++i) {
		std::cin >> powers[i];
		Union(powers[i - 1], powers[i]);
	}
    
	std::priority_queue<Cable, std::vector<Cable>, std::less<Cable>> cables;
	for (int i = 0; i < nCable; ++i){
		int t1, t2, c;
		std::cin >> t1 >> t2 >> c;
		cables.emplace(t1, t2, c);
	}

	int totalCost = 0;
	while (!cables.empty() && nConnect < nTown) {
		auto curr = cables.top();
		int a = curr.aTown;
		int b = curr.bTown;
		int cost = curr.cost;
		cables.pop();

		if (Find(a) == Find(b)) {
			continue;
		}
		Union(a, b);
		nConnect += 1;
		totalCost += cost;
	}
	std::cout << totalCost << std::endl;
}
