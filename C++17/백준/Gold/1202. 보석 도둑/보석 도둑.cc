#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 모든 보석들을 무게->가치 순으로 정렬
// 2. 모든 가방을 무게가 작은 순서로 정렬
// 3. 모든 가방을 순회하며 아래의 단계를 진행
//   3 - 1. 보석을 순차적으로 탐색하며, 현재 가방에 들어갈 수 있는 보석 중에 제일 가치있는 것을 가방에 삽입
//   3 - 2. 이외에 보석은 우선순위 큐에 삽입
// 4. 3단계를 반복하며 각 가방에 넣을 수 있는 가장 가치가 있는 보석을 처리

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nJewels, nBackpack;
	cin >> nJewels >> nBackpack;

	vector<pair<int, int>> jewels(nJewels);
	for (int i = 0; i < nJewels; ++i) {
		cin >> jewels[i].first >> jewels[i].second;
	}
	
	sort(jewels.begin(), jewels.end(), [](const auto& a, const auto& b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
		});

	vector<int> backpack(nBackpack);
	for (int i = 0; i < nBackpack; ++i) {
		cin >> backpack[i];
	}
	sort(backpack.begin(), backpack.end());
	long long total = 0;

	priority_queue<int> pq;	// 가방에 하나의 보석만 담을 수 있기 때문에, 지금까지 나온 보석의 가치만 신경 쓰면 된다.
	
	// Priority Queue에 Jewel을 하나씩 삽입한다.
	// 현재 가방의 무게와 같은 보석까지 차례대로 Queue에 삽입
	int j = 0;
	for (int i = 0; i < nBackpack; ++i) {
		while (j < jewels.size() && jewels[j].first <= backpack[i]) {
			pq.emplace(jewels[j].second); // 가치만 넣음
			++j;
		}
		if (!pq.empty()) {
			total += pq.top();
			pq.pop();
		}
	}
	cout << total;
}
