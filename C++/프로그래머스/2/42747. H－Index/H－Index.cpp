#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int nCitation = citations.size();
    sort(citations.begin(), citations.end());
    
    int minScore = 0;
    int maxScore = *citations.rbegin();
    
    while (minScore <= maxScore) {
        int middleScore = (minScore + maxScore) / 2;
        if (middleScore > nCitation) {
            maxScore = middleScore - 1;
            continue;
        }
        
        if (citations[nCitation - middleScore] >= middleScore) {
            answer = middleScore;
            minScore = middleScore + 1;
        }
        else {
            maxScore = middleScore - 1;
        }
    }
    
    return answer;
}