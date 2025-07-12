#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int nNum, k;
	cin >> nNum >> k;
	
	vector<int> nums(nNum);
	for (int i = 0; i < nNum; ++i) {
		cin >> nums[i];
	}

	int sIndex = 0;
	int eIndex = 0;
	int maxValue = 0;
	int nOdds = 0;
	// 홀수 k개를 포함한 최대 길이 부분수열 구하기

	while (eIndex < nNum) {
		// 다음에 추가할 값이 홀수면 
		if (nums[eIndex] % 2 == 1) {
			// 포함된 홀수 개수 +1
			nOdds += 1;

			// 현재 부분 수열에 홀수가 K개 이상이면 홀수 개수가 K개 미만일 때까지 sIndex 이동
			while (nOdds > k) {
				if (nums[sIndex] % 2 == 1) {
					nOdds -= 1;
				}
				sIndex += 1;
			}
		}
		eIndex += 1;
		// 현재 문자열 개수가 최대 개수면 최댓값 갱신
		int currValue = eIndex - sIndex - nOdds;
		if (currValue > maxValue) {
			maxValue = currValue;
		}
	}
	cout << maxValue << "\n";
}