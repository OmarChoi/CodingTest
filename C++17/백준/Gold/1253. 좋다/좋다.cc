#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<long long> numbers(n);

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end());
	int targetIndex = 2;
	int goodNumber = 0;

	for (int i = 0; i < n; ++i) {
		int startIndex = 0, endIndex = n - 1;
		while (startIndex < endIndex) {
			if (startIndex == i) startIndex++;
			else if (endIndex == i) endIndex--;
			else if (numbers[startIndex] + numbers[endIndex] > numbers[i]) {
				endIndex -= 1;
			}
			else if (numbers[startIndex] + numbers[endIndex] < numbers[i]) {
				startIndex += 1;
			}
			else {
				++goodNumber;
				break;
			}
		}
	}
	cout << goodNumber;
}