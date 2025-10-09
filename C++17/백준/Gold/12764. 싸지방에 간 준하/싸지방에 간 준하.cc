#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

struct Com
{
	int i;		// 몇번째 컴퓨터인지
	int eTime;	// 언제까지 쓰는지

	Com(int i, int end) : i(i), eTime(end) {}

	bool operator > (const Com& rhs) const {
		if (eTime == rhs.eTime) {
			return i > rhs.i;
		}
		return eTime > rhs.eTime;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nPerson;
	std::cin >> nPerson;
	std::vector<std::pair<int, int>> usingLog(nPerson);
	for (int i = 0; i < nPerson; ++i) {
		std::cin >> usingLog[i].first >> usingLog[i].second;
	}
	std::sort(usingLog.begin(), usingLog.end());
	std::vector<int> computers(nPerson);

	std::priority_queue<Com, std::vector<Com>, std::greater<Com>> pq;
	std::set<int> blankSeat;
	int total = 1;

	for (int i = 0; i < nPerson; ++i) {
		if (pq.empty() == true) {
			computers[0] += 1;
			pq.emplace(0, usingLog[i].second);
			continue;
		}

		// 현재 가장 먼저 끝나는 컴퓨터 반납
		while (!pq.empty() && usingLog[i].first > pq.top().eTime) {
			blankSeat.emplace(pq.top().i);
			pq.pop();
		}

		// 비어있는 좌석이 있으면 가장 앞에 있는 좌석 추가
		// 없으면 새로운 컴퓨터 추가
		if (blankSeat.empty() != true) {
			auto it = blankSeat.begin();
			computers[*it] += 1;
			pq.emplace(*it, usingLog[i].second);
			blankSeat.erase(it);
		}
		else {
			int newCom = pq.size();
			computers[newCom] += 1;
			pq.emplace(newCom, usingLog[i].second);
			total = std::max(static_cast<int>(pq.size()), total);
		}
	}

	std::cout << total << "\n";
	for (int i = 0; i < total; ++i) {
		std::cout << computers[i] << " ";
	}
}
