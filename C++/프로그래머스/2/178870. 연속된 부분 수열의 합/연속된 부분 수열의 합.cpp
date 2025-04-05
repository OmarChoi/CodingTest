#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    vector<int> prefixSum(sequence.size() + 1);
    
    prefixSum[0] = 0;
    for (int i = 1; i < prefixSum.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + sequence[i - 1];
    }
    int sIndex = 0;
    int eIndex = 1;
    int minSize = sequence.size() + 1;
    
    while (sIndex <= eIndex && eIndex < prefixSum.size()) {
        int n = prefixSum[eIndex] - prefixSum[sIndex];
        if (n > k) {
            sIndex += 1;
        }
        else if (n < k) {
            eIndex += 1;
        }
        else {
            if (eIndex - sIndex < minSize) {
                answer[0] = sIndex;
                answer[1] = eIndex - 1;
                minSize = eIndex - sIndex;
            }
            eIndex += 1;
        }
    }
    
    return answer;
}