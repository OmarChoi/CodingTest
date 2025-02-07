#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b, int c = -1)
{
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

void SetDefault(int startIndex, vector<int>& dpVec, const vector<int>& sticker)
{
    dpVec[0] = sticker[startIndex]; 
    dpVec[1] = sticker[startIndex + 1];
    dpVec[2] = max(dpVec[0] + sticker[startIndex + 2], dpVec[1]);
}

int solution(vector<int> sticker)
{
    int answer =0;
    int nSticker = sticker.size();
    if(nSticker <= 3)
    {
        answer = *max_element(sticker.begin(), sticker.end());
        return answer;
    }
    
    vector<int> dpZero(nSticker);
    vector<int> dpOne(nSticker);
    
    SetDefault(0, dpZero, sticker);
    SetDefault(1, dpOne, sticker);
    
    for(int i = 3; i < nSticker - 1; ++i) 
    {
        dpZero[i] = max(dpZero[i - 3] + sticker[i], dpZero[i - 2] + sticker[i], dpZero[i - 1]);
        dpOne[i] = max(dpOne[i - 3] + sticker[i + 1], dpOne[i - 2] + sticker[i + 1], dpOne[i - 1]);
    }
    
    answer = max(dpZero[nSticker - 2], dpOne[nSticker - 2]);
    return answer;
}