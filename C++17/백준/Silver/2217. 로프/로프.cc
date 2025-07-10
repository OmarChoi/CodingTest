#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nRope = 0;
	cin >> nRope;

	vector<int> ropes(nRope);
	for (int i = 0; i < nRope; ++i) {
		cin >> ropes[i];
	}
	sort(ropes.begin(), ropes.end());

	int maxValue = 0;
	for (int i = 0; i < nRope; ++i) {
		int val = ropes[i] * (nRope - i);
		if (maxValue < val)
			maxValue = val;
	}
	cout << maxValue;
}