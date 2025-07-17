#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nHouse, nWIFI;
	cin >> nHouse >> nWIFI;
	vector<int> houses(nHouse);
	for (int i = 0; i < nHouse; ++i) {
		cin >> houses[i];
	}
	sort(houses.begin(), houses.end());

	int left = 1;
	int answer = 0;
	int right = *houses.rbegin() - *houses.begin();

	while (left <= right) {
		int mid = (left + right) / 2;
		int prevHouse = houses[0];
		int cnt = 1;
		for (int i = 1; i < nHouse; ++i) {
			if (houses[i] - prevHouse >= mid) {
				prevHouse = houses[i];
				cnt += 1;
			}
		}

		if (cnt < nWIFI) {
			right = mid - 1;
		}
		else {
			answer = mid;
			left = mid + 1;
		}
	}
	cout << answer;
}