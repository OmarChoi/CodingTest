#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nPerson, nCookie;
	cin >> nPerson >> nCookie;

	int left = 1;
	int right = 0;
	vector<int> cookies(nCookie);
	for (int i = 0; i < nCookie; ++i) {
		cin >> cookies[i];
		if (cookies[i] > right) {
			right = cookies[i];
		}
	}

	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int total = 0;
		// 전체 과자를 순회하여 해당 길이의 과자를 몇 개 만들 수 있는지 확인
		for (int i = 0; i < nCookie; ++i) {
			if (cookies[i] < mid) continue;
			total += cookies[i] / mid;
		}

		if (total >= nPerson) {
			// 더 길게
			answer = mid;
			left = mid + 1;
		}
		else {
			// 더 짧게
			right = mid - 1;
		}
	}
	cout << answer;
}