#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    sort(routes.begin(), routes.end(), [] (const vector<int>& vec1, const vector<int>& vec2) {
        if(vec1[1] == vec2[1])
            return vec1[0] < vec2[0]; 
        return vec1[1] < vec2[1]; 
    });
    
    int rIndex = routes[0][1];
    for (const vector<int>& vec : routes) {
        if (vec[0] <= rIndex) continue;
        answer += 1;
        rIndex = vec[1];
    }
    return answer;
}