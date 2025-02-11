#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    // 처음부터 끝까지 순회하며 범위가 K일 때의 최댓값을 구한다.
    //// 최댓값을 구할 때 시간복잡도가 O(n)보다 작은 방법으로 구한다.
    // K의 최솟값을 반환한다.
    multiset<int, greater<int>> numInRange;
    queue<int> stoneInRange;
    vector<int> maxVec(stones.size() - k + 1);
    
    int maxIndex = 0;
    
    for (int i = 0; i < k; ++i) {
        stoneInRange.emplace(stones[i]);
        numInRange.emplace(stones[i]);
    }
    maxVec[maxIndex++] = *numInRange.begin();
    
    for (int i = k; i < stones.size(); ++i) {
        int popNum = stoneInRange.front();
        stoneInRange.pop();
        
        auto it = numInRange.find(popNum);
        if (it != numInRange.end())
            numInRange.erase(it);
        
        stoneInRange.emplace(stones[i]);
        numInRange.emplace(stones[i]);
        maxVec[maxIndex++] = *numInRange.begin();
    }
    
    sort(maxVec.begin(), maxVec.end());
    return maxVec[0];
}