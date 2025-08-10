#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);	std::cout.tie(NULL);

	int nLecture;
	std::cin >> nLecture;
	std::vector<std::pair<int, int>> lectures(nLecture);
	for (int i = 0; i < nLecture; ++i) {
		std::cin >> lectures[i].first >> lectures[i].second;
	}

	// 먼저 시작하는 강의실 순서로 정렬
	std::sort(lectures.begin(), lectures.end(), [](const auto& a, const auto& b) {
		if (a.first == b.first) {
			// 시작 시간이 같으면 끝나는 시간이 빠른 순서로 정렬
			return a.second < b.second;
		}
		return a.first < b.first;
		});


	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (const auto& lecture : lectures) {
		if (!pq.empty()) {
			if (pq.top() <= lecture.first) {
				// 새로운 강의 시작 시간보다 일찍 끝나는 강의가 있으면
				// 해당 강의실이 비었다 판단하여 해당 강의 제거
				pq.pop();
			}
		}
		pq.emplace(lecture.second);
	}
	std::cout << pq.size();
}
