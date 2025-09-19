#include <iostream>
#include <array>
#include <vector>

class Num
{
public:
	std::array<Num*, 10> nextNum{ nullptr, };	// 다음 번에 오는 숫자
	bool isEnd = false;

	// str를 삽입하면서 접두사 충돌이 있으면 false 반환
	bool FindAndRegist(const std::string& str, size_t idx) {

		// 새 번호가 끝났는데 자식이 있으면: 새 번호가 다른 번호의 접두사
		if (idx == str.length()) {
			if (hasChild()) {
				return false;
			}
			isEnd = true;
			return isEnd;
		}

		// 아직 끝나지 않았는데 이미 어떤 번호가 여기서 끝났다면
		if (isEnd) {
			return false;
		}

		size_t next = static_cast<size_t>(str[idx] - '0');
		if (next < 0 || next > 9) {
			return false;
		}

		if (nextNum[next] == nullptr) {
			nextNum[next] = new Num();
		}
		return nextNum[next]->FindAndRegist(str, idx + 1);
	}

	bool hasChild() const {
		for (auto p : nextNum) {
			if (p != nullptr) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nTestCase = 0;
	std::cin >> nTestCase;


	for (int tc = 0; tc < nTestCase; ++tc) {
		int nTel;
		std::cin >> nTel;
		std::string answer = "YES";
		std::vector<std::string> tels(nTel);
		Num* rootNum = new Num;

		for (int i = 0; i < nTel; ++i) {
			std::cin >> tels[i];
		}

		for (const std::string& tel : tels) {
			if (!rootNum->FindAndRegist(tel, 0)) {
				answer = "NO";
				break;
			}
		}

		std::cout << answer << "\n";
	}
}
