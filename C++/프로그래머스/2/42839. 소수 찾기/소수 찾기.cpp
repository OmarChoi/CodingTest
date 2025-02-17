#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

int numLength = 0;
unordered_set<int> primeNums;

bool IsPrime(int num) {
    if (num < 2) return false;
    for(int i = 2; i <= sqrt(num); ++i) {
        if(num % i == 0) 
            return false;
    }
    return true;
}

void DFS(string& numbers, int idx, string currStr, vector<bool>& isUsed) {
    if (idx >= numLength) return;
    if (isUsed[idx] == true) return;
    isUsed[idx] = true;
    
    currStr += numbers[idx];
    
    int num = stoi(currStr);
    if (IsPrime(num) == true) {
        if (find(primeNums.begin(), primeNums.end(), num) == primeNums.end())
            primeNums.emplace(num);
    }
        
    
    for (int i = 0; i < numLength; ++i) {
        if (isUsed[i] == true) continue;
        DFS(numbers, i, currStr, isUsed);
    }
    
    isUsed[idx] = false;
}

int solution(string numbers) {
    numLength = numbers.length();
    vector<bool> isUsed(numLength, false);
    for (int i = 0; i < numLength; ++i) {
        string str = "";
        DFS(numbers, i, str, isUsed);
    }
    return primeNums.size();
}