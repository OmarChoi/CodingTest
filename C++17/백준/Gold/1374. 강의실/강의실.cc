#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nLecture;
	cin >> nLecture;

	vector<std::pair<int, int>> lectures(nLecture);
	for (int i = 0; i < nLecture; ++i) {
		// 강의 번호는 불필요한 정보 같아서 굳이 저장 X
		int lID;
		cin >> lID >> lectures[i].first >> lectures[i].second;
	}
	sort(lectures.begin(), lectures.end());

	priority_queue<int, vector<int>, greater<int>> pq; // 현재 사용하고 있는 강의실 끝나는 시간이 빠른 순서로 정렬
	for (int i = 0; i < nLecture; ++i) {
		if (pq.empty()) {
			// 현재 진행 중인 강의가 없으면 새로운 강의실 추가 후 강의 배정
			pq.emplace(lectures[i].second);
			continue;
		}
		if (pq.top() <= lectures[i].first) {
			// 현재 강의 시간 전에 끝나는 강의가 있으면 해당 강의실 비어주고 현재 강의 추가
			pq.pop();
		}
		pq.emplace(lectures[i].second);
	}
	cout << pq.size() << endl;
}
