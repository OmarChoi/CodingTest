#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nInput;
	cin >> nInput;
	priority_queue<int, vector<int>, less<int>> pq;
	
	for (int i = 0; i < nInput; ++i) {
		int input;
		cin >> input;

		if (input == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.emplace(input);
		}
	}
}