#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nTestCase = 0;
	cin >> nTestCase;

	while (nTestCase > 0) {
		nTestCase -= 1;

		int targetNum = 0;
		cin >> targetNum;

		std::vector<int> dp(targetNum + 1);
		dp[0] = 1;
		for (int j = 1; j <= 3; ++j) {
			for (int i = j; i <= targetNum; ++i) {
				dp[i] += dp[i - j]; // 마지막에 숫자 j를 추가한 경우
			}
		}
		cout << dp[targetNum] << "\n";
	}
}
