#include <iostream>

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int32_t N, P, Q;
	std::cin >> N >> P >> Q;

	if (P > Q) {
		std::swap(P, Q);
	}
	
	int64_t answer = INT64_MAX;

	for (int32_t i = 0; i < P; ++i) {
		int64_t qPay = Q * i;	// Q(비싼) 지폐로 지불한 금액
		if (qPay >= N) {
			answer = std::min(answer, qPay);
			break;
		}
		int32_t remain = N - qPay;
		int32_t pPay = (remain + P - 1) / P;
		answer = std::min(answer, pPay * P + qPay);
	}

	std::cout << answer;
}
