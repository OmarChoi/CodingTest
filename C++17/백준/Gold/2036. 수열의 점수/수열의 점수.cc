#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNum;
	cin >> nNum;

	priority_queue<int,vector<int>, greater<int>> minusQueue;
	priority_queue<int,vector<int>, less<int>> plusQueue;

	for (int i = 0; i < nNum; ++i) {
		int n;
		cin >> n;
		if (n <= 0) {
			minusQueue.emplace(n);
		}
		else {
			plusQueue.emplace(n);
		}
	}

	long long sum = 0;
	while (!minusQueue.empty()) {
		long long n1 = minusQueue.top();
		minusQueue.pop();
		if (minusQueue.empty()) {
			sum += n1;
			break;
		}

		long long n2 = minusQueue.top();
		minusQueue.pop();

		sum += n1 * n2;
	}

	while (!plusQueue.empty()) {
		long long n1 = plusQueue.top();
		plusQueue.pop();
		if (plusQueue.empty()) {
			sum += n1;
			break;
		}

		long long n2 = plusQueue.top();
		plusQueue.pop();

		if (n1 * n2 > n1 + n2) {
			sum += n1 * n2;
		}
		else {
			sum += (n1 + n2);
		}
	}

	cout << sum;
}