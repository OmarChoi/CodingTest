#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<int> nums(n);
	vector<int> nNums(100'001);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	int sIndex = 0;
	int eIndex = 1;
	int maxLength = 0;
	nNums[nums[sIndex]] += 1;

	while (eIndex < n) {
		nNums[nums[eIndex]] += 1;
		while (nNums[nums[eIndex]] > k) {
			nNums[nums[sIndex]] -= 1;
			sIndex += 1;
		}
		eIndex += 1;
		if (eIndex - sIndex > maxLength) {
			maxLength = eIndex - sIndex;
		}
	}
	cout << maxLength << "\n";
}