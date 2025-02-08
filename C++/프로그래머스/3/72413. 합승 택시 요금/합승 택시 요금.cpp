#include <string>
#include <vector>

using namespace std;

constexpr int INF = 200'000'000; // 200 * 100'000

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INF));
    
	for (const vector<int>& vec : fares) {
		cost[vec[0]][vec[1]] = vec[2];
		cost[vec[1]][vec[0]] = vec[2];
	}
    
    for (int i = 1; i <= n; ++i) {
        cost[i][i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for(int k = 1; k <= n; ++k) {
                if(cost[j][k] > cost[j][i] + cost[i][k])
					cost[j][k] = cost[j][i] + cost[i][k];
            }
        }
    }
    
    int minCost = INF;
	for (int i = 1; i <= n; ++i) {
        int totalCost = cost[s][i] + cost[i][a] + cost[i][b];
        if(totalCost < minCost)
            minCost = totalCost;
	}
    
    return minCost;
}