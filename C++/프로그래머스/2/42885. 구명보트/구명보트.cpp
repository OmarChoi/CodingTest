#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int fIndex = 0;
    int bIndex = people.size() - 1;
    
    while (fIndex <= bIndex) {
        if (people[fIndex] + people[bIndex] <= limit) {
            fIndex += 1;
            bIndex -= 1;
        }
        else {
            bIndex -= 1;
        }
        answer += 1;
    }
    return answer;
}