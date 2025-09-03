#include <iostream>
#include <vector>

using namespace std;

int nTown;

int FindRoute(const std::vector<std::vector<int>>& dist, 
              std::vector<std::vector<bool>>& connected ) {
	for (int k = 0; k < nTown; ++k) {
		for (int j = 0; j < nTown; ++j) {
			if (j == k) {
				continue;
			}

			for (int i = 0; i < nTown; ++i) {
				if (i == k || i == j) {
					continue;
				}

				int cost = dist[j][k] + dist[k][i];
				
				// 만약 해당 경로로 가는 최소 비용이 K를 경유해서 가는 비용보다 크면 오류
				if (dist[j][i] > cost) {
					return 0;
				}

				// j -> i 의 최단 경로가 K를 경유해야 하면 J -> I인 통로는 제거
				if (dist[j][i] == cost) {
					connected[i][j] = connected[j][i] = false;
				}
			}
		}
	}
	return 1;
}

int CountRoad(const std::vector<std::vector<int>>& dist, 
              const std::vector<std::vector<bool>>& connected) {
    // 유효한 도로의 합
	int answer = 0;
	for (int j = 0; j < nTown; ++j) {
		for (int i = j + 1; i < nTown; ++i) {
			if (connected[j][i] == true) {
				answer += dist[j][i];
			}
		}
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> nTown;

	std::vector<std::vector<int>> dist(nTown, std::vector<int>(nTown));
	std::vector<std::vector<bool>> connected(nTown, std::vector<bool>(nTown, true));
	for (int j = 0; j < nTown; ++j) {
		for (int i = 0; i < nTown; ++i) {
			cin >> dist[j][i];
		}
	}

	if (FindRoute(dist, connected)) {
		cout << CountRoad(dist, connected) << "\n";
	}
	else {
		cout << "-1\n";
	}
}
