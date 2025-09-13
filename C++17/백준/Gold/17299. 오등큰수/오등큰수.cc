#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int nNum;
	cin >> nNum;
	vector<int> nums(nNum);
	unordered_map<int, int> frequency;
	for (int& n : nums) {
		cin >> n;
		frequency[n] += 1;
	}

	vector<int> answer(nNum, -1);
	stack<pair<int, int>> st;	// value와 idx
	for (int i = 0; i < nNum; ++i) {
		// 스택이 비어 있으면 그냥 추가
		while (st.empty() != true) {
			const auto& [value, index] = st.top();
			int prevCount = frequency[value];
			int currCount = frequency[nums[i]];

			// 이전 값이 더 크면 stack에 추가하고 종료
			if (prevCount >= currCount) {
				break;
			}

			answer[index] = nums[i];
			st.pop();
		}
		st.emplace(nums[i], i);
	}

	for (int i : answer) {
		cout << i << " ";
	}
}
