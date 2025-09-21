#include <iostream>
#include <algorithm>

// 맨 뒤에 있는 A삭제
void RemoveChar(std::string& str) {
	str.pop_back();
}

// B를 삭제하고 문자열을 뒤집기
void RemoveAndReverse(std::string& str) {
	RemoveChar(str);
	std::reverse(str.begin(), str.end());
}

bool CheckAnswer(const std::string& answer, const std::string& str) {
	return answer == str;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::string S, T;
	std::cin >> S >> T;
	
	while (T.length() > S.length()) {
		if (*T.rbegin() == 'A') {
			RemoveChar(T);
		}
		else {
			RemoveAndReverse(T);
		}
	}

	std::cout << CheckAnswer(S, T);
}
