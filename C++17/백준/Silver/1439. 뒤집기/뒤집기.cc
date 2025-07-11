#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;
	cin >> str;

	array<int, 2> nums{ 0, };
	int prevNum = str[0] - '0';
	nums[prevNum] += 1;

	for (int i = 0; i < str.length(); ++i) {
		int currNum = str[i] - '0';
		if (prevNum != currNum) {
			nums[currNum] += 1;
			prevNum = currNum;
		}
	}

	if (nums[0] > nums[1]) {
		cout << nums[1];
	}
	else {
		cout << nums[0];
	}
}