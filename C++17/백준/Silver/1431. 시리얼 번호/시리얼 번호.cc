#include <iostream>
#include <vector>
#include <algorithm>

struct STR 
{
	std::string str;
	int sum = 0;

	bool operator < (const STR& rhs) const {
		if (str.length() == rhs.str.length()) {
			if (sum == rhs.sum) {
				return str < rhs.str;
			}
			return sum < rhs.sum;
		}
		return str.length() < rhs.str.length();
	}

	void SetNum() {
		for (char c : str) {
			if (c > '0' && c <= '9') {
				sum += (c - '0');
			}
		}
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nStr = 0;
	std::cin >> nStr;
	std::vector<STR> strs(nStr);
	for (int i = 0; i < nStr; ++i) {
		std::cin >> strs[i].str;
		strs[i].SetNum();
	}
	
	std::sort(strs.begin(), strs.end());
	for (const STR& str : strs) {
		std::cout << str.str << "\n";
	}
}