#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string consonant = "qwertasdfgzxcv";

	int i;
	std::string str;
	std::cin >> i >> str;

	char c = *str.rbegin();
	std::cout << std::count(consonant.begin(), consonant.end(), c);
}