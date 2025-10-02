#include <iostream>
#include <array>
#include <vector>
#include <sstream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::string str;
	std::cin >> str;
	
	
	int lIdx = 0;
	int rIdx = n - 1;
	while (lIdx < rIdx) {
		if (str[lIdx] != '?') {
			str[rIdx] = str[lIdx];
		}
		else if (str[rIdx] != '?') {
			str[lIdx] = str[rIdx];
		}
		else {
			// 둘 다 '?'일 때
			str[lIdx] = str[rIdx] = 'a';
		}

		lIdx += 1;
		rIdx -= 1;
	}

	// 가운데가 ?인 경우
	if (str[lIdx] == '?') {
		str[lIdx] = 'a';
	}
	std::cout << str;
}