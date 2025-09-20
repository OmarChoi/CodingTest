#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	
	std::string str;
	std::cin >> str;

	std::sort(str.begin(), str.end(), std::greater<char>());

	for (char c : str) {
		std::cout << c;
	}
}