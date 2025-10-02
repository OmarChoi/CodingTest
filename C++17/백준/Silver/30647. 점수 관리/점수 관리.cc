#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Info
{
	std::string name = "";
	int score = 0;
	bool isHidden = false;

	bool operator > (const Info& rhs) const {
		if (score == rhs.score) {
			return name < rhs.name;
		}
		return score > rhs.score;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nParticipant;
	std::cin >> nParticipant;
	std::vector<Info> infos(nParticipant);
	for (int i = 0; i < nParticipant; ++i) {
		std::string str;
		std::cin >> str;

		int nameIdx = str.find("name") + 7;	// "name":" 이후 인덱스 값 찾기
		int scoreIdx = str.find("score");
		infos[i].name = str.substr(nameIdx, scoreIdx - nameIdx - 3);
		
		scoreIdx += 7;
		int hiddenIdx = str.find("isHidden"); 
		infos[i].score = std::stoi(str.substr(scoreIdx, hiddenIdx - scoreIdx - 2));

		infos[i].isHidden = str[hiddenIdx + 10] - '0';
	}

	std::sort(infos.begin(), infos.end(), std::greater<Info>());

	int rank = 1;
	int prevScore = 100'000'001;
	for (int i = 0; i < nParticipant; ++i) {
		const auto& [name, score, isHidden] = infos[i];

		if (score < prevScore) {
			rank = (i + 1);
		}
		prevScore = score;

		if (isHidden == false) {
			std::cout << rank << " " << name << " " << score << "\n";
		}
	}
}