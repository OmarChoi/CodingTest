#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<long long> nums(N);
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int left = 0;
	int right = 0;
	long long min = 200'000'000'1;
	while (left <= right) {
		long long sub = nums[right] - nums[left];
		if (sub > M) {
			if (sub < min) {
				min = sub;
			}
			left += 1;
		}
		else if (sub == M) {
			min = sub;
			break;
		}
		else {
			right += 1;
			if (right == nums.size()) {
				break;
			}
		}
	}
	cout << min;
}
