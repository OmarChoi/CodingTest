#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	int N, M; // 숫자 개수, 나누려는 수
	std::cin >> N >> M;

	std::vector<int> remains(M);	// 나머지 결과 값의 개수를 저장하는 벡터
	std::vector<int> nums(N + 1);
	std::vector<int64_t> prefixSum(N + 1);

	remains[0] += 1;	// 시작 지점 0은 항상 나머지가 0이기 때문
	for (int i = 1; i <= N; ++i) {
		std::cin >> nums[i];
		prefixSum[i] = prefixSum[i - 1] + nums[i];

		int remain = prefixSum[i] % M;
		remains[remain] += 1;
	}

	int64_t answer = 0;
	// 나머지가 같은 지점에서 중복하지 않게 2지점을 고르는 경우 nC2 = n(n - 1) / 2
	for (int i : remains) {
		if (i > 1) {
			answer += static_cast<int64_t>(i) * (i - 1) / 2;
		}
	}

	std::cout << answer;
}