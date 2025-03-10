#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nObject;
	cin >> nObject;

	vector<int> buildTime(nObject + 1, 0);
	vector<int> cost(nObject + 1, 0);
	vector<vector<int>> connect(nObject + 1);
	for (int i = 1; i <= nObject; ++i) {
		cin >> buildTime[i];
		while (true) {
			int n;
			cin >> n;
			if (n == -1) break;
			connect[n].emplace_back(i);
			cost[i] += 1;
		}
	}

	queue<int> q;
	for (int i = 1; i <= nObject; ++i) {
		if (cost[i] == 0) {
			q.emplace(i);
		}
	}

	vector<int> totalTime(nObject + 1, 0);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i : connect[curr]) {
			cost[i] -= 1;
			if (cost[i] == 0)
				q.emplace(i);
			
			totalTime[i] = max(totalTime[i], totalTime[curr] + buildTime[curr]);
		}
	}

	for (int i = 1; i <= nObject; ++i) {
		cout << totalTime[i] + buildTime[i] << "\n";
	}
}
