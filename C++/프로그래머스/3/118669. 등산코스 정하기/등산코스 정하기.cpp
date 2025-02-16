#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;
constexpr int MAX_VALUE = 10'000'001;
class Course
{
public:
    int dest;
    int cost;
    
    Course(int d, int c) : dest(d), cost(c) {}
    
    bool operator > (const Course& c) const {
        if (cost == c.cost)
            return dest > c.dest;
        return cost > c.cost;
    }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2, MAX_VALUE);
    vector<vector<Course>> route(n + 1);
    unordered_set<int> summit(summits.begin(), summits.end());

    for (const vector<int> path : paths) {
        route[path[0]].emplace_back(path[1], path[2]);
        route[path[1]].emplace_back(path[0], path[2]);
    }
    
    int min = MAX_VALUE;
    for (int g : gates) {
        priority_queue<Course, vector<Course>, greater<Course>> pq;
        pq.emplace(g, 0);
        vector<bool> visit(n + 1, false);
        vector<int> cost(n + 1, MAX_VALUE);
        int maxIntensity = -1;
        int searchCount = 0;
        while (!pq.empty()) {
            Course next = pq.top();
            pq.pop();
            
            if (next.cost > min) continue;
            if (visit[next.dest] == true) continue;
            visit[next.dest] = true;
            
            if (maxIntensity < next.cost)
                maxIntensity = next.cost;
            if (cost[next.dest] > maxIntensity)
                cost[next.dest] == maxIntensity;
            if (count(summit.begin(), summit.end(), next.dest) != 0) {
                if (maxIntensity < min) {
                    min = maxIntensity;
                    answer[0] = next.dest;
                    answer[1] = maxIntensity;
                }
                else if (maxIntensity == min) {
                    if (answer[0] > next.dest) {
                        answer[0] = next.dest;
                        answer[1] = maxIntensity;
                    }
                }
                searchCount += 1;
                if (searchCount == summits.size())
                    break;
                continue;
            }
            
            for (const Course& c : route[next.dest]) {
                if (visit[c.dest] == true) continue;
                if (cost[c.dest] < maxIntensity) continue;
                pq.emplace(c.dest, c.cost);
            }
        }
    }
    
    return answer;
}