#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<char, queue<int>> wordMap;
	vector<char> words(N);
	for (int i = 0; i < N; ++i) {
		cin >> words[i];
		wordMap[words[i]].emplace(i);
	}

	int eraseCount = 0;
	while (eraseCount < M) {
		auto it = wordMap.begin();
		int idx = it->second.front();
		it->second.pop();
		if (it->second.empty()) {
			wordMap.erase(it);
		}
		words[idx] = '#';
		eraseCount += 1;
	}

	for (char c : words) {
		if (c != '#') {
			cout << c;
		}
	}
}
