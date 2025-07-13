#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class compare
{
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nProblem;
	cin >> nProblem;

	// 컵라면을 많이 제공하는 문제인데 이미 해당 날짜에 다른 문제를 제출하면 
	// 앞으로 하나씩 이동하면서 빈 공간에 삽입
	vector<pair<int, int>> problems(nProblem);
	int maxDeadLine = 0;
	for (int i = 0; i < nProblem; ++i) {
		cin >> problems[i].first >> problems[i].second;
	}

	// 해당 데드라인 날짜에 제출해서 얻을 수 있는 컵라면
	vector<int> nCanGet(maxDeadLine + 1, 0);

	sort(problems.begin(), problems.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
		});
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	for (int i = 0; i < nProblem; ++i) {
		int deadLine = problems[i].first;
		int cupLamen = problems[i].second;
		if (deadLine > pq.size()) {
			// 해당 문제의 DeadLine이 현재 Queue 사이즈보다 크면 Queue에 삽입
			pq.emplace(problems[i]);
			continue;
		}

		if (cupLamen > pq.top().second) {
			// 해당 문제가 현재 Queue에 있는 가장 작은 문제보다 크면 
			// 가장 작은 문제 삭제 후 해당 문제 삽입
			pq.pop();
			pq.emplace(problems[i]);
		}
	}

	int totalCup = 0;
	while (!pq.empty()) {
		totalCup += pq.top().second;
		pq.pop();
	}

	cout << totalCup;
}