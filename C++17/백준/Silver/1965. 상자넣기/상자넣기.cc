#include <iostream>
#include <vector>

using namespace std;

void SetNums(vector<int>& sortedVec, int num) {
	if (num > *sortedVec.rbegin()) {
		sortedVec.emplace_back(num);
	}
	else {
		int startIndex = 0;
		int endIndex = sortedVec.size();
		while (startIndex < endIndex) {
			int midIndex = (startIndex + endIndex) / 2;
			if (sortedVec[midIndex] < num) {
				startIndex = midIndex + 1;
			}
			else {
				endIndex = midIndex;
			}
		}
		sortedVec[endIndex] = num;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNum;
	cin >> nNum;

	vector<int> numbers(nNum);
	vector<int> sortedVec;

	for (int i = 0; i < nNum; ++i) {
		cin >> numbers[i];
	}

	sortedVec.emplace_back(numbers[0]);
	for (int i = 1; i < nNum; ++i) {
		SetNums(sortedVec, numbers[i]);
	}

	cout << sortedVec.size();
}