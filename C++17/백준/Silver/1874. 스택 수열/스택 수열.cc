#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nNum;
	cin >> nNum;
	stack<int> numStack;
	vector<char> record;
	int inputIndex = 1;
	bool canMake = true;
	for (int i = 0; i < nNum; ++i) {
		int num;
		cin >> num;
		if (num >= inputIndex) {
			// 해당 숫자가 아직 Stack에 들어온적이 없는 경우
			// 해당 숫자까지 Input 후 해당 숫자 Pop()
			while (num >= inputIndex) {
				numStack.emplace(inputIndex++);
				record.emplace_back('+');
			}
			numStack.pop();
			record.emplace_back('-');
		}
		else {
			// 이미 해당 숫자가 Stack에 들어온 경우
			int top = numStack.top();
			numStack.pop();
			if (top > num) {
				canMake = false;
				break;
			}
			record.emplace_back('-');
		}
	}

	if (canMake) {
		for (char c : record) {
			cout << c << "\n";
		}
	}
	else {
		cout << "NO\n";
	}
	
}