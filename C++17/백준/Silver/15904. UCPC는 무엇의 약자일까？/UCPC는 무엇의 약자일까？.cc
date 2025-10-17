#include <iostream>
#include <string>
#include <algorithm>

bool CanMake(const std::string title) {
	std::string target = "UCPC";

	auto it = title.begin();
	for (const char c : target) {
		it = std::find(it, title.end(), c);
		if (it == title.end()) {
			return false;
		}
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string title;
	std::getline(std::cin, title);

	if (CanMake(title)) {
		std::cout << "I love UCPC\n";
	}
	else {
		std::cout << "I hate UCPC\n";
	}
}
