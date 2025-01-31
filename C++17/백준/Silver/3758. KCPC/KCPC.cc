#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Team
{
public:
	int teamID;
	int nSubmission = 0;
	int scoreSum = 0;
	int lastSubmissionTime = 0;
	vector<int> scores;

	void InputScore(int problem, int score, int time) 
	{
		if (scores[problem] < score)
		{
			// 기존에 입력되어 있던 점수가 더 작으면
			scoreSum -= scores[problem];
			scores[problem] = score;
			scoreSum += scores[problem];
		}
		nSubmission += 1;
		lastSubmissionTime = time;
	}

	bool operator > (const Team& other) const
	{
		if(scoreSum != other.scoreSum)
			return scoreSum > other.scoreSum;
		if (nSubmission != other.nSubmission)
			return nSubmission < other.nSubmission;
		else
			return lastSubmissionTime < other.lastSubmissionTime;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nTestCase;
	cin >> nTestCase;
	int testCount = 0;

	while (testCount < nTestCase)
	{
		int nTeam, nProblem, MyTeam, nLog;
		cin >> nTeam >> nProblem >> MyTeam >> nLog;
		MyTeam -= 1;
		vector<Team> teams(nTeam);
		for (int i = 0; i < nTeam; ++i) {
			teams[i].teamID = i;
			teams[i].scores.resize(nProblem);
		}

		for (int i = 0; i < nLog; ++i) {
			int teamID, problemID, score;
			cin >> teamID >> problemID >> score;
			teams[teamID - 1].InputScore(problemID - 1, score, i);
		}

		sort(teams.begin(), teams.end(), greater<Team>());
		auto it = find_if(teams.begin(), teams.end(), [&MyTeam](const Team& team) {
			return team.teamID == MyTeam;
			});
		
		cout << it - teams.begin() + 1 << "\n";
		testCount += 1;
	}
}
