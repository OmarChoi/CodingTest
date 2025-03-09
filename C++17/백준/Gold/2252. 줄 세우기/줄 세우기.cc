#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nStudent, nCompare;
	cin >> nStudent >> nCompare;
	vector<int> cost(nStudent + 1);
	vector<vector<int>> connect(nStudent + 1);
	for (int i = 0; i < nCompare; ++i) {
		int a, b;
		cin >> a >> b;
		connect[a].emplace_back(b);
		cost[b] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= nStudent; ++i) {
		if (cost[i] == 0)
			q.emplace(i);
	}

	while (!q.empty()) {
		int student = q.front();
		q.pop();
		cout << student << " ";
		for (int other : connect[student]) {
			cost[other] -= 1;
			if (cost[other] == 0)
				q.emplace(other);
		}
	}
}
