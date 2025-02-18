#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int lastIndex = 1;
    
    for (int i = 0; i < stations.size(); ++i) 
    {
        int leftIndex = stations[i] - w;
        
        if (lastIndex > leftIndex)
        {
            lastIndex = stations[i] + w + 1;
            continue;
        }
        answer += ceil(static_cast<float>(leftIndex - lastIndex) / (w * 2 + 1));
        lastIndex = stations[i] + w + 1;
    }
    
    // 마지막 Station 오른쪽 기준부터 끝까지 기지국 설치
    if (lastIndex <= n)
        answer += ceil(static_cast<float>(n - lastIndex + 1) / (w * 2 + 1));
    return answer;
}