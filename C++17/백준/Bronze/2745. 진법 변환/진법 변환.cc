#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	int B;
	std::cin >> str >> B;

	int ans = 0;
	for (const char c : str) {
		int value = 0;
		if (std::isdigit(c) == true) {
			value = c - '0';
		}
		else {
			value = c - 'A' + 10;
		}

		if (value >= 0 && value <= B) {
			ans = ans * B + value;
		}
	}
	std::cout << ans;
}
