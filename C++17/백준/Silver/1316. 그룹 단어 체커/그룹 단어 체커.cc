#include <iostream>
#include <array>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nWord;
	cin >> nWord;
	int answer = nWord;

	for (int i = 0; i < nWord; ++i) {
		string str;
		cin >> str;

		array<int, 26> charArr{ 0, };
		char beforeWord = str[0];
		for (int j = 0; j < str.length(); ++j) {
			if (charArr[str[j]- 'a'] != 0 && beforeWord != str[j]) {
				answer -= 1;
				break;
			}
			charArr[str[j] - 'a'] += 1;
			beforeWord = str[j];
		}
	}

	cout << answer;
}