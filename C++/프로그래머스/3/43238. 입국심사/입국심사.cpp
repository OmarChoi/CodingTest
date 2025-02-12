#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long minValue = 0;
    long long maxValue = static_cast<long long>(*max_element(times.begin(), times.end())) * n;
    
    while(minValue < maxValue) {
        // N시간동안 몇명을 처리할 수 있는지
        long long midValue = (minValue + maxValue) / 2;
        long long nProcessPerson = 0;
        for (int i : times) {
            nProcessPerson += midValue / i;
        }
        
        if (nProcessPerson < n) {
            minValue = midValue + 1;
        }
        else {
            maxValue = midValue;
        }
    }
    return maxValue;
}