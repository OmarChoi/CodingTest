#include <iostream>
#include <set>
#include <sstream>

float GetScore(const std::string& score) {
	if (score == "P") {
		return -1.0f;
	}
	else if (score == "F") {
		return 0.0f;
	}

	int grade = 'E' - score[0];	// A/B/C/D
	float plus = (score[1] == '0') ? 0.0f : 0.5f;

	return static_cast<float>(grade) + plus;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::string str;
	double total = 0.0;
	int cnt = 0;
	for(int i = 0; i < 20; ++i) {
		std::getline(std::cin, str);
		std::istringstream ss(str);
		std::string name, score;
		float multiply;
		ss >> name >> multiply >> score;

		float grade = GetScore(score);
		if (grade != -1) {
			total += (multiply * grade);
			cnt += static_cast<int>(multiply);
		}
	}

	std::cout << total / cnt;
}
