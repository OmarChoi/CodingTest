#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

std::vector<int> team;

int Find(int a) {
	if (team[a] != a) {
		team[a] = Find(team[a]);
	}
	return team[a];
}

void Union(int a, int b) {
	int aTeam = Find(a);
	int bTeam = Find(b);
	if (aTeam != bTeam) {
		team[aTeam] = bTeam;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nStudent;
	std::cin >> nStudent;
	
	team = std::vector<int>(nStudent + 1);
	std::vector<std::vector<int>> enemies(nStudent + 1);	// i와 적인 객체
	std::iota(team.begin(), team.end(), 0);

	int nRelation;
	std::cin >> nRelation;

	for (int i = 0; i < nRelation; ++i) {
		char rel;
		int a, b;
		std::cin >> rel >> a >> b;

		// 친구인지 확인
		if (rel == 'F') {
			Union(a, b);
		}
		else {
			enemies[a].emplace_back(b);
			enemies[b].emplace_back(a);
		}
	}

	// 적의 적을 친구로 설정
	for (const auto& vec : enemies) {
		for (int i = 0; i < vec.size(); ++i) {
			for (int j = i + 1; j < vec.size(); ++j) {
				Union(vec[i], vec[j]);
			}
		}
	}

    // 대표 값만 set에 삽입
	std::unordered_set<int> teamSet;
	for (int i = 1; i <= nStudent; ++i) {
		teamSet.emplace(Find(team[i]));
	}

	std::cout << teamSet.size();
}
