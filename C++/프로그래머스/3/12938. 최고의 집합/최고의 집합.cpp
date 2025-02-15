#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s < n) {
        answer.emplace_back(-1);
        return answer;
    }
    if (n == 1) {
        answer.emplace_back(s);
        return answer;
    }
    
    int nums = round(s / n);
    int numSum = nums * n;
    answer = vector<int>(n, nums);
    if (numSum < s) {
        int diff = s - numSum;
        for (int i = n - diff; i < n; ++i) {
            answer[i] += 1;
        }
    }
    else if (numSum > s) {
        int diff = numSum - s;
        for (int i = 0; i < diff; ++i) {
            answer[i] += 1;
        }
    }
    return answer;
}