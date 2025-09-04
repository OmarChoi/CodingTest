#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nVertex;
	cin >> nVertex;

	vector<vector<int>> connected(nVertex + 1);
	for (int i = 1; i < nVertex; ++i) {
		int s, e;
		cin >> s >> e;
		connected[s].emplace_back(e);
		connected[e].emplace_back(s);
	}
	
	// 입력된 BFS 방문 순서
	vector<int> answer(nVertex + 1);
	vector<int> seq(nVertex + 1);
	for (int i = 1; i <= nVertex; ++i) {
		cin >> answer[i];
		seq[answer[i]] = i;
	}

	// BFS를 할 때, 주어진 입력 순서에 맞춰서 탐색할 수 있게 설정
	for (int i = 1; i <= nVertex; ++i) {
		sort(connected[i].begin(), connected[i].end(), [&](int a, int b) {
			return seq[a] < seq[b];
			});
	}


	queue<int> q;
	vector<bool> visit(nVertex + 1, false);
	q.push(1);
	visit[1] = true;

	// BFS 탐색 순서에 따른 Vertex 정보를 저장
	vector<int> output(nVertex + 1);
	int outIndex = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (outIndex > nVertex) {
			break;
		}
		output[outIndex++] = curr;
		for (int i : connected[curr]) {
			if (visit[i] != true) {
				visit[i] = true;
				q.emplace(i);
			}
		}
	}

	bool canMake = true;
	// 입력 순서와 탐색 순서가 일치하는지 확인
	for (int i = 1; i <= nVertex; ++i) {
		if (output[i] != answer[i]) {
			canMake = false;
			break;
		}
	}

	cout << canMake;
}
