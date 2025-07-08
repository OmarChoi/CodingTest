#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nNum = 0;
    long long answer = 0;
    cin >> nNum;

    vector<int> nums(nNum);
    vector<bool> alreadyHave(100'001, false);
    for (int i = 0; i < nNum; ++i) {
        cin >> nums[i];
    }
    int sIndex = 0;
    int eIndex = 0;
    alreadyHave[nums[sIndex]] = true;

    while (eIndex < nNum) {
        if (alreadyHave[nums[eIndex]] == true) { 
            // 다음에 오는 숫자가 이미 포함되어 있는 경우

            while (alreadyHave[nums[eIndex]] == true && sIndex != eIndex) {
                // 이미 포함된 부분이 올 때까지 앞에 있는 숫자를 제거한다.
                alreadyHave[nums[sIndex++]] = false;
            }

            alreadyHave[nums[eIndex]] = true;
            answer += (eIndex - sIndex + 1);
            eIndex++;
        }
        else {
            // 다음에 오는 숫자가 처음 오는 숫자인 경우
            answer += (eIndex - sIndex + 1);
            alreadyHave[nums[eIndex]] = true;
            eIndex++;
        }
    }
    cout << answer;
}