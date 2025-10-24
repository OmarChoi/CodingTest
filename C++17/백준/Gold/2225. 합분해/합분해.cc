#include <iostream>
#include <vector>

constexpr int Mod = 100'000'000'0;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int nNum, nSum;
	std::cin >> nNum >> nSum;
	std::vector<std::vector<int>> sumCase(nSum + 1, std::vector<int>(nNum + 1));	// 몇개를 합쳐서 nNum이 되는지
	
	for (int i = 0; i <= nNum; ++i) {
		sumCase[1][i] = 1;	// 1 ~ nNum까지 1개로 해당 숫자 만드는 경우의 수
	}

	for (int k = 2; k <= nSum; ++k) {
		for (int n = 0; n <= nNum; ++n) {
			for (int m = 0; m <= n; ++m) {
				sumCase[k][n] = (sumCase[k][n] % Mod + sumCase[k - 1][n - m] % Mod) % Mod;
			}
		}
	}

	std::cout << sumCase[nSum][nNum];
}
