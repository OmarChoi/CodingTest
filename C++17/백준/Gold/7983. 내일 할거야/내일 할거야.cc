#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> homework(n);
	for (auto& [d, t] : homework) {
		cin >> d >> t;
	}

	sort(homework.begin(), homework.end(),
		[](const auto& a, const auto& b) {
			return a.second > b.second;
		});

	int blankTime = 100'000'000'1;
	for (auto& [d, t] : homework) {
		if (t > blankTime) {
			blankTime = blankTime - d;
		}
		else {
			blankTime = t - d;
		}
	}
	cout << blankTime;
}
