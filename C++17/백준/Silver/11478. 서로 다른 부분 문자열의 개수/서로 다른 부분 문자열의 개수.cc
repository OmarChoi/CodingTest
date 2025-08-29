#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	unordered_set<string> strSet;

	for (int j = 0; j < str.length(); ++j) {
		for (int i = j; i <= str.length(); ++i) {
			string tempStr = str.substr(j, i - j);
			if (tempStr != "") {
				strSet.emplace(tempStr);
			}
		}
	}

	cout << strSet.size();
}
