#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string fullStr;
	string bombStr;
	cin >> fullStr >> bombStr;
	int bombLength = bombStr.length();
	deque<char> remainStr;
	for (int i = 0; i <= fullStr.size(); ++i) {
		if (remainStr.size() < bombLength) {
			remainStr.emplace_back(fullStr[i]);
			continue;
		}
		string tempStr(remainStr.end() - bombLength, remainStr.end());
		if (tempStr == bombStr) {
			for (int i = 0; i < bombLength; ++i) {
				remainStr.pop_back();
			}
		}
		remainStr.emplace_back(fullStr[i]);
	}
	remainStr.pop_back();

	if (remainStr.size() == 0) {
		cout << "FRULA";
	}
	else {
		for (char c : remainStr) {
			cout << c;
		}
	}

}