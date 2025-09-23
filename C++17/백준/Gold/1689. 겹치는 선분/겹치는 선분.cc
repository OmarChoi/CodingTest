#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nLine;
	std::cin >> nLine;
	std::vector<int> start(nLine);
	std::vector<int> end(nLine);

	for (int i = 0; i < nLine; ++i) {
		std::cin >> start[i] >> end[i];
	}

	std::sort(start.begin(), start.end());
	std::sort(end.begin(), end.end());

	// 특정 선분의 끝나는 지점 end보다 앞에서 시작하는 선분이 있으면 +1
	int sIdx = 0;
	int eIdx = 0;
	int maxLine = 0;
	int currLine = 0;
	while(sIdx < nLine) {
		if (start[sIdx] < end[eIdx]) {
			currLine += 1;
			if (currLine > maxLine) {
				maxLine = currLine;
			}
			sIdx += 1;
		}
		else {
			currLine -= 1;
			eIdx += 1;
		}
	}

	std::cout << maxLine;
}
