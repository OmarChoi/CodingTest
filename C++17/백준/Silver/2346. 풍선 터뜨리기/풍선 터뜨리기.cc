#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

class Balloon
{
public:
	int index = 0;
	int num;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNum;
	cin >> nNum;

	deque<Balloon> nums(nNum);
	for (int i = 0; i < nNum; ++i) {
		nums[i].index = i + 1;
		cin >> nums[i].num;
	}

	int nPoppedBallooon = 0;
	while (true) {
		int dest = abs(nums.front().num);
		bool isReverse= (nums.front().num < 0) ? true : false;
		dest += isReverse;
		cout << nums.front().index << " ";
		nums.pop_front();
		if (nums.empty()) break;
		for (int i = 0; i < dest - 1; ++i) {
			if (isReverse == false) {
				nums.push_back(*nums.begin());
				nums.pop_front();
			}
			else {
				nums.push_front(*nums.rbegin());
				nums.pop_back();
			}
		}
		nPoppedBallooon += 1;
	}
}
