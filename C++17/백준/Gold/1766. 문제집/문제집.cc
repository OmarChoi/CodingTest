#include <iostream>
#include <queue>
#include <vector>

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, nRel;
	std::cin >> n >> nRel;
	std::vector<int> seq(n + 1);
	seq[0] = -1;
	std::vector<std::vector<int>> rel(n + 1);
	for (int i = 0; i < nRel; ++i) {
		int a, b;
		std::cin >> a >> b;
		rel[a].emplace_back(b);
		seq[b] += 1;
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] == 0) {
			pq.emplace(i);
		}
	}

	while (!pq.empty()) {
		int i = pq.top();
		pq.pop();
        std::cout << i << " ";
		for (int j : rel[i]) {
			seq[j] -= 1;
			if (seq[j] == 0) {
				pq.emplace(j);
			}
		}
	}
}
