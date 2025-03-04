#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

constexpr int dy[4] = {1, 0, -1, 0};
constexpr int dx[4] = {0, 1, 0, -1};
constexpr int INT_MAX = 210'000'000;
class Node
{
public:
    int yPos;
    int xPos;
    int cost;
    
    Node(int y, int x, int c) : yPos(y), xPos(x), cost(c) {};
    
    bool operator > (const Node& other) const {
        return cost > other.cost;
    }
};


int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int wHeight = land.size();
    int wWidth = land[0].size();
    vector<vector<int>> cost(wHeight, vector<int>(wWidth, INT_MAX));
    vector<vector<bool>> visit(wHeight, vector<bool>(wWidth, false));
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.emplace(0, 0, 0);
    
    while (!pq.empty()) {
        Node currNode = pq.top();
        pq.pop();
        int yPos = currNode.yPos;
        int xPos = currNode.xPos;
        if (visit[yPos][xPos] == true) continue;
        visit[yPos][xPos] = true;
        answer += currNode.cost;
        
        for (int i = 0; i < 4; ++i) {
            int nextY = yPos + dy[i];
            int nextX = xPos + dx[i];
            if (nextY < 0 || nextY >=  wHeight) continue;
            if (nextX < 0 || nextX >=  wWidth) continue;
            if (visit[nextY][nextX] == true) continue;
            
            int diff = abs(land[nextY][nextX] - land[yPos][xPos]);
            int moveCost = (diff > height) ? diff : 0;
            if (cost[nextY][nextX] <= moveCost) continue;
            cost[nextY][nextX] = currNode.cost + moveCost;
            pq.emplace(nextY, nextX, moveCost);
        }
    }
    return answer;
}