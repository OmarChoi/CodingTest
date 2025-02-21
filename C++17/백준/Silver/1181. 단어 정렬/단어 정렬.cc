#include <iostream>
#include <set>

using namespace std;

struct Compare
{
	bool operator()(const string str1, const string str2) const {
		if (str1.length() == str2.length()) {
			return str1 < str2;
		}
		return str1.length() < str2.length();
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nWord;
	set<string, Compare> strSet;
	cin >> nWord;

	for (int i = 0; i < nWord; ++i) {
		string str;
		cin >> str;
		strSet.emplace(str);
	}

	for (const string& str : strSet) {
		cout << str << "\n";
	}
}
