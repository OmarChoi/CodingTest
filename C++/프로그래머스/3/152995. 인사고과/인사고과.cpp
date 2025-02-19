#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class employee
{
public:
    bool CanGetInsentive = true;
    int workerID;
    int workScore;
    int coworkerScore;
    int sumScore;
    
    void SetInfo(int id, int s1, int s2) { workerID = id; workScore = s1; coworkerScore = s2; sumScore = s1 + s2; }
    void EliScore() { CanGetInsentive = false; sumScore = -1; }
    bool operator < (const employee& other) {
        return (coworkerScore < other.coworkerScore && workScore < other.workScore);
    }
};

int solution(vector<vector<int>> scores) {
    vector<employee> eVec(scores.size());
    for (int i = 0; i < scores.size(); ++i) {
        eVec[i].SetInfo(i, scores[i][0], scores[i][1]);
    }
    sort(eVec.begin(), eVec.end(), [](const employee& a, const employee& b) {        
        if (a.workScore == b.workScore)
            return a.coworkerScore > b.coworkerScore;
        return a.workScore > b.workScore;
    });
    
    for (int i = 0; i < eVec.size() - 1; ++i) {
        for(int j = i + 1; j < eVec.size(); ++j) {
            if (eVec[j].CanGetInsentive == false) continue;
            if (eVec[j] < eVec[i]) {
                if (eVec[j].workerID == 0) 
                    return -1;
                eVec[j].EliScore();
            }
        }
    }
    
    sort(eVec.begin(), eVec.end(), [](const employee& a, const employee& b) {
        return a.sumScore > b.sumScore;
    });
    int nSameScore = 0;
    int ranking = 1;
    int score = eVec[0].sumScore;
    
    for (int i = 0; i < eVec.size(); ++i) {
        if (eVec[i].sumScore == score) {
            nSameScore += 1;
        }
        else {
            ranking += nSameScore;
            nSameScore = 1;
            score = eVec[i].sumScore;
        }
        if (eVec[i].workerID == 0) {
            break;
        }
    }
    return ranking;
}