#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int solution(int n, vector<int> cores) {
    int answer = 0;
    int nCore = cores.size();
    if(n <= nCore)
        return n;
    
    int start = 0;
    int end = 250'000'001;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        long long completedWork = nCore;
        int nProcessing = 0;
        for (int i = 0; i < nCore; ++i) {
            completedWork += mid / cores[i];
            if (mid % cores[i] == 0) {
                nProcessing += 1;
                completedWork -= 1;
            }
        }
        
        if (completedWork >= n) {
            end = mid - 1;
        }
        else {
            if (completedWork + nProcessing < n) {
                start = mid + 1;
            }
            else {
                for (int i = 0; i < nCore; ++i) {
                    if (mid % cores[i] == 0) {
                        completedWork += 1;
                    }
                    if (completedWork == n) {
                        return i + 1;
                    }
                }
            }
        }
    }
    return answer;
}