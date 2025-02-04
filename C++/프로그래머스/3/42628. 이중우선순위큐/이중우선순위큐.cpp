#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    multiset<int, greater<int>> nums;
    for (const string& str : operations) {
        char oper = str[0];
        if (oper == 'I') {
            string numString { str.begin() + 2, str.end() };    
            nums.emplace(stoi(numString));
        }
        else {
            if (nums.size() == 0) continue;
            if (str[2] == '-') {
                nums.erase(--nums.end());
            }
            else {
                nums.erase(nums.begin());
            }
        }
    }

    if(nums.size() != 0) {
        answer[0] = *nums.begin();
        answer[1] = *nums.rbegin();
    }
    return answer;
}