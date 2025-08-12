#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nNum = 0;
	cin >> nNum;
	vector<int> nums(nNum);
	vector<int> answer(nNum, -1);

	for (int i = 0; i < nNum; ++i) {
		cin >> nums[i];
	}
	
	stack<pair<int, int>> st;	// <num, index>
	st.emplace(nums[0], 0);
	
	for (int i = 1; i < nNum; ++i) {
		if (nums[i] > st.top().first) {
			while (nums[i] > st.top().first) {
				answer[st.top().second] = nums[i];
				st.pop();
				if (st.empty()) {
					break;
				}
			}
		}
		st.emplace(nums[i], i);
	}

	for (int i : answer) {
		cout << i << " ";
	}
}
