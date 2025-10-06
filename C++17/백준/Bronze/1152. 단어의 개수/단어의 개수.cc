#include <iostream>
#include <sstream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	std::getline(std::cin, str);

	std::stringstream ss(str);
	int cnt = 0;
	std::string word;
	while (ss >> word) {
		++cnt;
	}

	std::cout << cnt;
}
