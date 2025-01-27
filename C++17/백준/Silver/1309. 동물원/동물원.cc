#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNum;
	cin >> nNum;

	vector<int> dp(nNum + 1);
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= nNum; ++i) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}
	cout << dp[nNum];

	// 0칸 : 1가지					1
	// 1칸 : 1 + 2가지				3
	// 2칸 : 1 + 4 + 2가지			7 = dp[1] * 2 + dp[0];
	// 3칸 : 1 + 6 + 8 + 2가지		17 = dp[2] * 2 + dp[1];
	// 4칸 : 41가지				41 = dp[3] * 2 + dp[2];
}