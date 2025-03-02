#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nWord, cutLine;
	cin >> nWord >> cutLine;
	map<string, int> wordMap;

	for (int i = 0; i < nWord; ++i) {
		string str;
		cin >> str;
		if (str.length() < cutLine)
			continue;
		wordMap[str] += 1;
	}

	vector<pair<string, int>> wordVec(wordMap.begin(), wordMap.end());
	sort(wordVec.begin(), wordVec.end(),
		[](const pair<string, int>& a, const pair<string, int>& b) {
			if (a.second == b.second) {
				if (a.first.length() == b.first.length())
					return a.first < b.first;
				return a.first.length() > b.first.length();
			}
			return a.second > b.second;
		});

	for (const pair<string, int>& word : wordVec) {
		cout << word.first << "\n";
	}
}