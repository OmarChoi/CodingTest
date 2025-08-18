#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> lBooks;
	vector<int> rBooks;
	lBooks.reserve(N);
	rBooks.reserve(N);

	for (int i = 0; i < N; ++i) {
		int pos;
		cin >> pos;
		if (pos < 0) {
			lBooks.emplace_back(-pos);
		}
		else if (pos > 0) {
			rBooks.emplace_back(pos);
		}
	}

	sort(lBooks.begin(), lBooks.end(), greater<int>());
	sort(rBooks.begin(), rBooks.end(), greater<int>());

	int answer = 0;
	// 멀리 있는 책들 부터 M개씩 묶어서 가져다 두기
	for (int i = 0; i < lBooks.size(); i += M) {
		answer += (lBooks[i]* 2);
	}
	for (int i = 0; i < rBooks.size(); i += M) {
		answer += (rBooks[i] * 2);
	}

	// 가장 멀리 있는 책은 편도로 가져다 두기
	answer -= (rBooks[0] > lBooks[0]) ? rBooks[0] : lBooks[0];
	cout << answer; 
}
