#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> tanMap;
    for(int i : tangerine) {
        tanMap[i] += 1;
    }
    vector<pair<int,int>> tanVec(tanMap.begin(), tanMap.end());
    sort(tanVec.begin(), tanVec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second > b.second;
    });
    for (const pair<int,int>& tan : tanVec) {
        k -= tan.second;
        answer += 1;
        if (k <= 0) {
            break;
        }
    }
    return answer;
}