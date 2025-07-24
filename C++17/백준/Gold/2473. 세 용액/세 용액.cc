#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	long long minValue = 300'000'000'1;
	array<int, 3> answer{ 0, 0, 0 };
	for (int i = 0; i < N; ++i) {
		if (minValue == 0) break;
		int left = i + 1;
		int right = N - 1;

		while (left < right) {
			long long sum = static_cast<long long>(vec[i]) + vec[left] + vec[right];
			if (abs(sum) < abs(minValue)) {
				answer[0] = i;
				answer[1] = left;
				answer[2] = right;
				minValue = sum;
			}

			if (sum < 0) {
				left += 1;
			}
			else if (sum > 0) {
				right -= 1;
			}
			else {
				left = right;
			}
		}
	}

	for (int i : answer) {
		cout << vec[i] << " ";
	}
}
