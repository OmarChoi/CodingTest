#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Compare
{
public:
	bool operator () (const pair<int, int>& a, const pair<int, int>& b) const {
		return a.second < b.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nCode = 0;
	int nUse = 0;
	cin >> nCode >> nUse;

	vector<int> seq(nUse);
	unordered_map<int, queue<int>> elecMap;
	for (int i = 0; i < nUse; ++i) {
		cin >> seq[i];
		if (elecMap.find(seq[i]) == elecMap.end()) {
			elecMap[seq[i]];
		}
		else {
			elecMap[seq[i]].emplace(i);
		}
	}

	priority_queue <pair<int, int>, vector<pair<int, int>>, Compare> pq;	// 다음에 빠르게 나오는 순서로 정렬
	unordered_set<int> currUse;			// 현재 사용 중인 전자제품
	int currElec = 0;
	int nChange = 0;

	while (currElec < nUse) {
		auto it = elecMap.find(seq[currElec]);
		if (it == elecMap.end()) {
			return 0;
		}

		int nextIdx = 101;
		if (it->second.size() != 0) {
			nextIdx = it->second.front();
			it->second.pop();
		}

		if (currUse.size() >= nCode) {
			if (currUse.count(seq[currElec]) == 0) {
				nChange += 1;
				if (!pq.empty()) {
					int removeID = pq.top().first;
					pq.pop();
					currUse.erase(removeID);
				}
			}
		}

		pq.emplace(make_pair(seq[currElec], nextIdx));
		currUse.emplace(seq[currElec]);
		currElec += 1;
	}

	cout << nChange << endl;
}