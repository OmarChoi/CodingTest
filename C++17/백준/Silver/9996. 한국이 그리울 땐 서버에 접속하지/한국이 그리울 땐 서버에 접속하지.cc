#include <iostream>
#include <sstream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nStr;
	std::cin >> nStr;

	std::string str;
	std::cin >> str;

	std::stringstream ss(str);
	std::string front, back;
	std::getline(ss, front, '*');
	std::getline(ss, back);

	for (int i = 0; i < nStr; ++i) {
		std::string input;
		std::cin >> input;

		bool isDA = true;
		if (input.length() < front.length() + back.length()) {
			std::cout << "NE\n";
			continue;
		}

		for (int j = 0; j < front.size(); ++j) {
			if (front[j] != input[j]) {
				isDA = false;
				break;
			}
		}

		for (int j = 0; j < back.size(); ++j) {
			if (back[j] != *(input.end() - back.size() + j)) {
				isDA = false;
				break;
			}
		}
		
		if (isDA) {
			std::cout << "DA\n";
		}
		else {
			std::cout << "NE\n";
		}
	}
}
