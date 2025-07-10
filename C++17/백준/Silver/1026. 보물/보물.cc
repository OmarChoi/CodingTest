#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNums = 0;
	cin >> nNums;
	vector<vector<int>> nums(2, vector<int>(nNums, 0));

	for (int j = 0; j < 2; ++j) {
		for (int i = 0; i < nNums; ++i) {
			cin >> nums[j][i];
		}
	}
	sort(nums[0].begin(), nums[0].end(), greater<int>());
	sort(nums[1].begin(), nums[1].end(), less<int>());

	int answer = 0;
	for (int i = 0; i < nNums; ++i) {
		answer += nums[0][i] * nums[1][i];
	}
	cout << answer;
}