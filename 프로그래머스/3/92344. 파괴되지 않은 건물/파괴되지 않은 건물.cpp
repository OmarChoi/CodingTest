#include <string>
#include <vector>
#include <iostream>

using namespace std;
void PrintVec(const vector<vector<int>>& vec) {
    for (const vector<int>& v : vec) {
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int width = board[0].size();
    int height = board.size();
    int answer = 0;
    vector<vector<int>> damage(height, vector<int>(width));
    // b[s[1]][s[2]]    b[s[1]][s[4] + 1]
    // b[s[3] + 1][s[2]]    b[s[3] + 1][s[4] + 1]
    for (const vector<int>& s : skill) {
        if (s[0] == 1) {
            damage[s[1]][s[2]] += s[5];
            if (s[4] + 1 < width) {
                damage[s[1]][s[4] + 1] += -s[5];
            }
            if (s[3] + 1 < height) {
                    damage[s[3] + 1][s[2]] += -s[5];
                if (s[4] + 1 < width) {
                    damage[s[3] + 1][s[4] + 1] += s[5];
                }
            }
        }
        else {
            damage[s[1]][s[2]] += -s[5];
            if (s[4] + 1 < width) {
                damage[s[1]][s[4] + 1] += s[5];
            }
            if (s[3] + 1 < height) {
                    damage[s[3] + 1][s[2]] += s[5];
                if (s[4] + 1 < width) {
                    damage[s[3] + 1][s[4] + 1] += -s[5];
                }
            }
        }
    }
    for (int i = 1; i < width; ++i) {
        for(int j = 0; j < height; ++j)
            damage[j][i] += damage[j][i - 1];
    }
    for (int j = 1; j < height; ++j) {
        for(int i = 0; i < width; ++i)
            damage[j][i] += damage[j - 1][i];
    }

    for (int j = 0; j < height; ++j) {
        for(int i = 0; i < width; ++i) {
            if (damage[j][i] <= 0) {
                answer += 1;
                continue;
            }
            if (board[j][i] > damage[j][i]) {
                answer += 1;
            }
        }
    }
    
    return answer;
}