#include <iostream>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;

	int nRemove = 0;
	std::queue<int> aIndex;
	std::queue<int> bIndex;
	for (int i = 0; i < str.length(); ++i) {
		char ch = str[i];

		// A와 B는 index 저장
		// C일 때 앞에 있는 B와 제거
		if (ch == 'A') {
			aIndex.emplace(i);
		}
		else if (ch == 'B') {
			bIndex.emplace(i);
		}
		else if (ch == 'C') {
			if (bIndex.size() > 0) {
				bIndex.pop();
				nRemove += 1;
			}
		}
	}

	while (!aIndex.empty() && !bIndex.empty()) {
		int a = aIndex.front();
		int b = bIndex.front();

		// 맨 앞에 있는 a와 b 제거
		if (a < b) {
			aIndex.pop();
			bIndex.pop();
			nRemove += 1;
		}

		// 앞에 a가 없는 b 제거
		while (a > b) {
			bIndex.pop();
			if (bIndex.empty()) {
				break;
			}

			b = bIndex.front();
		}
	}
	std::cout << nRemove;
}
