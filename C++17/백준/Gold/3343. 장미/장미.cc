#include <iostream>

constexpr int64_t MAX = 100'000'000'000'000'000'0;

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int64_t N, A, B, C, D;
	std::cin >> N >> A >> B >> C >> D;

	// 무조건 A가 싼 집이 될 수 있게 처리
	if (B * C > D * A) {	// B / A > D / C
		std::swap(A, C);
		std::swap(B, D);
	}
	
	int64_t answer = MAX;
	// A 이상의 꽃에 대해서는 저렴한 꽃집에서 사기 때문에 i < A에 대해서만 탐색
	for (int64_t i = 0; i < A; ++i) {
		// 비싼 집에서 i 묶음 사기
		int64_t buyC = i * C;
		if (buyC >= N) {
			// 0 ~ 최대 구매 가능한 수까지 검사 완료했기 때문에 break
			answer = std::min(answer, i * D);
			break;
		}
		int64_t remain = N - buyC;
		// 부족분은 싸게 파는 집에서 채우기
		int64_t buyA = (remain + A - 1) / A;
		answer = std::min(answer, buyA * B + i * D);
	}

	std::cout << answer;
}
