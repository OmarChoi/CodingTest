#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, X;
	cin >> N >> X;
	std::vector<int> nums(N + 1);
	std::vector<int64_t> prefix(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
		prefix[i] = prefix[i - 1] + nums[i];\
	}

	int64_t max = 0;
	int count = 0;
	for (int i = X; i <= N; ++i) {
		int64_t sum = prefix[i] - prefix[i - X];
		if (sum > max) {
			max = sum;
			count = 1;
		}
		else if (sum == max) {
			count += 1;
		}
	}

	if (max == 0) {
		cout << "SAD";
	}
	else {
		cout << max << "\n" << count;
	}
}
