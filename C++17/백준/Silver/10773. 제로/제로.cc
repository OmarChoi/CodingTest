#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nNum;
	cin >> nNum;
	int sum = 0;
	stack<int> nums;
	for (int i = 0; i < nNum; ++i) {
		int n;
		cin >> n;

		if (n == 0) {
			sum -= nums.top();
			nums.pop();
		}
		else {
			sum += n;
			nums.emplace(n);
		}
	}

	cout << sum;
}
