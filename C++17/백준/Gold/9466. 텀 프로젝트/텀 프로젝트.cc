#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nTestCase = 0;
	cin >> nTestCase;

	while (nTestCase > 0) {
		int nStudent;
		cin >> nStudent;

		vector<int> coworker(nStudent + 1);
		vector<bool> visit(nStudent + 1, false);
		vector<bool> haveTeam(nStudent + 1, false);
		haveTeam[0] = true;

		for (int i = 1; i <= nStudent; ++i) {
			cin >> coworker[i];
		}

		// Stack에 나온적이 있는 노드가 등장할 때까지 값을 하나씩 삽입
		// 만약 나온적이 있는 노드가 등장했을 때, 이전에 해당 노드가 나온 시점까지 한 사이클을 이루고 있다고 판단.
		// 사이클 판단이 끝나면 사이클을 이루지 않는 나머지 노드들은 사이클을 이루지 않는다고 판단한다.
		for (int i = 1; i <= nStudent; ++i) {
			if (visit[i] == true) continue;
			stack<int> path;
			vector<bool> inStack(nStudent + 1, false);
			int current = i;

			while (true) {
				if (visit[current]) {
					if (inStack[current]) {
						while (!path.empty()) {
							int node = path.top(); 
							path.pop();
							haveTeam[node] = true;
							if (node == current) break;
						}
					}
					break;
				}

				visit[current] = true;
				path.push(current);
				inStack[current] = true;

				current = coworker[current];
			}
		}

		int answer = 0;
		for (int i = 0; i < haveTeam.size(); ++i) {
			if (haveTeam[i] == false) {
				answer += 1;
			}
		}
		cout << answer << "\n";
		nTestCase -= 1;
	}
}
