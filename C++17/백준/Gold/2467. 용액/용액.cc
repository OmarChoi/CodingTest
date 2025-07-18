#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> water(n);

	for (int i = 0; i < n; ++i) {
		cin >> water[i];
	}

	int left = 0;
	int right = n - 1;

	int minValue = 210'000'000'0;
	array<int, 2> answer{ 0, };
	while (left < right) {
		int sum = water[left] + water[right];
		if (abs(sum) <= minValue) {
			minValue = abs(sum);
			answer[0] = water[left];
			answer[1] = water[right];
		}

		if (sum < 0) {
			left += 1;
		}
		else if (sum > 0) {
			right -= 1;
		}
		else {
			break;
		}
	}
	cout << answer[0] << " " << answer[1];
}