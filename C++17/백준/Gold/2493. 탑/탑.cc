#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int nTop;
	cin >> nTop;
	vector<int> topVec(nTop);
	stack<int> top;

	for (int i = 0; i < nTop; ++i) {
		cin >> topVec[i];
	}
	top.emplace(0);
	cout << "0 ";

	for (int i = 1; i < nTop; ++i) {
		while (true) {
			if (top.empty() == true) {
				cout << "0 ";
				top.emplace(i);
				break;
			}
			int value = topVec[top.top()];
			if (value < topVec[i]) {
				top.pop();
			}
			else {
				cout << top.top() + 1 << " ";
				top.emplace(i);
				break;
			}
		}
	}
}