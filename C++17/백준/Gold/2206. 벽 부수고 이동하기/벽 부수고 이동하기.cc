#include <iostream>
#include <queue>

using namespace std;

#define LargeNum 100'000'0

int height, width;

bool CanGo(int yPos, int xPos) {
    if (yPos < 0 || yPos >= height) return false;
    if (xPos < 0 || xPos >= width) return false;
    return true;
}

class Pos
{
public:
    int yPos = 0;
    int xPos = 0;
    int count = LargeNum;
    bool alreadyCrush = false;

    Pos(int y, int x, int c, bool b) : yPos(y), xPos(x), count(c), alreadyCrush(b) {};
    bool operator < (const Pos& rhs) const {
        return count > rhs.count;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> height >> width;
    vector<vector<int>> map(height, vector<int>(width, 0));
    vector<vector<pair<int, bool>>> cost(height, vector<pair<int, bool>>(width, make_pair(LargeNum, false)));

    for (int j = 0; j < height; ++j) {
        string str;
        cin >> str;
        for (int i = 0; i < width; ++i) {
            map[j][i] = str[i] - '0';
        }
    }

    priority_queue<Pos, vector<Pos>, less<Pos>> pq;
    pq.emplace(0, 0, 1, false);
    cost[0][0] = make_pair(1, false);

    int yTrans[4] = { -1, 0, 1, 0 };
    int xTrans[4] = { 0, 1, 0, -1 };
    while (!pq.empty()) {
        Pos pos = pq.top();
        pq.pop();

        int yPos = pos.yPos;
        int xPos = pos.xPos;
        if (yPos == height - 1 && xPos == width - 1) break;

        for (int i = 0; i < 4; ++i) {
            // 현재 칸을 기준으로 4방향 칸에 대해서 추가
            int nextYPos = yPos + yTrans[i];
            int nextXPos = xPos + xTrans[i];
            if (!CanGo(nextYPos, nextXPos)) continue;

            // 이미 더 적은 횟수로 방문한적이 있으면 다시 작업하지 않게 설정
            // 벽을 부수고 더 적은 횟수로 방문한 것이면 다른 경우도 탐색
            if (cost[nextYPos][nextXPos].first <= pos.count + 1 &&
                (cost[nextYPos][nextXPos].second == false || pos.alreadyCrush == true))
                continue;

            if (map[nextYPos][nextXPos] == 1) {
                // 이미 벽을 부순 여부를 확인
                // 벽을 부순적이 없을 때만 큐에 추가
                if (pos.alreadyCrush == true) continue;
                cost[nextYPos][nextXPos] = make_pair(pos.count + 1, true);
                pq.emplace(nextYPos, nextXPos, pos.count + 1, true);
            }
            else {
                cost[nextYPos][nextXPos] = make_pair(pos.count + 1, pos.alreadyCrush);
                pq.emplace(nextYPos, nextXPos, pos.count + 1, pos.alreadyCrush);
            }
        }
    }

    if (cost[height - 1][width - 1].first == LargeNum)
        cout << "-1";
    else
        cout << cost[height - 1][width - 1].first;
}
