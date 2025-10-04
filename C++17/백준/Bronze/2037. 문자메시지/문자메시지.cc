#include <iostream>
#include <array>
#include <string>

struct Alphabet
{
	int button;
	int nClick;
};

void SetKeySet(std::array<Alphabet, 26>& keySet) {
	const std::array<int, 8> nButtons = { 3, 3, 3, 3, 3, 4, 3, 4 };

	int idx = 0;
	// 어느 버튼을 눌러야 하는지
	for (int i = 0; i < nButtons.size(); ++i) {
		// 몇번 눌러야 하는지
		for (int j = 1; j <= nButtons[i]; ++j) {
			keySet[idx].button = i;
			keySet[idx].nClick = j;
			idx += 1;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	std::array<Alphabet, 26> keySet;
	SetKeySet(keySet);

	int prevNum = -1;
	int p, w;	// 1회 누르는데 걸리는 시간, 연속으로 누르기 위해 대기하는 시간
	std::cin >> p >> w;

	std::string str;
	std::getline(std::cin >> std::ws, str);

	int duration = 0;
	for (const char c : str) {
		if (c == ' ') {
			duration += p;	// ' '한번만 누르면 된다.
			prevNum = -1;
			continue;
		}

		int n = static_cast<int>(c - 'A');
		const auto& [button, count] = keySet[n];

		// 이전과 같은 버튼을 눌러야 하면 w만큼 대기
		if (button == prevNum) {
			duration += w;
		}
		duration += (p * count);

		prevNum = button;
	}

	std::cout << duration << std::endl;
}
	