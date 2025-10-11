#include <iostream>
#include <set>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;

	std::set<std::string> suffixSet;
	for (int i = 0; i < str.size(); ++i) {
		suffixSet.emplace(str.substr(i));
	}

	for (const auto& s : suffixSet) {
		std::cout << s << "\n";
	}
}