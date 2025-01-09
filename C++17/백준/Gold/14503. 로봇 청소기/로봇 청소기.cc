#include <iostream>
#include <vector>

using namespace std;

int width, height;

enum Direction
{
    Up = 0,
    Right = 1,
    Down = 2,
    Left = 3,
    DirCount = 4,
};

int xTrans[DirCount] = { 0, 1, 0, -1 };
int yTrans[DirCount] = { -1, 0, 1, 0 };

bool ValidatePosition(const vector<vector<int>>& roomVec, int yPos, int xPos) {
    if (yPos < 0 || yPos >= height) return false;
    if (xPos < 0 || xPos >= width) return false;
    if (roomVec[yPos][xPos] == 1) return false;
    return true;
}


Direction ChangeDirection(Direction currentDirection) {
    int nextDir = (currentDirection + (Direction::DirCount - 1)) % Direction::DirCount;
    return static_cast<Direction>(nextDir);
}

Direction GetBackDirection(Direction currentDirection) {
    int backDir = (currentDirection + 2) % Direction::DirCount;
    return static_cast<Direction>(backDir);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> height >> width;

    int currXPos, currYPos, currDir;
    cin >> currYPos >> currXPos >> currDir;
    
    vector<vector<int>> room(height, vector<int>(width, 0));
    for (int j = 0; j < height; ++j) {
        for(int i = 0; i < width; ++i) {
            cin >> room[j][i];
        }
    }

    int cleanCount = 0;
    while (true) {
        // 현재 칸이 청소되어 있는지 확인
        if (room[currYPos][currXPos] == 0) {
            cleanCount += 1;
            room[currYPos][currXPos] = 2;
        }

        // 주변 4칸을 확인해서 청소되어 있는 칸의 존재 여부 확인
        bool needCleaning = false;
        for (int i = 0; i < DirCount; ++i) {
            int nextYPos = currYPos + yTrans[i];
            int nextXPos = currXPos + xTrans[i];
            if (nextXPos == 11) {
                int a = 111;
            }
            if (ValidatePosition(room, nextYPos, nextXPos) == false) continue;
            if (room[nextYPos][nextXPos] == 0) {
                // 청소해야 되는 칸이 한 칸이라도 존재하면 break
                needCleaning = true;
                break;
            }
        }

        if (needCleaning == true) {
            // 빈칸이 존재하는 경우 방향 변경
            while (true) {
                // 정면에 있는 칸이 청소가 안되어 있을 때까지 방향 전환
                currDir = ChangeDirection(static_cast<Direction>(currDir));
                int nextYPos = currYPos + yTrans[currDir];
                int nextXPos = currXPos + xTrans[currDir];

                if (ValidatePosition(room, nextYPos, nextXPos) == true) {
                    if (room[nextYPos][nextXPos] == 0) {
                        currYPos = nextYPos;
                        currXPos = nextXPos;
                        break;
                    }
                }

            }
        }
        else {
            // 모든 칸이 청소되어 있으면 뒤 방향으로 한칸 후진
            int nextDir = GetBackDirection(static_cast<Direction>(currDir));
            int nextYPos = currYPos + yTrans[nextDir];
            int nextXPos = currXPos + xTrans[nextDir];
            if (ValidatePosition(room, nextYPos, nextXPos) == false) {
                // -> 후진이 불가능하면 break;
                break;
            }
            else {
                currYPos = nextYPos;
                currXPos = nextXPos;
            }
        }
    }
    cout << cleanCount << endl;
}