#include <iostream>
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

	int nearZero = 210'000'000'0;
	while (left < right) {
		int sum = water[left] + water[right];
		if (abs(sum) <= abs(nearZero)) {
			nearZero = sum;
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
	cout << nearZero;
}