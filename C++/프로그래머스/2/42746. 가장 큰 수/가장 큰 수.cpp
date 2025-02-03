#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct compare
{
    bool operator() (string str1, string str2) {
        return str1 + str2 < str2 + str1;
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    priority_queue<string, vector<string>, compare> pq;
    
    for (int i : numbers)
        pq.emplace(to_string(i));
    if(pq.top() == "0") 
        return "0";
    while (!pq.empty()) {
        string str = pq.top();
        pq.pop();
        answer += str;
    }
    
    return answer;
}