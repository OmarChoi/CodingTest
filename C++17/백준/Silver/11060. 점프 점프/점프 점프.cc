#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int CountJump(int N, const vector<int>& nums) {
	vector<bool> visit(N + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	// 점프 횟수, index
	pq.emplace(0, 1);
	while (!pq.empty()) {
		auto [count, curr] = pq.top();
		pq.pop();
		if (curr >= N) {
			return count;
		}

		if (visit[curr] == true) {
			continue;
		}
		visit[curr] = true;

		for (int i = 1; i <= nums[curr]; ++i) {
			int next = std::min(curr + i, N);
			if (visit[next] == false) {
				pq.emplace(count + 1, next);
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> nums(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
	}

	cout << CountJump(N, nums);

	return 0;
}
