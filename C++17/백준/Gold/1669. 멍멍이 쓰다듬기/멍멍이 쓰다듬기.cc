#include <iostream>
#include <cmath>
using namespace std;

int CalDate(int monkey, int dog) {
	if (monkey >= dog) {
		return 0;
	}

	int dist = dog - monkey;
	int n = static_cast<int>(sqrt(dist));

	if (n * n == dist) {
		return 2 * n - 1;	// n번째 날에 중앙 지점 지나는 중
	}
	else if (dist <= n * n + n) {
		return 2 * n;		// n일 지나면 중앙점을 지남
	}
	else {
		return 2 * n + 1;	// n + 1일에 중앙
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	int mon, dog;
	std::cin >> mon >> dog;
	
	std::cout << CalDate(mon, dog);
}
