#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	bool isLeft[26] = { false };
	std::string leftKeys = "qwertyasdfgzxcvb";
	for (char k : leftKeys) {
		isLeft[k - 'a'] = true;
	}

	std::string str; 
	getline(std::cin, str);

	int nL = 0;
	int nR = 0;
	int joker = 0;					// 조커: Shift(대문자), Space

	for (char c : str) {
		if (c == ' ') {
			joker += 1;
			continue;
		}

        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isupper(uc)) {
            joker += 1;
            c = static_cast<char>(std::tolower(uc));
        }

		if (c >= 'a' && c <= 'z') {
			if (isLeft[c - 'a'] == true) {
				nL += 1;
			}
			else {
				nR += 1;
			}
		}
	}

	while (joker > 0) {
		if (nL <= nR) {
			++nL;
		}
		else {
			++nR;
		}
		joker -= 1;
	}
	std::cout << nL << " " << nR << "\n";
}
	