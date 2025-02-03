#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int execTime = 0;
    queue<pair<int, int>> bridge;
    int currWeight = 0;
    int nextTruck = 0;

    while (true) {
        execTime += 1;
        if(!bridge.empty()) {
            pair<int, int> frontTruck = bridge.front();
            if (execTime - frontTruck.second >= bridge_length) {
                bridge.pop();
                currWeight -= truck_weights[frontTruck.first];
            }
        }
        if (currWeight < weight) {
            if (nextTruck == truck_weights.size()) {
                if(currWeight == 0)
                    break;
            }
            else {
                if(truck_weights[nextTruck] + currWeight <= weight) {
                    bridge.emplace(make_pair(nextTruck, execTime));
                    currWeight += truck_weights[nextTruck];
                    nextTruck += 1;
                }
            }

        }
    }
    
    return execTime;
}