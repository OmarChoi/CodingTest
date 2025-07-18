#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int curr, const vector<vector<int>>& rel, vector<bool>& visit) {
	visit[curr] = true;
	int count = 1; // 자기 자신 포함
	for (int next : rel[curr]) {
		if (!visit[next]) {
			count += DFS(next, rel, visit);
		}
	}
	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nBall, nRel;
	cin >> nBall >> nRel;
	vector<vector<int>> hRelations(nBall + 1);
	vector<vector<int>> lRelations(nBall + 1);
	vector<bool> visit(nBall + 1);

	for (int i = 0; i < nRel; ++i) {
		int heavy, light;
		cin >> heavy >> light;
		hRelations[light].emplace_back(heavy);
		lRelations[heavy].emplace_back(light);
	}

	int mid = (nBall + 1) / 2;
	int answer = 0;
	for (int i = 1; i <= nBall; ++i) {
		fill(visit.begin(), visit.end(), false);
		int heavyCount = DFS(i, hRelations, visit) - 1;

		fill(visit.begin(), visit.end(), false);
		int lightCount = DFS(i, lRelations, visit) - 1;

		if (heavyCount >= mid || lightCount >= mid) {
			answer += 1;
		}
	}

	cout << answer;
}
