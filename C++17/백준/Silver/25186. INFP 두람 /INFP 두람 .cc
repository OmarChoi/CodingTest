#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nType;
	std::cin >> nType;

	int64_t totalPerson = 0;	// 총 사람 수
	int64_t maxType = 0;		// 가장 많은 옷의 개수

	// 가장 많은 옷의 개수가 (총 사람의 수 / 2)개 보다 많으면 불행
	for (int i = 0; i < nType; ++i) {
		int64_t type;
		std::cin >> type;

		totalPerson += type;
		maxType = std::max(maxType, type);
	}
	
	if (totalPerson == 1 || maxType <= totalPerson / 2) {
		std::cout << "Happy\n";
	}
	else {
		std::cout << "Unhappy\n";
	}
}