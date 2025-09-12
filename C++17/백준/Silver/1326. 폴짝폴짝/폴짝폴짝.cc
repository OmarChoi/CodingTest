#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int FindRoute(int N, int start, int end, const vector<int>& stones) {
	vector<int> dist(N + 1, -1);
	queue<int> q;
	dist[start] = 0;
	q.emplace(start);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (curr == end) {
			return dist[curr];
		}

		// 오른쪽(+) 방향으로 이동
		for (int k = 1;; ++k) {
			int next = curr + stones[curr] * k;
			if (next > N) {
				break;
			}

			if (dist[next] != -1) {
				continue;
			}
			dist[next] = dist[curr] + 1;
			q.emplace(next);
		}

		// 왼쪽(-) 방향으로 이동
		for (int k = 1;; ++k) {
			int next = curr - stones[curr] * k;
			if (next < 1) {
				break;
			}

			if (dist[next] != -1) {
				continue;
			}
			dist[next] = dist[curr] + 1;
			q.emplace(next);
		}
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	cin >> N;
	std::vector<int> stones(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> stones[i];
	}

	int start, end;
	cin >> start >> end;

	cout << FindRoute(N, start, end, stones);
}
