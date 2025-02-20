#include <iostream>
#include <queue>

using namespace std;

constexpr int MAX = 100'000'000'1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNum, length;
	cin >> nNum >> length;

	priority_queue<pair<int, int>, vector<pair<int, int>>, 
		greater<pair<int, int>>> MinQueue;	// <Value, Index>

	for (int i = 1; i <= length - 1; ++i) {
		MinQueue.emplace(MAX, -i);
	}

	for (int i = 0; i < nNum; ++i) {
		int newNum = 0;
		cin >> newNum;
		MinQueue.emplace(newNum, i);

		while (!MinQueue.empty()) {
			pair<int, int> top = MinQueue.top();
			if (top.second > i - length && top.second <= i) {
				break;
			}
			MinQueue.pop();
		}

		if (!MinQueue.empty())
			cout << MinQueue.top().first << " ";
	}
}
