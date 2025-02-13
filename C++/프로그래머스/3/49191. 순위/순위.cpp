#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Pro;
vector<Pro> participant;
class Pro
{
public:
    unordered_set<int> highRanker;
    unordered_set<int> lowRanker;
    bool exactRank = false;
    
    bool CheckRankExact() {
        if (participant.size() == 0) return false;
        return (participant.size() - 2 == highRanker.size() + lowRanker.size());
    }
    
    void AddResult (int opponentIndex, bool winnable) {
        if (winnable) {
            // 나보다 위에 랭크에 있는 애들도 상대방을 이길 수 있다.
            if (lowRanker.find(opponentIndex) != lowRanker.end()) return;
            lowRanker.emplace(opponentIndex);
            for (int i : highRanker) {
                for (int j : lowRanker) {
                    participant[i].AddResult(j, winnable);
                    participant[j].AddResult(i, !winnable);
                }
            }
        }
        else {
            if (highRanker.find(opponentIndex) != highRanker.end()) return;
            highRanker.emplace(opponentIndex);
            for (int i : lowRanker) {
                for (int j : highRanker) {
                    participant[i].AddResult(j, winnable);
                    participant[j].AddResult(i, !winnable);
                }
            }
        }
        exactRank = CheckRankExact();
    }
}; 

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    participant = vector<Pro>(n + 1);
    
    for (const vector<int>& result : results) { 
        int winner = result[0];
        int loser = result[1];
        participant[winner].AddResult(loser, true);
        participant[loser].AddResult(winner, false);
    }
    
    for (const Pro& pro : participant) {
        if (pro.exactRank)
            answer += 1;
    }
    return answer;
}