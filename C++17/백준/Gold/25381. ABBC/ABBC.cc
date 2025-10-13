#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;

	int nRemove = 0;
	int remainB = 0;	// 뒤에 남아 있는 B가 존재하는지
	int remainC = 0;	// 뒤에 남아 있는 C가 존재하는지
	for (auto it = str.rbegin(); it != str.rend(); ++it) {
		char ch = *it;
		switch (ch) {
		case 'A':
		{
			// 뒤에 남아 있는 B가 있었으면 해당 AB 제거
			if (remainB > 0) {
				remainB -= 1;
				nRemove += 1;
			}
			break;
		}
		case 'B':
		{
			// 뒤에 C가 있으면 BC 제거
			if (remainC > 0) {
				remainC -= 1;
				nRemove += 1;
			}
			else {
				remainB += 1;
			}
			break;
		}
		case 'C':
		{
			remainC += 1;
			break;
		}
		}
	}
	std::cout << nRemove;
}
