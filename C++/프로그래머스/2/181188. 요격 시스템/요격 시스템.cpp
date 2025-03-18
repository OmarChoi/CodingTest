#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b){
       return a[1] < b[1]; 
    });
    
    int missilePos = -1;
    for(const vector<int>& target : targets) {
        if (target[0] >= missilePos) {
            missilePos = target[1];
            answer += 1;
        }
    }
    
    return answer;
}