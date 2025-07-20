#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nLine = 0;
	cin >> nLine;
	vector<pair<int, int>> lines;
	for (int i = 0; i < nLine; ++i) {
		int s, e;
		cin >> s >> e;
		lines.emplace_back(s, e);
	}

	sort(lines.begin(), lines.end(), [](const auto& a, const auto& b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
		});

	int answer = 0;
	int start = 100'000'000'1;	// 현재 저장된 선의 시작 부분
	int end = 100'000'000'1;	// 현저 저장된 선의 끝 부분
	for (int i = 0; i < nLine; ++i) {
		// 종료 지점이 뒤에 있는 것부터 하나씩 확인
		if (start > lines[i].second) {
			// 이전 선의 시작점이 현재 선의 종료 지점보다 뒤에 있으면 서로 다른 선이라 판단
			// 이전 선의 길이를 저장하고 선 정보 갱신
			answer += end - start;
			end = lines[i].second;
			start = lines[i].first;
		}
		else {
			// 중복된 부분이 있는 선이라 판단하여 두 선을 하나로 합치기
			start = min(start, lines[i].first);
		}
	}
	answer += end - start;
	cout << answer;
}
