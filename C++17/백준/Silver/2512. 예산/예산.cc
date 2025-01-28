#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nSection;
	cin >> nSection;

	vector<int> section(nSection);
	int minValue = 1;
	int maxValue = 0;
	for (int i = 0; i < nSection; ++i) {
		cin >> section[i];
		if (section[i] > maxValue) {
			maxValue = section[i];
		}
	}
	sort(section.begin(), section.end());
	int targetCost;
	cin >> targetCost;

	while (minValue <= maxValue) {
		int midValue = (minValue + maxValue) / 2;
		int sum = 0;
		for (int i = 0; i < nSection; ++i) {
			if (section[i] >= midValue) {
				sum += (nSection - i) * midValue;
				break;
			}
			sum += section[i];
		}

		if (sum > targetCost) {
			maxValue = midValue - 1;
		}
		else if (sum < targetCost) {
			minValue = midValue + 1;
		}
		else {
			maxValue = midValue;
			break;
		}
	}
	cout << maxValue << endl;
}