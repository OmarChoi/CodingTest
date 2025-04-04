#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int Width, Height;
bool outLineChanged = false;
deque<pair<int, int>> outLine;
vector<vector<int>> visit;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool IsValid(int yPos, int xPos) {
    if (yPos < 0 || yPos >= Height) return false;
    if (xPos < 0 || xPos >= Width) return false;
    return true;
}

void UpdateOutLine(vector<string>& storage) {
    // 이전 테두리 벡터 기반으로 BFS로 탐색
    // 알파벳을 발견하면 해당 알파벳을 테두리로 지정
    // 빈칸을 발견하면 인근 추가 탐색
    int nOutLine = outLine.size();
    for (int j = 0; j < nOutLine; ++j) {
        pair<int, int> curr = outLine.front();
        int y = curr.first;
        int x = curr.second;
        outLine.pop_front();
        if (storage[y][x] != ' ') {
            // 외곽선 변경이 없는 경우
            outLine.emplace_back(curr);
            continue;
        }
        
        queue<pair<int, int>> temp;
        temp.emplace(make_pair(y, x));
        while (!temp.empty()) {
            pair<int, int> tc = temp.front();
            temp.pop();
            int ty = tc.first;
            int tx = tc.second;
            for (int i = 0; i < 4; ++i) {
                int nY = ty + dy[i];
                int nX = tx + dx[i];
                if (IsValid(nY, nX) == false) continue;
                if (visit[nY][nX] != 0) continue;
                if (storage[nY][nX] == ' ') {
                    visit[nY][nX] = -1;
                    temp.emplace(make_pair(nY, nX));
                }
                else {
                    visit[nY][nX] = 1;
                    outLine.emplace_back(make_pair(nY, nX));
                }
            }
        }
    }
}

int RemovebyCrain(vector<string>& storage, char targetWord) {
    // 전체 탐색 후 해당하는 알파벳 삭제
    // 삭제된 항목의 개수 반환
    int nRemoved = 0;
    for (int j = 0; j < Height; ++j) {
        for (int i = 0; i < Width; ++i) {
            if (storage[j][i] == targetWord) {
                if (visit[j][i] == 1) 
                    outLineChanged = true;
                storage[j][i] = ' ';
                nRemoved += 1;
            }
        }
    }
    return nRemoved;
}

int RemovebyFork(vector<string>& storage, char targetWord) {
    int nRemoved = 0;
    for (const auto& p : outLine) {
        if (storage[p.first][p.second] == targetWord) {
            outLineChanged = true;
            storage[p.first][p.second] = ' ';
            nRemoved += 1;
        }
    }
    return nRemoved;
}

int solution(vector<string> storage, vector<string> requests) {
    Height = storage.size();
    Width = storage[0].size();
    int answer = Height * Width;
    
    outLine = deque<pair<int, int>>(Height * 2 + Width * 2 - 4);  // 4변에 있는 알파벳 개수 - 꼭짓점 4개
    visit = vector<vector<int>>(Height, vector<int>(Width, 0));
    int k = 0;
    for (int i = 0; i < Height; ++i) {
        outLine[k++] = make_pair(i, 0);
        visit[i][0] = 1;
        outLine[k++] = make_pair(i, Width - 1);
        visit[i][Width - 1] = 1;
    }
        
    for (int i = 1; i < Width - 1; ++i) {
        outLine[k++] = make_pair(0, i);
        visit[0][i] = 1;
        outLine[k++] = make_pair(Height - 1, i);
        visit[Height - 1][i] = 1;
    }
    
    for (const string& str : requests) {
        if (str.length() == 2) {
            // 크레인을 통한 삭제
            answer -= RemovebyCrain(storage, str[0]);
        }
        else {
            // 지게차를 통한 삭제
            answer -= RemovebyFork(storage, str[0]);
        }
        if (outLineChanged) {
            UpdateOutLine(storage);    
        }
    }
    
    return answer;
}