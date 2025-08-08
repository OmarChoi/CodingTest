#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string str, str2;
	std::cin >> str >> str2;

	int n = str.size();
	int m = str2.size();

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

	// 뒤에서부터 채움
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (str[i] == str2[j]) {
				// J 이후 나오는 LCS (dp[i + 1][j + 1]) + 나 자신(1)
				// [i + 1][j + 1]인 이유는 str[i]가 문자열에 2개 이상 있어도 1개만 적용되야 하기 때문
				dp[i][j] = dp[i + 1][j + 1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	int i = 0, j = 0;
	int max = dp[0][0];
	std::cout << max << "\n";
	std::string lcs;
	lcs.reserve(max);

	while (i < n && j < m || lcs.length() < max) {
		if (str[i] == str2[j]) {
			// 두 문자가 같으면 LCS에 포함
			lcs.push_back(str[i]);
			++i; ++j;
		}
		else if (dp[i + 1][j] >= dp[i][j + 1]) {
			// str 쪽 문자를 건너뛰고 다음 행으로 이동
			++i;
		}
		else {
			// str2 쪽 문자를 건너뛰고 다음 열로 이동
			++j;
		}
	}
	std::cout << lcs << "\n";
}