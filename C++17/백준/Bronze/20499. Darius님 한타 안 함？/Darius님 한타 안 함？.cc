#include <iostream>
#include <sstream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;
    std::stringstream ss(str);

    int K, D, A;
    char slash;
    ss >> K >> slash >> D >> slash >> A;

    if (K + A < D || D == 0) {
        std::cout << "hasu\n";
    }
    else {
        std::cout << "gosu\n";
    }
}